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

inline bool value(int x,int y,int w,int h){
  return (x >= 0 && x < w && y >= 0 && y < h);
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll n,m;
  while (cin >> n >> m && n && m) {
    vector<ll> v(n+1);
    rep(i,n){
      cin >> v[i];
    }
    v[n] = 0;
    sort(all(v));
    ll ans = 0;
    vector<ll> k(n + n * n);
    rep(i,n){
      rep(j,n+1){
        if(v[i] + v[j] > m) continue ;
        k[i + j * n] = v[i] + v[j];
        ans = max(ans,k[i+j*n]);
      }
    }
    sort(all(k));
    rep(i,n){
      rep(j,n+1){
        auto it = upper_bound(all(k),m - (v[i] + v[j]));
        if(it != k.begin())
          ans = max(ans,*(it-1) + v[i]+v[j]);
      }
    }
    cout << ans << endl;
  }
  return 0;
}
