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
  ll n;
  while(cin >> n && n){
    ll w,h,x,y;
    cin >> w >> h;
    vector<vector<ll>> v(h,vector<ll>(w,0));
    vector<vector<ll>> dp(h+1,vector<ll>(w+1,0));
    rep(i,n){
      cin >> x >> y;
      --x,--y;
      v[y][x] = 1;
    }
    rep(j,h){
      REP(i,0,w){
        dp[j+1][i+1] += dp[j+1][i] + v[j][i];
      }
    }
    rep(i,w+1){
      REP(j,0,h){
        dp[j+1][i] += dp[j][i];
      }
    }
    ll s,t;
    cin >> s >> t;
    ll ans = 0;
//     rep(j,h+1){
//       rep(i,w+1){
//         cout << dp[j][i] << ' ';
//       }
//       cout << endl;
//     }
    --s,--t;
    REP(j,1,h+1){
      REP(i,1,w+1){
        if(value(i+s,j+t,w+1,h+1)){
          ans = max(ans,dp[j+t][i+s]+dp[j-1][i-1]-dp[j+t][i-1]-dp[j-1][i+s]);
        }
      }
    }
    cout << ans << endl;
  }
  return 0;
}

