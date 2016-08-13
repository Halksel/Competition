#include <bits/stdc++.h>
using namespace std ;

#define pb(n) push_back(n)
#define fi first
#define se second
#define value(x,y,w,h) (x >= 0 && x < w && y >= 0 && y < h)
#define all(r) (r).begin(),(r).end()
#define gsort(st,en) sort((st),(en),greater<int>())
#define vmax(ary) *max_element(all(ary))
#define vmin(ary) *min_element(all(ary))
#define debug(x) cout<<#x<<": "<<x<<endl
#define fcout(n) cout<<fixed<<setprecision((n))
#define scout(n) cout<<setw(n)

#define rep(i,n) for(int i = 0; i < (int)(n);++i)
#define REP(i,a,b) for(int i = (a);i < (int)(b);++i)
#define repi(it,array) for(auto it = array.begin(),end = array.end(); it != end;++it)
#define repa(n,array) for(auto &n :(array))

typedef long long ll ;
typedef deque<int> di ;
typedef deque<ll> dl ;
typedef map<string,int> dict;
typedef complex<double> comd;
typedef pair<int,int> pii;

constexpr int imax = ((1<<30)-1)*2+1 ;
constexpr int inf = 100000000;
constexpr double PI = acos(-1.0) ;
double eps = 1e-10 ;

template <typename T>
void out(deque < T > d)
{
  for(size_t i = 0; i < d.size(); i++)
  {
    debug(d[i]);
  }
}

template<typename T>
T ston(string& str, T n){
  istringstream sin(str) ;
  T num ;
  sin >> num ;
  return num ;
}
array<int,1000001> arr;
void Eratosthenes(int N){
  for(int i = 0; i < N; i++){
    arr[i] = 1;
  }
  arr[1] = 0;
  for(int i = 2; i*i < N ; i++){
    if(arr[i]){
      for(int j = 0; i * (j + 2) < N; j++){
        arr[i *(j + 2)] = 0;
      }
    }
  }
}
const int dy[] = {1,0,-1,0};
const int dx[] = {0,-1,0,1};
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int m,n;
  while(cin >> m >> n){
    if(m + n == 0) break;
    Eratosthenes(m);
    int u = 1;
    while(u*u <= m){
      u += 2;
    }
    if(u != 1) u-=2;
    vector<vector<int>> cave(u+3,vector<int>(u+3,0));
    vector<vector<int>> dp(u+3,vector<int>(u+3,0));
    int num = 1;
    int x = u/2+1,y = u/2+1,dir = 0,k = 1;
    int cx,cy;
    cave[x][y] = num;
    while(num <= m){
      rep(i,2){
        rep(j,k){
          if(value(x+dx[dir],y+dy[dir],u+3,u+3)){
            ++num;
            if(cave[x+dx[dir]][y+dy[dir]] == 0){
              cave[x+dx[dir]][y+dy[dir]] = num ;
              x += dx[dir];
              y += dy[dir];
              if( num == n){
                cx = x;
                cy = y;
              }
            }
            else break;
          }
        }
        dir = (dir+1) % 4;
      }
      ++k;
    }
    auto tmp = arr;
    for(int i = 0; i < cx+1;++i){
      rep(j,u+2){
        if(cave[i][j] != n) tmp[cave[i][j]] = 0;
      }
    }
    REP(i,0,u+2){
      REP(j,0,u+2){
        scout(3) << cave[i][j];
      }
      cout << endl;
    }
  }
  return 0;
}
