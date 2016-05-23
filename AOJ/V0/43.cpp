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

bool cheak(int n){
  if(n / 100){
    if(n/100 == n%100/10 && n%100/10 == n % 10) return true;
    if(n / 100+1 == n%100/10 && n%100/10+1 == n % 10) return true;
  }
  else{
    if( n/10 == n % 10) return true;
  }
  return false;
}

void Solve(string s, vector<int> v){
  sort(all(s));
  string s2 = s;
  set<int> ans;
  rep(k,v.size()){
    s = s2;
    s += to_string(v[k]);
    sort(all(s));
    rep(i,5){
      vector<int> v2;
      int st = 0;
      rep(j,5){
        if(i == j){
          auto s3 = s.substr(st,2);
          v2.push_back(ston(s3,1));
          st += 2;
        }
        else{
          auto s3 = s.substr(st,3);
          v2.push_back(ston(s3,1));
          st += 3;
        }
      }
      if(cheak(v2[0]) && cheak(v2[1]) && cheak(v2[2]) && cheak(v2[3]) && cheak(v2[4])) ans.insert(v[k]);
    }
  }
  for(auto it = ans.begin(); it != ans.end();++it){
    if(it != ans.begin()) cout << " " ;
    cout << *it ;
  }
  cout << endl;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  string s;
  while(cin>>s){
    vector<int> v(10,0);
    vector<int> v2;
    rep(i,13){
      v[s[i]-'0']++;
    }
    REP(i,1,10){
      if(v[i] < 4) v2.pb(i);
    }
    Solve(s,v2);
  }
  return 0;
}
