#include <bits/stdc++.h>
using namespace std ;

#define pb(n) push_back(n)
#define fi first
#define se second
#define all(r) begin(r),end(r)
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
using pii = pair<int,int> ;
using pll = pair<ll,ll> ;

template<typename T>
void O(T t){
  cout << t << endl;
}

const ll mod = 1e9+7;
constexpr ll inf = ((1<<30)-1)*2+1 ;
constexpr double PI = acos(-1.0) ;
double eps = 1e-10 ;
const int dy[] = {-1,0,1,0,1,-1,1,-1};
const int dx[] = {0,-1,0,1,1,-1,-1,1};

struct Edge{
  ll to;
  long long cost;
};
vector<Edge> g[100000];

ll dp[100001][2];
bool f[100001];

void dfs(int now,int pre){
  for (auto&& n : g[now]) {
    if(n.to != pre){
      dfs(n.to,now);
      (dp[now][0] *= (dp[n.to][0] + dp[n.to][1]) % mod) %= mod;
      (dp[now][1] *= (dp[n.to][0])) %= mod;
    }
  }
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll n,a,b;
  cin >> n;
  rep(i,n-1){
    cin >> a >> b;
    g[a-1].push_back({b-1,0});
    g[b-1].push_back({a-1,0});
  }
  rep(i,n){
    rep(j,2){
      dp[i][j] = 1;
    }
  }
  dfs(0,-1);
  /* rep(i,n){                                      */
  /*   cout << dp[i][0] << ' ' << dp[i][1] << endl; */
  /* }                                              */
  cout << (dp[0][0] + dp[0][1]) % mod << endl;
  return 0;
}
