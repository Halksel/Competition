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
int numofbits5(long bits)
{
  bits = (bits & 0x55555555) + (bits >> 1 & 0x55555555);
  bits = (bits & 0x33333333) + (bits >> 2 & 0x33333333);
  bits = (bits & 0x0f0f0f0f) + (bits >> 4 & 0x0f0f0f0f);
  bits = (bits & 0x00ff00ff) + (bits >> 8 & 0x00ff00ff);
  return (bits & 0x0000ffff) + (bits >>16 & 0x0000ffff);
}
ll dp[1 << 10][1000];
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  dp[0][0] = 1;
  rep(i,1 << 10){
    rep(k,10){
      if(i & (1 << k)) continue;
      rep(l,800){
        dp[i | (1 << k)][l + (numofbits5(i)+1) * k] += dp[i][l];
      }
    }
  }
  ll n,s;
  while(cin >> n >> s){
    ll ans = 0;
    if(s > 999) cout << ans << endl;
    else{
      rep(i,1 << 10){
        if(numofbits5(i) == n) ans += dp[i][s];
      }
      cout << ans << endl;
    }
  }
  return 0;
}

