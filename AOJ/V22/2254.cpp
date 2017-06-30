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
 
ll data[17][17];
ll dp[(1 << 17) + 1] = {};
 
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll n;
  while(cin >> n && n){
    rep(i,n){
      rep(j,n+1){
        cin >> data[i][j];
      }
    }
    rep(j,(1 << 17) + 1){
      dp[j] = 0;
    }
    bitset<17> b,nb;
    /* dp[0][0] = 0; */
    REP(st,1,1 << (n+1)){
      b = bitset<17>(st);
      nb = bitset<17>(st);
      ll tmpcost = inf;
      rep(i,n){
        if(!b[i]) continue;
        ll mint = data[i][0];
        ll tmp = st & ~(1 << i);
        /* nb[i] = 0; */
        /* cout << b << ' ' << i << ' ' << bitset<17>(tmp) << ' ' << nb << endl; */
        rep(j,n){
          if(tmp >> j & 1) {
            mint = min(mint,data[i][j+1]);
          }
        }
        tmpcost = min(tmpcost,dp[tmp] + mint);
      }
      dp[st] = tmpcost;
    }
    /* ll ans = inf;           */
    /* rep(j,1 << n){          */
    /*   cout << dp[j] << ' '; */
    /* }                       */
    /* cout << endl; */
    std::cout << dp[(1 << n) - 1] << std::endl;
  }
  return 0;
}
