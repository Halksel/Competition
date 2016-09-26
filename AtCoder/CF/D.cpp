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

const int mod = 1000000007;
constexpr ll inf = ((1<<30)-1)*2+1 ;

const int M = 10e5;
struct Edge{
  ll from,to;
  long long cost;
};
vector<Edge> g(M);
vector<ll> u(10e5 * 2,-inf);
ll n,r,c,a,R,C;
void dfs(int f,ll c){
  u[f] = c;
  rep(i,n){
    if(g[i].from == f){
      if(u[g[i].to] == -inf)
        dfs(g[i].to,g[i].cost - u[f]);
    }
    if(g[i].to == f){
      if(u[g[i].from] == -inf)
        dfs(g[i].from,g[i].cost - u[f]);
    }
  }
  return;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin >> R >> C >> n;
  rep(i,n){
    cin >> r >> c >> a;
    g[i] = Edge{r-1,c-1 + (ll)10e5,a};
  }
  dfs(g[0].from,0);
  bool ans = true;
  ll xc = inf,yc = inf;
  rep(i,n){
    ans &= (u[g[i].from] + u[g[i].to] == g[i].cost);
    xc = min(xc,u[g[i].from]);
    yc = min(yc,u[g[i].to]);
  }
  ans &= (xc+yc >= 0);
  cout << (ans ? "Yes" : "No" )<< endl;
//   while(cin >> r >> c){
//     cout << u[r-1] + u[c-1+M]<<endl;
//   }
  return 0;
}

