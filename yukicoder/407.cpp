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

const ll PrimeMax = 10000001;
int is_prime[PrimeMax],S = 0;
vector<ll> p(PrimeMax/2);
void Eratosthenes(){
  for(int i = 0; i < PrimeMax; i++){
    is_prime[i] = 1;
  }
  is_prime[0] = 0;
  is_prime[1] = 0;
  for(int i = 2; i < PrimeMax ; i++){
    if(is_prime[i]){
      p[S] = i;
      ++S;
      for(int j = 0; i * (j + 2) < PrimeMax; j++){
        is_prime[i *(j + 2)] = 0;
      }
    }
  }
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  Eratosthenes();
  ll n,l;
  cin >> n >> l;
  ll ans = 0;
  rep(i,S){
    ll s = l - (n-1) * p[i] + 1 ;
    if(s > 0){
      ans += s;
    }
    if(p[i] > l || s < 0) break;
  }
  cout << ans << endl;
  return 0;
}

