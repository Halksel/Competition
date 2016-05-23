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
int N,a,b,M;
struct Edge{
  int to;
  long long cost;
};

struct NODE{
  int pos;
  long long cost;
};
bool operator < (const NODE &a,const NODE &b){
  return a.cost > b.cost;
}
vector<Edge> g[100000],rg[100000];

const ll INF = 1e15;
vector<ll> dijkstra(int s,vector<Edge> g[100000]){
  priority_queue<NODE> Q;
  Q.push({s,0});
  vector<ll> res(N,INF);
  while(Q.size()){
    NODE q= Q.top();Q.pop();
    if(res[q.pos] == INF){
      res[q.pos] = q.cost;
    }
    else{
      continue;
    }
    for(auto n : g[q.pos]){
      Q.push({n.to,q.cost+n.cost});
    }
  }
  return res;
}
bool f[101][101];
ll ans;
vector<ll> dis;
int dp[101] = {};
void solve(){
  dis = dijkstra(a,g);
  priority_queue<pii,vector<pii>,greater<pii>> que;
  rep(i,N){
    que.push(pii(dis[i],i));
  }
  dp[a] = 1;
//   que.push(pii(0,a));
  while(!que.empty()) {
    int x = que.top().second; que.pop();

    if (dis[x] > dis[b])
      break;

    for (auto e : g[x]) {
      int y = e.to;
      if (dis[y] == dis[x] + 1) {
        dp[y] += dp[x];
        if (dp[y] > 1000000007) {
          dp[y] -= 1000000007;
        }
      }
    }
  }
  cout << dp[b] << endl;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin >> N >> a >> b >> M;
  int x,y;
  rep(i,M){
   cin >> x >> y;
   --x,--y;
   g[x].push_back(Edge{y,1});
   g[y].push_back(Edge{x,1});
  }
  --a,--b;
  solve();
  return 0;
}
