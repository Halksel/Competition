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

const int mod = 1000000007;
constexpr ll inf = ((1<<30)-1)*2+1 ;
constexpr double PI = acos(-1.0) ;
double eps = 1e-10 ;
const int dy[] = {-1,0,1,0,1,-1,1,-1};
const int dx[] = {0,-1,0,1,1,-1,-1,1};

inline bool value(int x,int y,int w,int h){
  return (x >= 0 && x < w && y >= 0 && y < h);
}

class powmod{
public:
  const ll mod = 1e9+7;
  const int MAX_N = 2000001;
  vector<ll> fact,revfact;
  powmod(){
    fact = vector<ll>(MAX_N);
    revfact = fact;
    fact[0] = 1;
    for(int i = 1; i < MAX_N; ++i){
      fact[i] = fact[i-1]*i;
      fact[i] %= mod;
    }
    revfact[MAX_N-1] = powmods(fact[MAX_N-1],mod-2);//逆元を求める
    for(int i = MAX_N-2;i >= 0;--i){
      revfact[i] = revfact[i+1] * (i+1);
      revfact[i] %= mod;//互いに素
    }
  }
  ll powmods(ll a, ll p){
    ll ans = 1;
    ll mul = a;
    for(; p > 0; p >>= 1, mul = (mul*mul) % mod){ //初期条件なし、pを2で割り続け、mulの値を更新
      if((p & 1) == 1) ans = ( ans * mul) % mod;//最下位Bitが1なら ansの値を更新
    }
    return ans;
  }
  ll getC(int a, int b){
    if(b > a) return 0;
    return (fact[a] * revfact[b] % mod) * revfact[a-b] % mod;
  }
  ll getP(int a,int b){
    if(b > a) return 0;
    return (fact[a] * revfact[a-b]) % mod;
  }
};

int dp[1001][1001];
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  powmod p;
  int N,a,b,c,d;
  cin >>N >> a >> b >> c >> d;
  dp[0][0] = 1;
  int I = 1;
  REP(k,1,N+1){// k人以下のグループの合計人数が
    I *= k;
    rep(n,N+1){//n人に成る
      int nI = 1;
      REP(x,0,(n/k)){
        nI *= I;
        if(a <= k && k <= b){
          if((c <= x && x <= d)){
            dp[k][n] += dp[k-1][n-k*x] *  p.getP(N-n+k*x,k*x) / (nI * p.fact[x]);
            dp[k][n] %= mod;
          }
        }
        else{
            dp[k][n] += dp[k-1][n] * p.getP(N-n,0) / (nI * p.fact[0]);
            dp[k][n] %= mod;
        }
      }
    }
  }

  REP(k,0,N+1){// k人以下のグループの合計人数が
    rep(n,N+1){//n人に成る
      cout << dp[k][n] << ' ';
    }
    cout << endl;
  }
  cout << dp[N][N] << endl;
  return 0;
}
