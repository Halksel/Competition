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
const int dy[] = {-1,0,1,0,0,-1,1,-1};
const int dx[] = {0,-1,0,1,0,-1,-1,1};

inline bool value(int x,int y,int w,int h){
  return (x >= 0 && x < w && y >= 0 && y < h);
}

const int W = 10,H = 10;
int tile[W][H];
int opt[W][H];
int flip[W][H];

int get(int x,int y){
  int c = tile[x][y];
  rep(i,5){
    int nx = x+dx[i],ny = y+dy[i];
    if(value(nx,ny,W,H)){
      c += flip[nx][ny];
    }
  }
  return c % 2;
}

int calc(){
  REP(i,1,W){
    rep(j,H){
      if(get(i-1,j) != 0){
        flip[i][j] = 1;
      }
    }
  }
  rep(j,H){
    if(get(W-1,j) != 0)
      return -1;
  }
  int res = 0;
  rep(i,W){
    rep(j,H){
      res += flip[i][j];
    }
  }
  return res;
}

void solve(){
  int res = -1;
  rep(i,1 << H){
    memset(flip, 0, sizeof(flip));
    rep(j,W){
      flip[0][H-j-1] = i >> j & 1;
    }
    if(calc() != -1){
      break;
    }
  }
  rep(i,W){
    rep(j,H){
      if(j) cout << ' ';
      cout << flip[i][j] ;
    }
    cout << endl;
  }
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  rep(x,n){
    rep(i,W){
      rep(j,H){
        cin >> tile[i][j];
      }
    }
    solve();
  }
  return 0;
}

