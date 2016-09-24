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

const int mod = 1000000007;
constexpr ll inf = ((1<<30)-1)*2+1 ;
constexpr double PI = acos(-1.0) ;
double eps = 1e-10 ;
const int dy[] = {-1,0,1,0,1,-1,1,-1};
const int dx[] = {0,-1,0,1,1,-1,-1,1};

inline bool value(int x,int y,int w,int h){
  return (x >= 0 && x < w && y >= 0 && y < h);
}
vector<ll> a(300001,inf),sum(300001,0);
vector<ll> b(300001,inf),  c(300001,inf);

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll n;
  cin >> n;
  rep(i,n){
    cin >> a[i];
  }
  sort(a.begin(),a.begin()+n);
  REP(i,0,n){
    sum[i+1] += a[i] + sum[i];
  }
  ll m;
  cin >> m;
  rep(i,m){
    cin >> b[i];
  }
  rep(i,m){
    cin >> c[i];
  }
  rep(j,m){
    int p = 0;
    auto it = upper_bound(a.begin(),a.begin()+n,b[j]);
    auto dis = distance(it,a.begin());
    p += sum[dis];
    if( p >= c[j]){
      cout << "Yes" << endl;
    }
    else{
      cout << "No" << endl;
    }
  }
  return 0;
}

