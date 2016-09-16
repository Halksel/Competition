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
constexpr double PI = acos(-1.0) ;
double eps = 1e-10 ;
const int d[] = {-1,0,1};

inline bool value(int x,int y,int w,int h){
  return (x >= 0 && x < w && y >= 0 && y < h);
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  map<pii,ll> m;
  ll h,w,n,a,b;
  cin >> h >> w >> n;
  vector<pii> v(n);
  ll d2[] = {0,-1,-2};
  rep(u,n){
    cin >> b >> a;
    --a,--b;
    v[u] = mp(a,b);
    rep(i,3){
      rep(j,3){
        ll dx = a + d2[j],dy=b+d2[i];
        if(value(dx,dy,w,h) && value(dx+2,dy+2,w,h)){
          m[mp(dx,dy)] = 0;
        }
      }
    }
  }
  rep(i,n){
    ll x = v[i].fi,y = v[i].se;
    rep(j,3){
      rep(k,3){
        ll dx = x+d2[k],dy = y+d2[j];
        if(m.count(mp(dx,dy))){
          m[mp(dx,dy)]++;
        }
      }
    }
  }
  ll ans[10]= {};
  ans[0] = (w-2)*(h-2);
  for(auto&& e:m){
    ans[e.se]++;
  }
  REP(i,1,10){
    ans[0] -= ans[i];
  }
  rep(i,10){
    cout << ans[i] << endl;
  }
  return 0;
}

