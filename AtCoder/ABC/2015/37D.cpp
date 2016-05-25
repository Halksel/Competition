#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<string>
#include<sstream>
#include<cmath>

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
const double PI = acos(-1.0) ;
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

const int mod = 1e9+7;
vector<vector<int>> v(1010,vector<int>(1010,0));
vector<vector<int>> dp(1010,vector<int>(1010,-1));
int h,w;
int dfs(int x, int y){
  ll sum = 1;
  if(dp[x][y] != -1){
    return dp[x][y] ;
  }
  rep(i,4){
    if(value(x+dx[i],y+dy[i],w,h) && v[x][y] < v[x+dx[i]][y+dy[i]]){
      sum += dfs(x+dx[i],y+dy[i]);
    }
  }
  dp[x][y] = sum % mod;
  return dp[x][y];
}

int main(){
//   cin.tie(0);
//   ios::sync_with_stdio(false);
//   cin >> h >> w;
  scanf("%d %d",&h,&w);
  rep(i,h){
    rep(j,w){
//       cin >> v[j][i];
      scanf("%d",&v[j][i]);
    }
  }
  ll ans = 0;
  rep(i,h){
    rep(j,w){
      ans += dfs(j,i) % mod;
    }
  }
//   cout << ans % mod<<endl;
  printf("%lld\n",ans%mod);
  return 0;
}