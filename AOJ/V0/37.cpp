#include <bits/stdc++.h>
using namespace std ;

#define pb(n) push_back(n)
#define fi first
#define se second
#define all(r) (r).begin(),(r).end()
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
using vi = vector<int>;
using vl = vector<ll>;
using dict = map<string,int>;
using pii = pair<int,int> ;
using pll = pair<ll,ll> ;

const int mod = 1000000007;
constexpr int inf = ((1<<30)-1)*2+1 ;
constexpr double PI = acos(-1.0) ;
double eps = 1e-10 ;

inline bool value(int x,int y,int w,int h){
  return (x >= 0 && x < w && y >= 0 && y < h);
}
const int dy[] = {0,1, 0,-1};
const int dx[] = {1,0,-1, 0};
const int DY[4][4] = {{-1,0, 1,0},{1,2, 1,0},{ 1, 0,-1,0},{-1,-2,-1,0}};
const int DX[4][4] = {{ 1,2, 1,0},{1,0,-1,0},{-1,-2,-1,0},{-1, 0, 1,0}};
const int chdir[] = {3,0,1,2};
const string Dir = "URDLURDL";
ll grid[10][10];
// u = 1,r = 2, d = 4, l = 8
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  vary(char,v,5,0);
  rep(i,9){
    if(i % 2){
      rep(j,5){
        cin >> v[j];
        v[j] -= '0';
        grid[j*2][i] = v[j];
      }
    }
    else{
      rep(j,4){
        cin >> v[j];
        v[j] -= '0';
        grid[j*2+1][i] = v[j];
      }
    }
  }
  ll x = 1,y = 0,c = 0,dir = 0;
  cout << "R";
  while(1){
    if(x == 1 && y == 0 && c) break;
    rep(i,4){
      ll nx = x + (DX[dir][i]),ny = y + (DY[dir][i]);
      if(value(nx,ny,10,10) && grid[nx][ny]){
        x = nx,y = ny;
        cout << Dir[dir+i];
        dir += chdir[i];
        dir %= 4;
        break;
      }
    }
    ++c;
    if(c > 100) break;
  }
  cout << endl;
//   rep(i,10){
//     rep(j,10){
//       scout(3) << grid[j][i];
//     }
//     cout << endl;
//   }
  return 0;
}
