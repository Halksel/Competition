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

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll n,x;
  cin >> n >> x;
  vector<ll> a(n);
  rep(i,n){
    cin >> a[i];
  }
  ll ans = 0;
  auto base = a;
  if(x < a[0]){
    a[0] -= a[0] - x;
  }
  for(int i = 0; i < n-1;++i){
    if(a[i+1] + a[i] > x){
      a[i+1] -= (a[i+1] + a[i]) - x;
    }
  }
  for(int i = 0; i < n; ++i){
    ans += base[i] - a[i];
  }
  cout << ans << endl;
  return 0;
}
