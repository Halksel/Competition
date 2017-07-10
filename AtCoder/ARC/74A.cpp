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
  ll w,h;
  cin >> h >> w;
  if(h % 3 == 0 || w % 3 == 0){
    cout << 0 << endl;
    return 0;
  }
  ll ans = inf;
  REP(i,1,w){
    ll A = (w-i) * h,B = i * (h/2),C = i * (h - h/2),D = h * (i/2),E = h * (i - i/2);
    ans = min(ans,min(max(A,max(B,C))-min(A,min(B,C)),max(A,max(D,E)) - min(A,min(D,E)) ));
  }
  swap(h,w);
  REP(i,1,w){
    ll A = (w-i) * h,B = i * (h/2),C = i * (h - h/2),D = h * (i/2),E = h * (i - i/2);
    ans = min(ans,min(max(A,max(B,C))-min(A,min(B,C)),max(A,max(D,E)) - min(A,min(D,E)) ));
  }
  cout << ans << endl;
  return 0;
}