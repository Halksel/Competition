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

const ll mod = 1e9+7;
constexpr ll inf = ((1<<30)-1)*2+1 ;
constexpr double PI = acos(-1.0) ;
double eps = 1e-10 ;
const int dy[] = {-1,0,1,0,1,-1,1,-1};
const int dx[] = {0,-1,0,1,1,-1,-1,1};


int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll n,a,b;
  cin >> n >> a >> b;
  vector<ll> v(n),c(n);
  ll s = 0;
  rep(i,n){
    cin >> v[i];
    s += v[i];
  }
  sort(all(v));
  ll l = 0,r = mod;
  /* if(a > 2 * b) a = 2*b; */
  rep(_,100){
    ll m = (l+r)/2;
    ll k = 0;
    rep(i,n){
      if(v[i] - b * m > 0){
        k += ceil(1.0 * (v[i] - b * m)/(a-b));
      }
    }
    if(k <= m){
      r = m;
    }
    else l = m;
  }
  cout << r << endl;
  return 0;
}
