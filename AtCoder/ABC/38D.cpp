#include <bits/stdc++.h>
using namespace std ;

#define pb(n) push_back(n)
#define fi first
#define se second
#define all(r) (r).begin(),(r).end()
#define gsort(st,en) sort((st),(en),greater<int>())
#define vmax(ary) *max_element(all(ary))
#define vmin(ary) *min_element(all(ary))
#define debug(x) cout<<#x<<": "<<x<<endl
#define fcout(n) cout<<fixed<<setprecision((n))
#define scout(n) cout<<setw(n)
#define vary(type,name,size,init) vector< type> name(size,init)

#define rep(i,n) for(int i = 0; i < (int)(n);++i)
#define REP(i,a,b) for(int i = (a);i < (int)(b);++i)
#define repi(it,array) for(auto it = array.begin(),end = array.end(); it != end;++it)
#define repa(n,array) for(auto &n :(array))

using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using dict = map<string,int>;
using pii = pair<int,int> ;

constexpr int imax = ((1<<30)-1)*2+1 ;
constexpr int inf = 100000000;
constexpr double PI = acos(-1.0) ;
double eps = 1e-10 ;
const int dy[] = {-1,0,1,0};
const int dx[] = {0,-1,0,1};


int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll h,r,mh = 0,n;
  cin >> n;
  vector<pair<ll,ll>> v(n);
  rep(i,n){
    cin >> h >> r;
    v[i] = make_pair(h,-r);
  }
  sort(all(v));
  ll ans = 0,c = 0;
  vector<ll> dp(n+1,inf);
  dp[0] = -inf;
  rep(i,n){
    ll lb = 0,ub = n+1;
    ll cand = -v[i].se;
    while(ub-lb>1){
      ll mid = (lb + ub)/2;
      if(dp[mid] < cand){
        lb = mid;
      }
      else{
        ub = mid;
      }
    }
    dp[lb+1] = cand;
  }
  for(ll i = n; i >= 0; --i){
    if(dp[i] < inf){
      cout << i << endl;
      break;
    }
  }
  return 0;
}
