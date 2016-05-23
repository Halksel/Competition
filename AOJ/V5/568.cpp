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
#define vary(Type,Arg,W,H,Init) (vector<vector<(Type)>> Arg ((W),(vector<(Type)>(H,Init))))

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

void run(){
  //  ifstream cin("in");
  //  ofstream cout( "out" );
  int N,K;cin >>N >> K;

  map<int,int> dmap;
  rep(i,K){
    int a,b;cin >> a >> b;
    dmap[a]=b;
  }

  vector<vector<vector<int> >> dp(N+1,vector<vector<int> >(4,vector<int>(4)));
  for(int c=1;c<=3;c++){
    if((dmap.count(1) > 0 && dmap[1]==c) || dmap.count(1)==0)
      dp[1][c][0]=1;
  }
  for(int i=2;i<=N;i++){
    for(int c=1;c<=3;c++){
      if( (dmap.count(i) > 0 && dmap[i]==c) || dmap.count(i)==0){
        for(int pc1=1;pc1<=3;pc1++)for(int pc2=0;pc2<=3;pc2++){
          if(!(c==pc1 && pc1 ==pc2)){
            dp[i][c][pc1]+=dp[i-1][pc1][pc2];
            dp[i][c][pc1]%=10000;
            debug(dp[i][c][pc1]);
          }
        }
      }
    }
  }

  ll res=0;
  for(int c=1;c<=3;c++)for(int p=1;p<=3;p++){
    res+=dp[N][c][p];
    res%=10000;
  }

  cout << res<<endl;
}

int N,K,a,b;
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
//   run();

  cin >> N >> K;
  map<int,int> p;
  rep(i,K){
    cin >> a >> b;
    p[a] = b ;
  }
  vector<vector<vector<int>>> dp(N+1,vector<vector<int>>(4,vector<int>(4,0)));
  for(int i = 1; i <= 3;++i){
    if((p.count(1) > 0 && p[1] == i) || p.count(1) == 0){
      dp[1][i][0] = 1;
    }
  }
  for(int i = 2; i <= N; i++){
    for(int c = 1; c <= 3; ++c){
      if((p.count(i) > 0 &&p[i] == c)|| p.count(i) == 0){//cは当日何を食べるか
        for(int pc1 = 1; pc1 <= 3; ++pc1){//前日
          for(int pc2 = 0; pc2<= 3; ++pc2){//前々日
            if(!(c == pc1 && pc1 == pc2)){//三日連続でない
              dp[i][c][pc1] += dp[i-1][pc1][pc2];
              dp[i][c][pc1] %= 10000;
            }
          }
        }
      }
    }
  }

  ll ans = 0;
  for(int i = 1; i <= 3; ++i){
    for(int j = 1; j <= 3; ++j){
      ans += dp[N][i][j];
      ans %= 10000;
    }
  }
  cout << ans << endl;
  return 0;
}
