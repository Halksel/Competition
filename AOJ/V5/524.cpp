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
multimap<ll,ll> pos;
ll m,n;
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  while(cin >> m && m){
    pos.clear();
    ll x, y;
    vector<pll> v(m);
    rep(i,m){
      cin >> x >> y;
      v[i] = mp(x,y);
    }
    cin >> n;
    vector<pll> v2(n);
    rep(i,n){
      cin >> x >> y;
      v2[i] = mp(x,y);
      pos.insert(mp(x,y));
    }
    rep(i,n){
      int dx = v2[i].fi - v[0].fi,dy = v2[i].se - v[0].se;
      int s = 1;
      bool f = true;
      while(f){
        auto tmp = pos.equal_range(v[s].fi + dx);
        auto it = tmp.fi;
        for(; it != tmp.se; ++it){
          if(it->se == v[s].se + dy){
            ++s;
            break;
          }
        }
        if(it == tmp.se){
          f = false;
        }
      }
      if(s == m){
        cout << dx << ' ' << dy << endl;
        break;
      }
    }
  }
  return 0;
}

