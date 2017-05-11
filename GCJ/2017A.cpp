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
  ll t;
  cin >> t;
  rep(x,t){
    string s;
    int k,res=0,sum = 0;
    bool ans = true;
    cin >> s >> k;
    int n = s.size();
    int dir[1001],f[1001] = {};
    rep(i,n){
      if(s[i] == '-'){
        dir[i] = 1;
      }
      else{
        dir[i] = 0;
      }
    }
    for(int i = 0; i + k <= n;++i){
      if((dir[i] + sum) % 2 != 0){
        ++res;
        f[i] = 1;
      }
      sum += f[i];
      if(i - k + 1 >= 0){
        sum -= f[i-k+1];
      }
    }
    for(int i = n - k + 1; i < n;++i){
      if((dir[i] + sum) % 2 != 0){
        ans = false;
        break;
      }
      else{
        sum -= f[i-k+1];
      }
    }
    std::cout << "Case #" << x+1 << ": ";
    if(ans)
       cout << res << std::endl;
    else
      std::cout << "IMPOSSIBLE" << std::endl;
  }
  return 0;
}
