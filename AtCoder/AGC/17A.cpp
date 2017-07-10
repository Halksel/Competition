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

const ll mod = 1e9+7;
constexpr ll inf = ((1<<30)-1)*2+1 ;
constexpr double PI = acos(-1.0) ;
double eps = 1e-10 ;
const int dy[] = {-1,0,1,0,1,-1,1,-1};
const int dx[] = {0,-1,0,1,1,-1,-1,1};

ll dp[51][4];

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll n,p;
  cin >> n >> p;
  vector<ll> v(n);
  bool f = false;
  rep(i,n){
    cin >> v[i];
    f |= v[i] % 2;
  }
  ll ans = 1;
  REP(i,0,n){
    ans *= 2;
  }
  if(f){
    if(n != 1)
      cout << ans / 2<< endl;
    else
      cout << (v[0] % 2 == p) << endl;
  }
  else{
    if(p)
      cout << 0 << endl;
    else
      std::cout << ans << std::endl;
  }
  return 0;
}
