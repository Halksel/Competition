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

using ti3 = tuple<ll,ll,ll>;
set<ti3> s;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll a,b,c,n,x,y,z;
  cin >> a >> b >> c >> n;
  ll ans = a * b * 2 + b * c * 2 + c * a * 2;
  rep(i,n){
    cin >> x >> y >> z;
    ti3 t(x,y,z);
    int cnt = 0;
    if((x == 0 || x == a - 1) || (y == 0 || y == b - 1) || (z == 0 || z == c - 1)){
      bool f[6] = {};
      if(x == 0){
        ++cnt;
      }
      else{
        if(s.find(make_tuple(x-1,y,z)) != s.end())++cnt;
      }
      if (x == a - 1){
        ++cnt;
      }
      else{
        if(s.find(make_tuple(x+1,y,z))!= s.end())++cnt;
      }
      if(y == 0){
        ++cnt;
      }
      else{
        if(s.find(make_tuple(x,y-1,z))!= s.end())++cnt;
      }
      if (y == b - 1){
        ++cnt;
      }
      else
        if(s.find(make_tuple(x,y+1,z))!= s.end())++cnt;
      if(z == 0){
        ++cnt;
      }
      else
        if(s.find(make_tuple(x,y,z-1))!= s.end())++cnt;
      if (z == c - 1){
        ++cnt;
      }
      else
        if(s.find(make_tuple(x,y,z+1))!= s.end())++cnt;
    }
    else{
      if(s.find(make_tuple(x-1,y,z))!= s.end())++cnt;
      if(s.find(make_tuple(x+1,y,z))!= s.end())++cnt;
      if(s.find(make_tuple(x,y-1,z))!= s.end())++cnt;
      if(s.find(make_tuple(x,y+1,z))!= s.end())++cnt;
      if(s.find(make_tuple(x,y,z-1))!= s.end())++cnt;
      if(s.find(make_tuple(x,y,z+1))!= s.end())++cnt;
    }
    if(cnt == 0) ans += 6;
    if(cnt == 1) ans += 4;
    if(cnt == 2) ans += 2;
    if(cnt == 3) ans += 0;
    if(cnt == 4) ans += -2;
    if(cnt == 5) ans += -4;
    if(cnt == 6) ans += -6;
    s.insert(t);
  }
  std::cout << ans << std::endl;
  return 0;
}
