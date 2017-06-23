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

const ll PrimeMax = 1000001;
int is_prime[PrimeMax];
void Eratosthenes(){
  for(int i = 0; i < PrimeMax; i++){
    is_prime[i] = 1;
  }
  is_prime[0] = 0;
  is_prime[1] = 0;
  for(int i = 2; i < PrimeMax ; i++){
    if(is_prime[i]){
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
  vector<ll> pr;
  rep(i,PrimeMax){
    if(i > 105000) break;
    if(is_prime[i] ){
      pr.push_back(i);
    }
  }
  /* std::cout << pr.size() << std::endl; */
  ll n,p;
  while(cin >> n >> p && (n+p > 0)){
    auto lw = upper_bound(all(pr),n);
    vector<ll> ans(150000);
    int k = 0;
    for(auto it = lw; it != pr.end();it++){
      for(auto it2 = it; it2 != pr.end();it2++){
        /* if(*it + *it2 > n * n && ans.size() > p) break; */
        if(k >= ans.size()) break;
        ans[k] = (*it + *it2);
        ++k;
      }
    }
    sort(ans.begin(),ans.begin()+k);
    /* rep(i,40){                        */
    /* std::cout << ans[i] << std::endl; */
    /* }                                 */
    cout << ans[p-1] << endl;
  }
  return 0;
}
