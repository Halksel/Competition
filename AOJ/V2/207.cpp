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
int xs,ys,xg,yg,n;
ll w,h;
vector<vector<ll>> field;
vector<vector<ll>> f;
bool res = false;

void dfs(int x,int y,int c){
  if(f[x][y] != inf) return ;
  if(x == xg && y == yg){
    res = true;
    return ;
  }
  f[x][y] = 1;
  rep(i,4){
    int nx = x + dx[i],ny = y + dy[i];
    if(value(nx,ny,w,h) && field[nx][ny] == c){
      dfs(nx,ny,c);
    }
  }
  return ;
}

void solve(){
  f = vector<vector<ll>>(w+1,vector<ll>(h+1,inf));
  res = false;
  if(field[xs][ys] != inf){
    dfs(xs,ys,field[xs][ys]);
  }
  if(res){
    cout << "OK" << endl;
    return ;
  }
  cout << "NG" << endl;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  while(cin >> w >> h && w+h){
    field = vector<vector<ll>>(w+1,vector<ll>(h+1,inf));
    cin >> xs >> ys >> xg >> yg >> n;
    xs--,ys--,xg--,yg--;
    int c,d,x,y;
    rep(i,n){
      cin >> c >> d >> x >> y;
      --x,--y,--c;
      rep(j,2){
        rep(k,4){
          ll nx = k,ny = j;
          if(d){
            swap(nx,ny);
          }
          field[x+nx][y+ny] = c;
        }
      }
    }
    solve();
  }
  return 0;
}

