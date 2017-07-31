//reference to
//http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=1724480#1

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
  ll r;
  ll n;
  while(cin >> r >> n ,r || n){
    vector<ll> a(45,0);
    ll l,u,h;
    rep(i,n){
      cin >> l >> u >> h; 
      l += 20;
      u += 20;
      REP(j,l,u){
        a[j] = max(a[j],h);
      }
    } 
    double ans = 11000;
    rep(i,40){
      int x=abs(i-20)+(i-20>=0?0:-1);
      if(x>=r)continue;
      double tmp=r-sqrt(1.0*(r*r-x*x));
      ans = min(ans,a[i]+tmp);
    }
    std::fcout(10) << ans << std::endl;
  }
  return 0;
}
