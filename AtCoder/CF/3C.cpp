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

const int mod = 1e9+7;
constexpr ll inf = ((1<<30)-1)*2+1 ;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll n,k = 0;;
  cin >> n;
  vector<ll> t(n),a(n);
  bool f = false;
  rep(i,n){
    cin >> t[i];
    if(k > t[i]){
      f = true;
    }
    k = t[i];
  }
  k = inf;
  rep(i,n){
    cin >> a[i];
    if(k < a[i]){
      f = true;
    }
    k = a[i];
  }
  ll ans = 1,T = *max_element(all(t)),A = *max_element(all(a));
  if(f || T != A){
    cout << 0 << endl;
    return 0;
  }
  vector<ll> h(n,0);
  rep(i,n){
    if(i == 0 || t[i - 1] < t[i]){
      h[i] = t[i];
    }
  }
  rep(i,n){
    if(i == 0 || a[n - i] < a[n-1-i]){
      h[n-i-1] = max(h[n-i-1],a[n - i - 1]);
    }
  }
  rep(i,n){
    if(h[i] < t[i] && h[i] < a[i]){
      ans = ans * min(t[i],a[i]) % mod;
    }
    if(h[i] == t[i] && h[i] > a[i]){
      ans = 0;
    }
    else if(h[i] == a[i] && h[i] > t[i]){
      ans = 0;
    }
  }
  cout << ans % mod << endl;
  return 0;
}

