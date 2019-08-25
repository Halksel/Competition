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
constexpr ll imax = ((1<<30)-1)*2+1 ;
constexpr int inf = 100000000;
constexpr double PI = acos(-1.0) ;
double eps = 1e-10 ;
const int dy[] = {-1,0,1,0,1,-1,1,-1};
const int dx[] = {0,-1,0,1,1,-1,-1,1};

ll n,m;
vvl(d,305,305,imax);
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin >> n >> m;
  ll u,v,l;
  vector<ll> p;
  rep(i,m){
    cin >> u >> v >> l;
    --u,--v;
    d[u][v] = l;
    d[v][u] = l;
    if( v == 0) swap(v,u);
    if(u == 0)
      p.pb(v);
  }
  if(p.size() < 2){
    cout << -1 << endl;
    return 0;
  }
  REP(k,1,n){
    REP(i,1,n){
      REP(j,1,n){
        d[i][j] = min(d[i][j],d[i][k] + d[k][j]);
      }
    }
  }
  ll ans = imax;
  rep(i,p.size()){
    REP(j,i+1,p.size()){
      ans = min(ans,d[0][p[i]]+d[p[i]][p[j]]+d[p[j]][0]);
    }
  }
  if(ans < inf)
    cout << ans << endl;
  else{
    cout << -1 << endl;
  }
  return 0;
}
