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

int N,M,T;
int A[100000];
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
vector<ll> dijkstra(vector<Edge> g[100000]){
  priority_queue<NODE> Q;
  Q.push({0,0});
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
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin >> N >> M >> T;
  rep(i,N) cin >> A[i];
  int a,b,c;
  rep(i,M){
    cin >> a >> b >> c;
    --a;
    --b;
    g[a].push_back({b,c});
    rg[b].push_back({a,c});
  }
  auto to = dijkstra(g);
  auto from = dijkstra(rg);
  ll res = -1;
  rep(i,N){
    ll cost = to[i] + from[i];
    if( cost > T) continue;
    res = max(res,(T-cost)*A[i]);
  }
  cout << res << endl;
  return 0;
}
