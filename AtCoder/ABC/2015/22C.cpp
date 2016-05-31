#include <bits/stdc++.h>
using namespace std ;

#define pb(n) push_back(n)
#define fi first
#define se second
#define all(r) (r).begin(),(r).end()
#define vmax(ary) *max_element(all(ary))
#define vmin(ary) *min_element(all(ary))
#define debug(x) cout<<#x<<": "<<x<<endl
#define fcout(n) cout<<fixed<<setprecision((n))
#define scout(n) cout<<setw(n)
#define vary(type,name,size,init) vector< type> name(size,init)
#define vvl(v,w,h,init) vector<vector<ll>> v(w,vector<ll>(h,init))
#define mp(a,b) make_pair(a,b)

#define rep(i,n) for(int i = 0; i < (int)(n);++i)
#define REP(i,a,b) for(int i = (a);i < (int)(b);++i)
#define repi(it,array) for(auto it = array.begin(),end = array.end(); it != end;++it)
#define repa(n,array) for(auto &n :(array))

using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using dict = map<string,int>;
using pii = pair<int,int> ;
using pll = pair<ll,ll> ;

const int mod = 1000000007;
constexpr int imax = ((1<<30)-1)*2+1 ;
constexpr int inf = 100000000;
constexpr double PI = acos(-1.0) ;
double eps = 1e-10 ;
const int dy[] = {-1,0,1,0,1,-1,1,-1};
const int dx[] = {0,-1,0,1,1,-1,-1,1};

ll n,m;
vvl(d,300,300,inf);
ll dp[1 << 16][300];
ll rec(ll s,ll v){
  if(dp[s][v] >= 0){
    return dp[s][v];
  }
  if(s == (1 << n) -1 && v == 0) return dp[s][v] = 0;
  ll res = inf;
  rep(i,n){
    if(!(s >> i & 1) && d[v][i] != inf){
      res = min(res,rec(s | (1 << i),i) + d[v][i]);
    }
  }
  return dp[s][v] = res;
}
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin >> n >> m;
  ll u,v,l;
  rep(i,m){
    cin >> u >> v >> l;
    --u,--v;
    d[u][v] = l;
    d[v][u] = l;
  }
  memset(dp,-1,sizeof(dp));
  ll ans = rec(0,0);
  if(ans == inf) ans = -1;
  cout << ans <<endl;
  return 0;
}
