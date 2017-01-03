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
  ll n;
  cin >> n;
  ll s = 1;
  double u = sqrt(n) + 1;
  REP(i,2,u){
    if(n % i == 0){
      if(i <= n / i){
        s += i + (n / i);
        if(i == n/i) s -= i;
      }
    }
  }
  if(n == s && n != 1) cout << "Perfect" << endl;
  else if(n < s) cout << "Abundant" << endl;
  else{
    cout << "Deficient" << endl;
  }
  return 0;
}

