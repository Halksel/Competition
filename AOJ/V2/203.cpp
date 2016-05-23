#include <bits/stdc++.h>
using namespace std ;

#define pb(n) push_back(n)
#define fi first
#define se second
#define all(r) (r).begin(),(r).end()
#define gsort(st,en) sort((st),(en),greater<int>())
#define vmax(ary) *max_element(all(ary))
#define vmin(ary) *min_element(all(ary))
#define debug(x) cout<<#x<<": "<<x<<endl
#define fcout(n) cout<<fixed<<setprecision((n))
#define scout(n) cout<<setw(n)
#define vary(type,name,size,init) vector< type> name(size,init)

#define rep(i,n) for(int i = 0; i < (int)(n);++i)
#define REP(i,a,b) for(int i = (a);i < (int)(b);++i)
#define repi(it,array) for(auto it = array.begin(),end = array.end(); it != end;++it)
#define repa(n,array) for(auto &n :(array))

using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using dict = map<string,int>;
using pii = pair<int,int> ;

const int mod = 1000000007;
constexpr int imax = ((1<<30)-1)*2+1 ;
constexpr int inf = 100000000;
constexpr double PI = acos(-1.0) ;
double eps = 1e-10 ;
const int dy[] = {1,1,1,1};
const int dx[] = {-1,0,1,0};

inline bool value(int x,int y,int w,int h){
  return (x >= 0 && x < w && y >= 0 && y < h);
}

template<typename T>
void Unique(vector<T> &v){
  sort(all(v));
  v.erase(unique(all(v)),v.end());
}

template<typename T>
T ston(string& str, T n){
  istringstream sin(str) ;
  T num ;
  sin >> num ;
  return num ;
}

void Ans(bool f){
  if(f) cout << "YES"<<endl;
  else cout << "NO"<<endl;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int x,y;
  while(cin >> x >> y&&x&&y){
    vector<vector<ll>> grid(x+1,vector<ll>(y+1,0));
    vector<vector<ll>> dp(x+3,vector<ll>(y+3,0));
    rep(i,y){
      rep(j,x){
        cin >> grid[j][i];
      }
    }
    rep(i,x){
      dp[i][0] = grid[i][0] == 0;
    }
    rep(i,y){
      rep(j,x){
        if(grid[j][i] == 0){
          rep(k,3){
            int nx = j+dx[k],ny = i+dy[k];
            if(value(j+dx[k],i+dy[k],x,y)){
              if(grid[nx][ny] == 0){
                dp[nx][ny] += dp[j][i];
              }
              else if(grid[nx][ny] == 2 && k == 1){
                dp[nx][ny] += dp[j][i];
              }
            }
          }
        }
        else if(grid[j][i] == 2 && grid[j][i+2] != 1){
          dp[j][i+2] += dp[j][i];
        }
      }
    }
    ll ans = 0;
    rep(i,x){
      ans += dp[i][y]+dp[i][y-1];
    }
    cout << ans << endl;
  }
  return 0;
}
