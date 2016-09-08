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
    vector<vector<ll>> a(n+10,vector<ll>(2,0));
    rep(j,2){
      rep(i,n){
        cin >> a[i][j];
      }
    }
    vector<vector<ll>> dp(n+10,vector<ll>(2,inf));
    dp[0][0] = dp[0][1] = 0;
    rep(i,2){
      if(a[0][i] == 1){
        ll l = 0;
        while(a[l][i] == 1 && l < n){
          ++l;
        }
        --l;
        dp[l][i] = 0;
      }
    }
    rep(x,n){
      rep(j,n){
        rep(i,2){
          if(a[j][i] == 0 || a[j][i] == 1){
            rep(k,3){
              if(a[j+k][!i] == 0){
                dp[j+k][!i] = min(dp[j+k][!i],dp[j][i]+1);
              }
              else if(a[j+k][!i] == 1){
                ll l = j+k;
                while(a[l][!i] == 1 && l < n){
                  ++l;
                }
                --l;
                dp[l][!i] = min(dp[l][!i],dp[j][i]+1);
              }
              else{
                ll l = j+k;
                while(a[l][!i] == 2){
                  --l;
                }
                ++l;
                dp[l][!i] = min(dp[l][!i],dp[j][i]+1);
              }
            }
          }
        }
      }
    }
    if(dp[n][0] == dp[n][1] && dp[n][1] == inf){
      cout << "NA" << endl;
    }
    else{
      ll ans = inf;
      REP(i,n-1,n+5){
        ans = min(ans,min(dp[i][0],dp[i][1]));
      }
      cout << ans << endl;
    }
  }
  return 0;
}

