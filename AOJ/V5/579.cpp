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

int dp[2][200];
vector<int> day[220];
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int N,D;
  cin >> N >> D;
  vector<int> d(N),a(D),b(D),c(D);
  rep(i,N){
    cin >> d[i];
  }
  rep(i,D){
    cin >> a[i] >> b[i] >> c[i];
  }
  rep(j,N){
    int u = 0;
    rep(i,D){
      if(a[i] <= d[j] && d[j] <= b[i]){
        ++u;
        day[j].pb(c[i]);
//         debug(day[j].size());
      }
    }
    sort(all(day[j]));
  }
//   rep(j,N){
//     rep(i,day[j].size()){
//       cout << day[j][i] << " " ;
//     }
//     cout << endl;
//   }
  int ans = 0;
  REP(i,0,N-1){
    int lm = 0,hm = 0;
    // 最低値から最低値へ
    int a,b,c,d;
    lm = abs(day[i][0]-day[i+1][0]);
    a = dp[0][i] + lm;
    //最低値から最大値へ
    lm = abs(day[i][0]-day[i+1][day[i+1].size()-1]);
    b = dp[0][i]+ lm;
    //最大値から最低値へ
    hm = abs(day[i][day[i].size()-1]-day[i+1][0]);
    c = dp[1][i] + hm;
    //最大値から最低値へ
    hm = abs(day[i][day[i].size()-1]-day[i+1][day[i+1].size()-1]) ;
    d = dp[1][i] +hm;
    dp[0][i+1] = max(a,c);
    dp[1][i+1] = max(b,d);
  }
  cout << max(dp[0][N-1],dp[1][N-1]) << endl;
  return 0;
}
