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
constexpr int inf = ((1<<30)-1)*2+1 ;
constexpr double PI = acos(-1.0) ;
double eps = 1e-10 ;
const int dy[] = {-1,0,1,0,1,-1,1,-1};
const int dx[] = {0,-1,0,1,1,-1,-1,1};

inline bool value(int x,int y,int w,int h){
  return (x >= 0 && x < w && y >= 0 && y < h);
}

struct Comp{
  bool operator()(pll a,pll b) const
  {
    if(a.fi == b.fi) return a.se <= b.se;
    return a.fi < b.fi;
  }
};

vector<pll> v(3001);
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll n;
  while(cin >> n && n){
    int x,y;
    multimap<int,int> m;
    rep(i,n){
      cin >> x >> y;
      v[i] = mp(x,y);
      m.insert(v[i]);
    }
    sort(begin(v),begin(v)+n);
    ll res = 0;
    rep(i,n){
      REP(j,i+1,n){
        int dx = v[j].fi - v[i].fi,dy = v[j].se - v[i].se;
        int CX = v[i].fi - dy,CY = v[i].se + dx;
        int DX = v[j].fi - dy,DY = v[j].se + dx;
        if(value(CX,CY,5001,5001) && value(DX,DY,5001,5001)){
          bool f1 = false,f2 = false;
          auto tmp = m.equal_range(CX);
          for(auto it = tmp.fi; it != tmp.se; ++it){
            if(it->se == CY){
              f1 = true;
              break;
            }
          }
          tmp = m.equal_range(DX);
          for(auto it = tmp.fi; it != tmp.se; ++it){
            if(it->se == DY){
              f2 = true;
              break;
            }
          }
          if(f1 && f2){
            ll dis = (dx * dx + dy * dy);
            res = max(res,dis) ;
          }
        }
      }
    }
    cout << res << endl;
  }
  return 0;
}

