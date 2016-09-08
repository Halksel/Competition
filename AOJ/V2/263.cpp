#include <bits/stdc++.h>
using namespace std ;

#define pb(n) push_back(n)
#define fi first
#define se second
#define all(r) (r).begin(),(r).end()
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
const int C = 16;
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll n,c;
  while(cin >> n >> c && n && c){
    vector<bitset<C>> a(n),b(c);
    ll ans = 0;
    string s,s2;
    rep(i,n){
      s = "";
      rep(i,C){
        cin >> s2;
        s+= s2;
      }
      a[i] = bitset<C>(s);
    }
    rep(i,c){
      s = "";
      rep(i,C){
        cin >> s2;
        s+= s2;
      }
      b[i] = bitset<C>(s);
    }
    vector<vector<ll>> dp(1 << C,vector<ll>(n+1,0));
    vector<vector<bool>> f(1 << C,vector<bool>(n+1,false));
    f[0][0] = true;
    rep(i,n){
      rep(bfr,1 << C){
        //光る
        if(f[bfr][i]){
          bitset<C> k(bfr);
          k |= a[i];
          rep(j,c){
            //叩く
            auto cnt = k & b[j];
            auto nxt = k & ~b[j];
            dp[(nxt).to_ulong()][i+1] = max(dp[(nxt).to_ulong()][i+1],dp[bfr][i] + (ll)cnt.count());
            f[(nxt).to_ulong()][i+1] = true;
          }
          if(i == 0) break;
        }
      }
    }
    ans = 0;
    rep(i,1 << C){
      ans = max(ans,dp[i][n]);
    }
    cout << ans << endl;
  }
  return 0;
}
