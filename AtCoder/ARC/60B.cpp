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

using ll = long long;

ll f(ll b,ll n){
  if(n < b) return n;
  return f(b, n/b) + n % b;
}

ll n,s;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin >> n;
  cin >>  s;
  if(s == n){
    cout << n + 1 << endl; return 0;
  }
  else if(s == 1){
    cout << n << endl; return 0;
  }
  else{
    for(ll i = 2; i * i <= n;++i){
      if(f(i,n) == s){
        cout << i << endl;
        return 0;
      }
    }
    for(ll i = 1; i * i < n;++i){
      if(s == f((n-s)/i+1,n)){
        cout << i << endl;
        return 0;
      }
    }
  }
  cout << -1 << endl;
  return 0;
}

