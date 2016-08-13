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
using pii = pair<int,int> ;
using pll = pair<ll,ll> ;

const int mod = 1000000007;
constexpr int inf = ((1<<30)-1)*2+1 ;
constexpr double PI = acos(-1.0) ;
double eps = 1e-10 ;
const int dy[] = {-1,0,1,0,1,-1,1,-1};
const int dx[] = {0,-1,0,1,1,-1,-1,1};

inline bool value(int x,int y,int w,int h){
  return (x >= 0 && x < w && y >= 0 && y < h);
}


ll powmod(ll a, ll p){
  ll ans = 1;
  ll mul = a;
  for(; p > 0; p >>= 1, mul = (mul*mul) % mod){ //初期条件なし、pを2で割り続け、mulの値を更新
    if((p & 1) == 1) ans = ( ans * mul) % mod;//pが1なら ansの値を更新
  }
  return ans;
}

const int MAX_N = 2000001;

ll fact[MAX_N];
ll revfact[MAX_N];

void setFact(int N){
  fact[0] = 1;
  for(int i = 1; i < N; ++i){
    fact[i] = fact[i-1]*i;
    fact[i] %= mod;
  }
  revfact[N-1] = powmod(fact[N-1],mod-2);//逆元を求める
  for(int i = N-2;i >= 0;--i){
    revfact[i] = revfact[i+1] * (i+1);
    revfact[i] %= mod;//互いに素
  }
}

ll getC(int a, int b){
  return (fact[a] * revfact[b] % mod) * revfact[a-b] % mod;
}
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll h,w,a,b;
  cin >> h >> w >> a >> b;
  setFact(MAX_N);
  vector<ll> q(w-b);
  ll k = w-b;
  rep(i,k){
    q[i] = getC(b+h-a+i-1,b+i);
  }
  ll ans = 0;
  rep(i,k){
    ans += (q[i] % mod * (getC(k+a-2-i,k-1-i) % mod))% mod;
    ans %= mod;
  }
  cout << ans << endl;
  return 0;
}

