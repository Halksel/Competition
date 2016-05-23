#include<iostream>
#include<iomanip>
#include<sstream>
#include<string>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<map>
#include<vector>
#include<queue>
#include<set>
#include<numeric>
#include<complex>

using namespace std ;

#define pb(n) push_back(n)
#define fi first
#define se second
#define np string::npos
#define X real()
#define Y imag()
#define all(r) (r).begin(),(r).end()
#define gsort(st,en) sort((st),(en),greater<int>())
#define vmax(ary) *max_element(all(ary))
#define vmin(ary) *min_element(all(ary))
#define debug(x) cout<<#x<<": "<<x<<endl
#define fcout(n) cout<<fixed<<setprecision((n))
#define scout(n) cout<<setw(n)

#define rep(i,n) for(int i = 0; i < (int)(n);++i)
#define repc(i,a,b) for(int i = (a);i < (int)(b);++i)
#define repi(it,array) for(auto it = array.begin(),end = array.end(); it != end;++it)
#define repa(n,array) for(auto &n :(array))

typedef long long ll ;
typedef deque<int> di ;
typedef deque<ll> dl ;
typedef map<string,int> dict;
typedef complex<double> comd;

constexpr int imax = ((1<<30)-1)*2+1 ;
constexpr int inf = 100000000;
const double PI = acos(-1.0) ;
double eps = 1e-10 ;

double CalcDist(comd p1, comd p2){
  return sqrt(pow(p1.X - p2.X,2.0) + pow(p1.Y -p2.Y,2.0));
}

  template <typename T>
void out(deque < T > d)
{
  for(size_t i = 0; i < d.size(); i++)
  {
    debug(d[i]);
  }
}

template<typename T>
T ston(string str, T n){
  istringstream sin(str) ;
  T num ;
  sin >> num ;
  return num ;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int R,C,sy,sx,gy,gx,x,y,tx,ty;
  string str;
  queue<int> xs,ys;
  cin >>  R >> C >> sy >> sx >> gy >> gx;
  vector<vector<string>> qds(R,vector<string>(C,""));
  vector<vector<int>> qdi(R,vector<int>(C,0));
  rep(i,R){
    cin >> str;
    rep(j,C){
      qds[i][j] = str[j];
    }
  }
  xs.push(sx-1);
  ys.push(sy-1);
  while(1){
    y = ys.front(),x = xs.front();
    ty = y,tx = x;
    if(qdi[y-1][x] == 0 && qds[y-1][x] != "#"){
      ys.push(y-1);
      xs.push(x);
      qdi[y-1][x] = qdi[ty][tx] + 1;
    }
    if(qdi[y][x-1]  == 0&& qds[y][x-1] != "#"){
      ys.push(y);
      xs.push(x-1);
      qdi[y][x-1] = qdi[ty][tx] + 1;
    }
    if(qdi[y+1][x]  == 0&& qds[y+1][x] != "#"){
      ys.push(y+1);
      xs.push(x);
      qdi[y+1][x] = qdi[ty][tx] + 1;
    }
    if(qdi[y][x+1]  == 0&& qds[y][x+1] != "#"){
      ys.push(y);
      xs.push(x+1);
      qdi[y][x+1] = qdi[ty][tx] + 1;
    }
    if(y+1 == gy && x+1 == gx){
      break;
    }
    ys.pop();
    xs.pop();
  }
  cout << qdi[gy-1][gx-1] << endl;
  return 0;
}
