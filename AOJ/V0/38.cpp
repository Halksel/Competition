#include <bits/stdc++.h>
using namespace std ;

#define pb(n) push_back(n)
#define fi first
#define se second
#define all(r) (r).begin(),(r).end()
#define gsort(st,en) sort((st),(en),greater<int>())
#define vmax(ary) *max_element(all(ary))
#define vmin(ary) *min_element(all(ary))
#define debug(x) cout<<#x<<": "<<x<<endl
#define fcout(n) cout<<fixed<<setprecision((n))
#define scout(n) cout<<setw(n)
#define vary(type,name,size,init) vector< type> name(size,init)

#define rep(i,n) for(int i = 0; i < (int)(n);++i)
#define REP(i,a,b) for(int i = (a);i < (int)(b);++i)
#define repi(it,array) for(auto it = array.begin(),end = array.end(); it != end;++it)
#define repa(n,array) for(auto &n :(array))

using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using dict = map<string,int>;
using pii = pair<int,int> ;

constexpr int imax = ((1<<30)-1)*2+1 ;
constexpr int inf = 100000000;
constexpr double PI = acos(-1.0) ;
double eps = 1e-10 ;
const int dy[] = {-1,0,1,0};
const int dx[] = {0,-1,0,1};

inline bool value(int x,int y,int w,int h){
  return (x >= 0 && x < w && y >= 0 && y < h);
}

template<typename T>
void Unique(vector<T> &v){
  sort(all(v));
  v.erase(unique(all(v)),v.end());
}

template<typename T>
T ston(string& str, T n){
  istringstream sin(str) ;
  T num ;
  sin >> num ;
  return num ;
}

void Ans(bool f){
  if(f) cout << "YES"<<endl;
  else cout << "NO"<<endl;
}

string Solve(vector<int> v){
  set<int> s;
  int st = 0;
  REP(i,1,14){
    if(v[i] > 0){
      s.insert(i);
    }
    if(v[i] == v[i-1] && v[i] != 0){
      ++st;
    }
  }
  int m = *max_element(all(v));
  if(m == 4){
    return "four card";
  }
  else if(m == 3 && s.size() == 2){
    return "full house";
  }
  else if(m == 1){
    if((v[1] != 0 && v[1] == v[10] && v[11] == v[12] && v[13] == v[1] && v[1] == v[11])||(st == 4)){
      return "straight";
    }
    else
      return "null";
  }
  else if(m == 3 && s.size() == 3){
    return "three card";
  }
  else if(m == 2 && s.size() == 3){
    return "two pair";
  }
  else if(m == 2){
    return "one pair";
  }
  return "null";
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  char c;
  int a,b,d,e,f;
  while(cin >> a >> c >> b >> c >> d >> c >> e >> c >> f){
    vary(int,v,14,0);
    v[a]++;
    v[b]++;
    v[d]++;
    v[e]++;
    v[f]++;
    cout << Solve(v) << endl;
  }
  return 0;
}
