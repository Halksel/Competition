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
typedef pair<int,int> pii;

constexpr int imax = ((1<<30)-1)*2+1 ;
constexpr int inf = 100000000;
constexpr double PI = acos(-1.0) ;
constexpr double eps = 1e-10 ;
const int dy[] = {-1,0,1,0};
const int dx[] = {0,-1,0,1};

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
T ston(string& str, T& n){
  istringstream sin(str) ;
  T num ;
  sin >> num ;
  return num ;
}

template<int X, int Y>
struct Add
{
     enum { result = X + Y };
};

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int R,C,sy,sx,gy,gx;
  string str;
  queue<pii> qpii;
  cin >>  R >> C >> sy >> sx >> gy >> gx;
  deque<deque<string>> qds(R,deque<string>(C,""));
  deque<deque<int>> qdi(R,deque<int>(C,0));
  rep(i,R){
    cin >> str;
    rep(j,C){
      qds[i][j] = str[j];
    }
  }
  qpii.push(pii(sy-1,sx-1));
  while(!qpii.empty()){
    pii p = qpii.front(); qpii.pop();
    rep(i,4){
//      int y = Add<p.fi,dy[i]> ;

      int y = p.fi + dy[i];
      int x = p.se + dx[i];
      if(qds[y][x] != "#" && qdi[y][x] ==0 ){
        qpii.push(pii(y,x));
        qdi[y][x] = qdi[p.fi][p.se]+1;
      }
    }
  }
  cout << qdi[gy-1][gx-1] << endl;
  return 0;
}
