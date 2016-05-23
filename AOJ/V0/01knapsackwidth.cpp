#include <bits/stdc++.h>
using namespace std ;

#define pb(n) push_back(n)
#define fi first
#define se second
#define np string::npos
#define X real()
#define Y imag()
#define value(x,y,w,h) (x >= 0 && x < w && y >= 0 && y < h)
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
double eps = 1e-10 ;
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

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  vector<vector<int>> table;
  int n,v,w,vn,wn,tmp;
  cin >> n >> v >> w;
  table.resize(v+1);
  rep(i,v+1){
    table[i].resize(n+1);
  }
  table[0][0] = 0;
  for(int i =1; i < v+1;++i){
    table[i][0] = 100 ;
  }
  rep(i,n){
    cin >> vn >> wn;
    rep(j,v){
      if(vn <= j ){
        tmp = min(table[j][i],table[j-vn][i]+wn);
        table[j][i+1] = tmp;
      }
      else{
        table[j][i+1] = table[j][i];
      }
    }
  }
  int ans;
  rep(i,100){
    if(table[i][n] == 0 || table[i][n] == 100){

    }
    else if(table[i][n] <= w ){
      ans = i;
    }
    else{
      break;
    }
  }
  cout << ans << endl;
  return 0;

}
