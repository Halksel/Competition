#include <bits/stdc++.h>
using namespace std ;

#define pb(n) push_back(n)
#define fi first
#define se second
#define all(r) begin(r),end(r)
#define vmax(ary) *max_element(all(ary))
#define vmin(ary) *min_element(all(ary))
#define debug(x) cout<<#x<<": "<<x<<endl
#define fcout(n) cout<<fixed<<setprecision((n))
#define scout(n) cout<<setw(n)
#define vary(type,name,size,init) vector< type> name(size,init)
#define vvl(v,w,h,init) vector<vector<ll>> v(w,vector<ll>(h,init))
#define mp(a,b) make_pair(a,b)

#define rep(i,n) for(int i = 0; i < (int)(n);++i)
#define REP(i,a,b) for(int i = (a);i < (int)(b);++i)
#define repi(it,array) for(auto it = array.begin(),end = array.end(); it != end;++it)
#define repa(n,array) for(auto &n :(array))

using ll = long long;
using pii = pair<int,int> ;
using pll = pair<ll,ll> ;

template<typename T>
void O(T t){
  cout << t << endl;
}

const ll mod = 1e9+7;
constexpr ll inf = ((1<<30)-1)*2+1 ;
constexpr double PI = acos(-1.0) ;
double eps = 1e-10 ;
const int dy[] = {-1,0,1,0,1,-1,1,-1};
const int dx[] = {0,-1,0,1,1,-1,-1,1};

inline bool value(int x,int y,int w,int h){
  return (x >= 0 && x < w && y >= 0 && y < h);
}
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
class dijkstra{
  public:
  const int MAX_V = 1000000;
  vector<Edge> g[100000],rg[100000];
  bool visit[100000];

  int N;
  const ll INF = 1e15;
  dijkstra(){};
  dijkstra(int n):N(n){};
  vector<ll> shorter_path(int s){
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
  void push(int p,int to,int c){
    g[p].push_back({to,c});
    rg[to].push_back({p,c});
  }
  deque<ll> Topological_sort(){
    deque<ll> res;
    rep(i,N){
      dfs(res,i);
    }
    return res;
  }
  void dfs(deque<ll> &res,int k){
    if(!visit[k]){
      visit[k] = true;
      for (auto&& nxt : g[k]) {
        dfs(res,nxt.to);
      }
      res.emplace_front(k);
    }
  }
};

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll v,e,a,b;
  cin >> v >> e;
  dijkstra d(v);
  rep(i,e){
    cin >> a >> b;
    d.push(a,b,0);
  }
  auto res = d.Topological_sort();
  for (auto&& n : res) {
    std::cout << n << std::endl;
  }
  return 0;
}
