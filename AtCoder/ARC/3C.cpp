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
inline bool value(int x,int y,int w,int h){
  return (x >= 0 && x < w && y >= 0 && y < h);
}


const ll mod = 1e9+7;
constexpr ll inf = ((1<<30)-1)*2+1 ;
constexpr double PI = acos(-1.0) ;
double eps = 1e-10 ;
const int dy[] = {-1,0,1,0,1,-1,1,-1};
const int dx[] = {0,-1,0,1,1,-1,-1,1};

double dp[500][500];

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll n,m;
  cin >> n >> m;
  vector<vector<char>> v(n,vector<char>(m));
  vector<double> a(n * m+1);
  a[0] = 0.99;
  rep(i,n*m){
    a[i+1] = a[i] * 0.99;
  }
  ll sx,sy,gx,gy;
  rep(i,n){
    rep(j,m){
      cin >> v[i][j];
      dp[i][j] = 0;
      if(v[i][j] == 's')
        sx = i,sy = j;
      if(v[i][j] == 'g')
        gx = i,gy = j;
    }
  }
  v[gx][gy] ='0';
  v[sx][sy] = '0';
  queue<pll> q;
  queue<pair<double,int>> p;
  q.push(mp(sx,sy));
  p.push(mp(inf,0));
  double ans = -inf;
  ll c = n * m + n + m;
  while(q.size()){
    pll nq = q.front();q.pop();
    ll x = nq.fi,y = nq.se;
    auto np = p.front();p.pop();
    int t = np.se;
    double l = np.fi;
    rep(i,4){
      ll nx = x+dx[i],ny = y+dy[i];
      if(value(nx,ny,n,m) && dp[nx][ny] < l && v[nx][ny] != '#'){
        q.push(mp(nx,ny));
        p.push(mp(min(l,(v[nx][ny] - '0') * a[t]),t+1));
        dp[nx][ny] = l;
        if(nx == gx && ny == gy){
          ans = max(ans,l);
        }
      }
    }
  }
  if(ans == -inf){
    cout << -1 << endl;
  }
  else
    fcout(10) << ans << endl;
  return 0;
}
