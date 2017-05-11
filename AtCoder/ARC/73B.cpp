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
  ll n,W;
  cin >> n >> W;
  vector<vector<ll>> v(4);
  vector<vector<ll>> sum(4);
  ll a,b,w,v2;
  cin >> a >> b;
  v[0].push_back(b);
  rep(i,n-1){
    cin >> w >> v2;
    v[w-a].push_back(v2);
  }
  rep(i,4){
    sort(all(v[i]));
    reverse(all(v[i]));
    sum[i].resize(v[i].size()+1);
    rep(j,sum[i].size()-1){
      sum[i][j+1] += sum[i][j] + v[i][j];
    }
  }
  ll ans = 0;
  rep(i,v[0].size()+1){
    rep(j,v[1].size()+1){
      rep(k,v[2].size()+1){
        rep(l,v[3].size()+1){
          if(i * a + j * (a+1) + k * (a+2) + l * (a+3) <= W){
            ans = max(ans,sum[0][i] + sum[1][j] + sum[2][k] + sum[3][l]) ;
          }
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}
