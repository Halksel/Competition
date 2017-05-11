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

inline bool value(int x,int y,int w,int h){
  return (x >= 0 && x < w && y >= 0 && y < h);
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll n;
  cin >> n;
  vector<ll> r(n),b(n);
  map<ll,ll> mr,mb;
  ll RM = 0,Rm = inf,BM = 0,Bm = inf;
  rep(i,n){
    cin >> r[i] >> b[i];
    RM = max(RM,max(r[i],b[i]));
    Bm = min(Bm,min(r[i],b[i]));
    mr[r[i]] = i;
    mb[b[i]] = i;
  }
  /* ll x = mr[RM],y = mb[Bm];    */
  /* if(r[mr[RM]] != RM){         */
  /*   swap(r[mr[RM]],b[mr[RM]]); */
  /* }                            */
  /* if(b[mb[Bm]] != Bm){         */
  /*   swap(r[mb[Bm]],b[mb[Bm]]); */
  /* }                            */
  rep(i,n){
    if(b[i] > r[i]){
      swap(b[i],r[i]);
    }
  }
  sort(all(r));
  sort(all(b));
  /* rep(i,n){                   */
  /*   std::cout << r[i] << ' '; */
  /* }                           */
  /* cout << endl;               */
  /* rep(i,n){                   */
  /*   std::cout << b[i] << ' '; */
  /* }                           */
  /* cout << endl;               */
  RM = r.back(),Rm = r[0],BM = b.back(),Bm= b[0];
  if( Rm < BM){
    cout << min((r.back()-r[0]) * (b.back() - b[0]), (r.back()-b[0]) * (b.back()-r[0])) << endl;
  }
  else{
    cout << (r.back()-r[0]) * (b.back() - b[0]) << endl;
  }
  return 0;
}
