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

const ll mod = 1e9+7;
constexpr ll inf = ((1<<30)-1)*2+1 ;
constexpr double PI = acos(-1.0) ;
double eps = 1e-10 ;
const int dy[] = {-1,0,1,0,1,-1,1,-1};
const int dx[] = {0,-1,0,1,1,-1,-1,1};

inline bool value(int x,int y,int w,int h){
  return (x >= 0 && x < w && y >= 0 && y < h);
}

ll n;
ll s = 0;
ll ans = inf;

ll f(ll s){
  return (s > 0 ? -1 : 1) * (abs(s) + 1);  
}
inline int sgn(ll a,ll b = 0) { return a < b ? -1 : a > b ? 1 : 0; }

void solve(vector<ll> v){
  vector<ll> a(n),b(n);
  a[0] = 1;
  b[0] = -1;
  rep(i,n-1){
    a[i+1] = -1 * a[i]; 
    b[i+1] = -1 * b[i];
  }
  ll ca = 0,cb = 0;
  auto v2 = v;
  auto v3 = v;
  rep(i,n){
    if(sgn(s + v[i]) != sgn(a[i])){
      v3[i] = a[i] - s;
      ca += abs(v3[i] - v[i]);
    }
    s += v3[i];
  }
  v = v2;
  v3 = v2;
  s = 0;
  rep(i,n){
    if(sgn(s + v[i]) != sgn(b[i])){
      v3[i] = b[i] - s;
      cb += abs(v3[i] - v[i]);
    }
    s += v3[i];
  }
  ans = min(ca,cb);
}
bool judge(vector<ll> v){
  ll s = 0;
  REP(i,0,n-1){
    s += v[i];
    if(s == 0) return false;
    if(sgn(s) == sgn(s + v[i+1])) return false;
  }
  return true;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin >> n;
  vector<ll> v(n);
  rep(i,n){
    cin >> v[i];
  }
  if(!judge(v)){
    solve(v);
    std::cout << ans << std::endl;
  }
  else
    std::cout << 0 << std::endl;
  return 0;
}
