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

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll n,m;
  while(cin >> n >> m && n+m){
    vector<vector<char>> v(m+1,vector<char>(n+1,' '));
    using piii = pair<int,pair<int,int>>;
    priority_queue<piii> q;
    vector<vector<int>> d(m+1,vector<int>(n+1,inf));
    {
      int x = 0,y = 0;
      rep(j,m){
        rep(i,n){
          cin >> v[j][i];
          if(v[j][i] == '&'){
            x = i;
            y = j;
          }
        }
      }
      piii pos = mp(0,mp(y,x));
      d[y][x] = 0;
      q.push(pos);
    }
    int ans = inf;
    while(q.size()){
      auto Q = q.top();q.pop();
      auto p = Q.se;
      int dpt = Q.fi;
      int x = p.se,y = p.fi;
      rep(i,4){
        int nx = x + dx[i],ny = y + dy[i];
        if(value(nx,ny,n,m)){
          if(v[y][x] == v[ny][nx] && d[ny][nx] > d[y][x]){
            d[ny][nx] = d[y][x];
            q.push(mp(-dpt,mp(ny,nx)));
          }
          else if(d[ny][nx] > d[y][x] + (v[ny][nx] == '#')){
            d[ny][nx] = (v[ny][nx] == '#') + d[y][x];
            q.push(mp(-(dpt+1),mp(ny,nx)));
          }
        }
        else{
          ans = min(ans,d[y][x]);
        }
      }
    }
    cout << ans << endl;
  }
  return 0;
}

