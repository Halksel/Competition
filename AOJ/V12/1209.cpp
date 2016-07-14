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
using vi = vector<int>;
using vl = vector<ll>;
using dict = map<string,int>;
using pii = pair<int,int> ;
using pll = pair<ll,ll> ;

const int mod = 1000000007;
constexpr int inf = ((1<<30)-1)*2+1 ;
constexpr double PI = acos(-1.0) ;
double eps = 1e-10 ;

vector<ll> dp(1000,0);

vary(int,v,0,0);
int solve(int n){
  rep(i,1000){
    dp[i] = 0;
  }
  dp[1] = 1;
  REP(i,1,18){
    REP(j,1,400){
      if(j - v[i]>= 0)
        dp[j] += dp[j-v[i]];
    }
  }
  return dp[n+1];
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  v.clear();
  REP(i,0,18){
    v.pb(i*i);
  }
  int n;
  while(cin >> n&&n){
    cout << solve(n) << endl;
  }
  return 0;
}
