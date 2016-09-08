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

const int mod = 10000;
constexpr int inf = ((1<<30)-1)*2+1 ;
constexpr double PI = acos(-1.0) ;
double eps = 1e-10 ;
const int dy[] = {-1,0,1,0,1,-1,1,-1};
const int dx[] = {0,-1,0,1,1,-1,-1,1};

inline bool value(int x,int y,int w,int h){
  return (x >= 0 && x < w && y >= 0 && y < h);
}

string a,b;
int m;
int dp[501][2][10][2];

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin >> a >> b >> m;
  dp[0][0][0][0] = 1;
  rep(i,b.size()){
    rep(j,2){
      int lim = j ? 9 : b[i] - '0';
      rep(l,2){
        rep(k,10){
          if(!l){
            for(int d = k+1; d < lim+1; ++d){
              (dp[i+1][j || d < lim][d][!l] += dp[i][j][k][l]) %= mod;
            }
          }
          else{
            rep(d,min(lim,k)+1){
              (dp[i+1][j || d < lim][d][!l] += dp[i][j][k][l]) %= mod;
            }
          }
        }
      }
    }
  }
  ll ans = 0;
  rep(i,2) rep(j,10) rep(k,2)
    (ans += dp[b.size()][i][j][k]) %= mod;
  cout << ans << endl;
  return 0;
}

