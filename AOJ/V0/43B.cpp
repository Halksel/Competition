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
set<int> ans;
bool Solve(vector<int> v, bool f){
  bool ans = false;
  int sum = 0;
  REP(i,1,10){
    sum += v[i];
  }
  if(sum == 0){
    return true;
  }
  auto v2 = v;
  bool fail = true;
  REP(i,1,10){
    //頭作成
    if(v[i] >= 2 && !f){
      v[i]-= 2;
      ans |= Solve(v,true);
      v = v2;
      fail = false;
    }
    //刻子作成
    if(v[i] >= 3){
      v[i]-=3;
      ans |= Solve(v,f);
      v = v2;
      fail = false;
    }
    //順子作成
    if(i < 8 && v[i] && v[i+1] && v[i+2]){
      --v[i];
      --v[i+1];
      --v[i+2];
      ans |= Solve(v,f);
      v = v2;
      fail = false;
    }
  }
  return ans;
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
    ans.clear();
    auto v3 = v;
    rep(i,v2.size()){
      v = v3;
      v[v2[i]]++;
      if(Solve(v,false)) ans.insert(v2[i]);
    }
    if(ans.size() != 0){
      for(auto it = ans.begin(); it != ans.end(); ++it){
        if(it != ans.begin()) cout << " ";
        cout << *it;
      }
      cout << endl;
    }
    else cout << 0 <<endl;
  }
  return 0;
}
