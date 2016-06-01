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
const int dy[] = {-1,0,1,0,1,-1,1,-1};
const int dx[] = {0,-1,0,1,1,-1,-1,1};
ll grid[6][6];
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
          grid[j+1][i/2+1] |= 8 *v[j];
          grid[j][i/2+1] |= 2 * v[j];
      }
    }
    else{
      rep(j,4){
        cin >> v[j];
        v[j] -= '0';
        grid[j+1][i/2+1] |= v[j];
        grid[j+1][i/2] |= v[j]* 4;
      }
    }
  }
  ll x = 1,y = 0,c=0,dir = 2;
  ll u = 1,r = 2, d = 4,l = 8;
  cout << "R";
  while(1){
    if(x == 1 && y == 0 && c) break;
    ++c;
    if(c > 100)break;
    if(dir == 0){
      if(grid[x][y+1] & l){
        ++y;
        cout << "D";
      }
      else if(grid[x-1][y+1] & u){
        --x;
        ++y;
        dir = 1;
        cout << "L";
      }
    }
    else if(dir == 1){
      if(grid[x-1][y] & u){
        --x;
        cout << "L";
      }
      else if(grid[x-1][y-1] & r){
        --x;
        --y;
        dir = 3;
        cout << "U";
      }
    }
    else if(dir == 2){
      if(grid[x+1][y] & d){
        ++x;
        cout << "R";
      }
      else if(grid[x+1][y+1] & l){
        ++x;
        ++y;
        dir = 0;
        cout << "D";
      }
    }
    else if(dir == 3){
      if(grid[x][y-1] & r){
        --y;
        cout << "U";
      }
      else if(grid[x+1][y-1] & d){
        ++x;
        --y;
        dir =2;
        cout << "R";
      }
    }
    if(dir == 0){
      if(grid[x][y] & d){
        dir = 2;
        cout << "R";
        if(grid[x][y] & r){
          dir = 3;
          cout << "U";
        }
      }
    }
    else if(dir == 1){
      if(grid[x][y] & l){
        dir = 0;
        cout << "D";
        if(grid[x][y] & d){
          dir = 2;
          cout << "R";
        }
      }
    }
    else if(dir == 2){
      if(grid[x][y] & r){
        dir = 3;
        cout << "U";
        if(grid[x][y] & u){
          dir = 1;
          cout <<"L";
        }
      }
    }
    else if(dir == 3){
      if(grid[x][y] & u){
        dir = 1;
        cout <<"L";
        if(grid[x][y] & l){
          dir = 0;
          cout << "D";
        }
      }
    }
  }
  cout << endl;
//   cout << "u = 1,r = 2, d = 4, l = 8"<<endl;
//   rep(i,6){
//     rep(j,6){
//       scout(3) << grid[j][i];
//     }
//     cout << endl;
//   }
  return 0;
}
