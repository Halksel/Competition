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

const ll mod = 1e9+7;
constexpr ll inf = ((1<<30)-1)*2+1 ;
constexpr double PI = acos(-1.0) ;
double eps = 1e-10 ;
const int dy[] = {-1,0,1,0,1,-1,1,-1};
const int dx[] = {0,-1,0,1,1,-1,-1,1};

inline bool value(int x,int y,int w,int h){
  return (x >= 0 && x < w && y >= 0 && y < h);
}

vector<string> s(50);
vector<vector<pll>> p;
vector<vector<pll>> n;
pll cond;
ll c ;
ll h,w,k;
ll M = 0;
void dfs(int x,int y,ll s){
  ll d = n[x][y].se;
  if(d == 7){
    if(M < s * n[x][y].fi){
      M = s * n[x][y].fi;
      cond = mp(x,y); 
    }
    return ;
  }
  rep(i,4){
    ll nx = x + dx[i],ny = y + dy[i];
    if(value(nx,ny,w,h) && n[nx][ny].se == 0 && n[nx][ny].fi != 0){
      ll tmp = n[nx][ny].se;
      n[nx][ny].se = d + 1;
      dfs(nx,ny,s * n[x][y].fi);
      n[nx][ny].se = tmp;
    }
  }
  return ;
}

void rev(){
  pll Q = cond;
  int cn = 0;
  queue<pll> q;
  queue<ll> U;
  q.push(Q);
  while(q.size()){
    pll p = q.front();q.pop();
    ll m = U.front();U.pop();
    if(n[p.fi][p.se].se == 8){
      Q = p;
      break;
    }
    rep(i,4){
      ll nx = p.fi + dx[i],ny = p.se + dy[i];
      if(n[p.fi][p.se].se < 8 && value(nx,ny,w,h) && m % n[nx][ny].fi == 0 && n[nx][ny].se == 0){
        n[nx][ny].se = n[p.fi][p.se].se + 1;
        U.push(m / n[nx][ny].fi);
      }
    }
  }
}

void solve(){
  rep(i,50){
    rep(j,50){
      if(n[i][j].fi > 0){
        M = 0;
        dfs(i,j,1);
        rev();
        ++c;
      }
    }
  }
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin >> h >> w >> k;
  rep(i,50){
    cin >> s[i];
  }
  rep(i,50){
    rep(j,50){
      n[i][j].fi = s[i][j] - '0';
    }
  }
  solve();
  cout << c << endl;
  rep(i,c){
    rep(j,8){
      cout << p[i][j].fi << ' ' << p[i][j].se << endl;
    }
  }
  return 0;
}
