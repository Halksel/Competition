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

const ll mod = 1000000007;
const int size = 100001 ;

ll powmod(ll a, ll p){
  ll ans = 1;
  ll mul = a;
  for(; p > 0; p >>= 1, mul = (mul*mul) % mod){ //初期条件なし、pを2で割り続け、mulの値を更新
    if((p & 1) == 1) ans = ( ans * mul) % mod;//最下位Bitが1なら ansの値を更新
  }
  return ans;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll n;
  cin >> n;
  vector<ll> v(n+1);
  ll a;
  ll ans = 1LL,depth = -1;
  rep(i,n){
    cin >> a;
    if(i == 0 && a != 0) ans = 0LL;
    depth = max(depth,a);
    v[a]++;
  }
  if(v[0] != 1LL){
    ans = 0LL;
  }
  REP(i,1,depth+1){
    if(v[i] == 0LL){
      ans = 0LL;
    }
    ll c = v[i] * (v[i]-1) / 2LL;
    ll k = powmod(powmod(2,v[i-1])-1,v[i]);
    ans = (ans * k) % mod;
    ans = (ans * powmod(2,c)) % mod;
  }
  cout << ans << endl;
  return 0;
}
