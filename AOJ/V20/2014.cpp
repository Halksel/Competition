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

ll W,h;
void solve(vector<vector<int>> &m,int x,int y,int b){
  rep(i,4){
    int nx = dx[i] + x,ny = dy[i] + y;
    if(value(nx,ny,W,h) && !(m[nx][ny] & b)){
      m[nx][ny] += b;
      solve(m,nx,ny,b);
    }
  }
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  while(cin >> W >> h,W+h){
    vector<vector<char>> w(51,vector<char>(51));
    vector<vector<int>> v(51,vector<int>(51));
    rep(j,h){
      rep(i,W){
        cin >> w[i][j];
        if(w[i][j] == '.'){
          v[i][j] = 0;
        }
        if(w[i][j] == 'W'){
          v[i][j] = 11;
        }
        if(w[i][j] == 'B'){
          v[i][j] = 7;
        }
      } }
    rep(i,W){
      rep(j,h){
        if(v[i][j] == 11)
        solve(v,i,j,1);
        if(v[i][j] == 7)
        solve(v,i,j,2);
      }
    }
    /* rep(j,h){                 */
    /*   rep(i,W){               */
    /*     cout << v[i][j] ;     */
    /*   }                       */
    /*   std::cout << std::endl; */
    /* }                         */
    ll bc = 0,wc = 0;
    rep(i,W){
      rep(j,h){
        if(v[i][j] == 1){
          wc += 1;
        }
      }
    }
    rep(i,W){
      rep(j,h){
        if(v[i][j] == 2){
          bc += 1;
        }
      }
    }
    cout << bc << ' ' << wc << endl;
  }
  return 0;
}
