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
using ll = long long;
using pii = pair<int,int> ;
using pll = pair<ll,ll> ;


int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll t;
  cin >> t;
  rep(x,t){
    ll res = 0,n;
    cin >> n;
    ll dp[22][10][10] ={};
    rep(i,19){
      rep(j,10){
        REP(k,0,10){
          REP(l,max(j,k),10){
            dp[i+1][k][l] = max(dp[i+1][k][l],dp[i][j][k] * 10 + l);
            if(dp[i+1][k][l] <= n){
              res = max(dp[i+1][k][l],res);
            }
          }
        }
      }
    }
    std::cout << "Case #" << x+1 << ": "; cout << res << std::endl;
  }
  return 0;
}

