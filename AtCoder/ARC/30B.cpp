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

int n,x;
int h[101];
int v[101];
int mem[101];
struct Edge{
  int to;
  long long cost;
};
vector<Edge> g[101];

int ans = 0;

bool dp(int x){
  if(v[x]) return 0 ;
  v[x] = 1;
  bool f = false;
  for(auto &&n : g[x]){
    f |= dp(n.to);
  }
  if(h[x]) f = true;
  if(f) ans += 2;
  return f;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin >> n >> x;
  rep(i,n){
    cin >> h[i+1];
  }
  int s,t;
  rep(i,n-1){
    cin >> s >> t;
    g[s].push_back({t,1LL});
    g[t].push_back({s,1LL});
  }
  dp(x);
  if(ans > 0)
    cout << ans - 2 << endl;
  else
    cout << 0 << endl;
  return 0;
}
