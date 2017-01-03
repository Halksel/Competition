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
const int dy[] = {-1,0,1,0,1,-1,1,-1};
const int dx[] = {0,-1,0,1,1,-1,-1,1};

inline bool value(int x,int y,int w,int h){
  return (x >= 0 && x < w && y >= 0 && y < h);
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll n,q;
  while(cin >> n >> q && n+q){
    string s;
    ll a,b;
    vector<pll> x(n);
    vector<pair<ll,string>> v(n);
    rep(i,n){
      cin >> s >> a >> b;
      v[i] = mp(a,s);
      x[i] = mp(b,i);
    }
    ll k;
    sort(all(x));
    rep(i,q){
      cin >> k;
      auto it = lower_bound(all(x),mp(k,-inf));
      auto dis = it->se;
      if(dis < n && v[dis].fi + k - it->fi > 0){
        cout << v[dis].se + " " <<v[dis].fi + ( k - it->fi) << endl;
      }
      else{
        cout << "Unknown" << endl;
      }
    }
  }
  return 0;
}

