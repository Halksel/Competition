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
constexpr int inf = ((1<<30)-1)*2+1 ;
constexpr double PI = acos(-1.0) ;
double eps = 1e-10 ;
const int dy[] = {-1,1,0,0,1,-1,1,-1};
const int dx[] = {0,0,-1,1,1,-1,-1,1};

inline bool value(int x,int y,int w,int h){
  return (x >= 0 && x < w && y >= 0 && y < h);
}
const string Dir = "UDLR^v<>";
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll t;
  cin >> t;
  rep(z,t){
    if(z) cout << endl;
    ll h,w,x,y,dir;
    cin >> h >> w;
    vector<vector<char>> v(h,vector<char>(w));
    rep(i,h){
      rep(j,w){
        cin >> v[i][j];
        if(v[i][j] == '^'){
          dir = 0;
          x = j,y = i;
        }
        if(v[i][j] == 'v'){
          dir = 1;
          x = j,y = i;
        }
        if(v[i][j] == '<'){
          dir = 2;
          x = j,y = i;
        }
        if(v[i][j] == '>'){
          dir = 3;
          x = j,y = i;
        }
      }
    }
    ll n;
    cin >> n;
    string s;
    cin >> s;
    rep(i,n){
      if(s[i] != 'S'){
        rep(j,4){
          if(s[i] == Dir[j]){
            dir = j;
            break;
          }
        }
        ll nx = x + dx[dir],ny = y+dy[dir];
        if(value(nx,ny,w,h)){
          if(v[ny][nx] == '.'){
            v[y][x] = '.';
            x = nx,y = ny;
            v[ny][nx] = Dir[dir+4];
          }
          else{
            v[y][x] = Dir[dir+4];
          }
        }
        else{
          v[y][x] = Dir[dir+4];
        }
      }
      else{
        ll nx = x,ny = y;
        while(1){
          nx += dx[dir],ny += dy[dir];
          if(!value(nx,ny,w,h)) break;
          if(v[ny][nx] == '*'){
            v[ny][nx] = '.';
            break;
          }
          if(v[ny][nx] == '#'){
            break;
          }
        }
      }
    }
    rep(k,h){
      rep(j,w){
        cout << v[k][j] ;
      }
      cout << endl;
    }
  }
  return 0;
}

