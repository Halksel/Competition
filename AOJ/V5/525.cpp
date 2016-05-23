#include <bits/stdc++.h>
using namespace std ;

#define pb(n) push_back(n)
#define fi first
#define se second
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
T ston(string& str, T n){
  istringstream sin(str) ;
  T num ;
  sin >> num ;
  return num ;
}
int ma = 0;
int R,C;
vector<int> dp(1 << 11),memo;
void dfs(vector<vector<int>> v, int n,int k){
  if(memo[n] == 1) return ;
  memo[n] = 1;
  int res = 0;
  rep(i,C){
    int a = 0;
    rep(j,R){
      if(v[j][i] == 1){
        ++a;
      }
    }
    if(a >= C/2){
      res += a;
    }
    else{
      res += C- a;
    }
  }
  ma = max(ma,res);
  rep(i,R){
    v[k][i] = v[k][i] == 1 ? -1:0;
  }
  rep(j,C){
    if(k != j){
      dfs(v,n |(1 << j),j);
    }
  }
}
// 数値を２進数文字列に変換
std::string to_binString(unsigned int val)
{
  if( !val )
    return std::string("0");
  std::string str;
  while( val != 0 ) {
    if( (val & 1) == 0 )  // val は偶数か？
      str.insert(str.begin(), '0');  //  偶数の場合
    else
      str.insert(str.begin(), '1');  //  奇数の場合
    val >>= 1;
  }
  return str;
}
void dfs2(int n, int k){
  if(memo[n] == 1) return ;
  memo[n] = 1;
  cout << to_binString(n)<<endl;
  rep(i,R){
    if(k != i){
      dfs2(n |(1 << i),i);
    }
  }
}
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  while(cin >> R >> C){
    if(R + C == 0) break;
    vector< vector<int>> senbei(15,vector<int>(10010,0));
    int res = 0;
    rep(i,R){
      rep(j,C){
        cin >> senbei[i][j];
        if(senbei[i][j] == 1){
          ++res;
        }
      }
    }
    ma = res;
    memo = dp;
    dfs(senbei,0,0);
    cout << ma << endl;
  }
  return 0;
}
