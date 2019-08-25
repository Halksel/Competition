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
int N,K;
int T[5][5];
bool dfs(int n, int bit){
  if(n == N) return bit == 0;
  rep(i,K){
    if(dfs(n+1,bit^T[n][i])) return true;
  }
  return false;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin >> N >> K;
  rep(i,N){
    rep(j,K){
      cin >> T[i][j];
    }
  }
  queue<int> q;
  rep(i,K) q.push(T[0][i]);
  REP(i,1,N){
    int s = q.size();
    rep(_,s){
      int bit = q.front();q.pop();
      rep(j,K){
        q.push(bit ^= T[i][j]);
      }
    }
  }
  bool f = false;
  while(!q.empty()){
    if(q.front() == 0){
      f = true;
      break;
    }
    q.pop();
  }

  if(dfs(0,0)) cout << "Found"<<endl;
  else cout << "Nothing" << endl;
  return 0;
}
