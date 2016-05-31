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
#define vvl(v,w,h,init) vector<vector<ll>> v(w,vector<ll>(h,init));

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
ll n,e;
vvl(d,20,20,inf);
ll dp[1 << 15][20];

ll rec(ll s, ll v){
  //一度見ているなら即座にその値を返す
  if(dp[s][v] >= 0){
    return dp[s][v];
  }
  //すべての頂点を訪れたなら
  if(s == (1 << n) - 1 && v == 0){
    return dp[s][v] = 0;
  }
  ll res = inf;
  rep(u,n){
    //まだ移動していない頂点なら、そこへ
    if( !(s >> u & 1) && d[v][u] != inf){
      res = min(res,rec(s | 1 << u, u) + d[v][u]);
    }
  }
  return dp[s][v] = res;
}

void solve(){
  memset(dp,-1,sizeof(dp));
  ll ans = rec(0,0);
  if(ans == inf) ans = -1;
  cout << ans<<endl;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin >> n >> e;
  ll s,t,dis;
  rep(i,e){
    cin >> s >> t >> dis;
    d[s][t] = dis;
  }
  solve();
  return 0;
}
