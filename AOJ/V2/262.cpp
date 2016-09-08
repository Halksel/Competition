#include <bits/stdc++.h>
using namespace std ;

#define pb(n) push_back(n)
#define fi first
#define se second
#define all(r) (r).begin(),(r).end()
#define gsort(st,en) sort((st),(en),greater<int>())
#define vmax(ary) *max_element(all(ary))
#define vmin(ary) *min_element(all(ary))
#define debug(x) cout<<#x<<": "<<x<<endl
#define fcout(n) cout<<fixed<<setprecision((n))
#define scout(n) cout<<setw(n)
#define vary(type,name,size,init) vector< type> name(size,init)

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
constexpr int imax = ((1<<30)-1)*2+1 ;
constexpr int inf = 100000000;
constexpr double PI = acos(-1.0) ;
double eps = 1e-10 ;
const int dy[] = {-1,0,1,0};
const int dx[] = {0,-1,0,1};

inline bool value(int x,int y,int w,int h){
  return (x >= 0 && x < w && y >= 0 && y < h);
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll m,n;
  while(cin >> m &&m){
    cin >> n;
    vary(ll,v,n,0);
    rep(i,n){
      cin >> v[i];
    }
    bool ans = true;
    rep(x,n){
      vary(bool,dp,2 * n+1,false);
      dp[0] = true;
      int s = x+1;
      if(s < 0) s = 0;
      if(s > n) dp[s] = true;
      if(s > 0 && s <= n){
        s += v[s-1];
      }
      if(s < 0) s = 0;
      dp[s] = true;
      if(s)
        dp[0] = false;
      rep(y,255){
        rep(i,n+1){
          rep(j,m){
            int s = j+1 + i;
            if(s < 0) s = 0;
            if(s > n) dp[s] = dp[s] | dp[i];
            if(s > 0 && s <= n){
              s += v[s-1];
            }
            if(s < 0) s = 0;
            dp[s] = dp[i] | dp[s];
          }
        }
      }
      bool f = false;
      REP(i,n+1,2 * n+1){
        f |= dp[i];
      }
      ans = ans & f;
    }
    if(ans){
      cout << "OK" << endl;
    }
    else{
      cout << "NG" << endl;
    }
  }
  return 0;
}
