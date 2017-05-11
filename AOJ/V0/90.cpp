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

inline bool value(int x,int y,int w,int h){
  return (x >= 0 && x < w && y >= 0 && y < h);
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll n,s;
  vector<vector<vector<ll>>> dp(102,vector<vector<ll>>(11,vector<ll>(1001,0)));
  dp[0][0][0] = 1;
  dp[0][1][0] = 1;
  REP(i,1,101){
    REP(j,0,10){
      REP(k,0,1001){
        if(i)
          dp[i][j][k] = dp[i-1][j][k];
        if(i && j && k-i >= 0)
          dp[i][j][k] += dp[i-1][j-1][k-i];
      }
    }
  }
  while(cin >> n >> s && n+s){
    cout << dp[100][n][s]  << endl;
  }
  return 0;
}
