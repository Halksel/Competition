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

const ll mod = 1e9+7;
constexpr ll inf = ((1<<30)-1)*2+1 ;
constexpr double PI = acos(-1.0) ;
double eps = 1e-10 ;
const int dy[] = {-1,0,1,0,1,-1,1,-1};
const int dx[] = {0,-1,0,1,1,-1,-1,1};
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
bool operator == (const Edge &a,const Edge &b){
  return a.to == b.to;
}
int c = 0;

class dijkstra{
  public:
    const int MAX_V = 1000000;
    vector<Edge> g[100000],rg[100000];
    vector<bool> visit;

    int N;
    const ll INF = 1e15;
    set<int> f,s;
    dijkstra(){};
    dijkstra(int n):N(n){
      visit.resize(n+1,false);
    };
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
      g[to].push_back({p,c});
      rg[to].push_back({p,c});
    }
    int dfs(int st){
      if(visit[st]) return 0;
      visit[st] = true;
      int res = 1;
      for(auto u : g[st]){
        res += dfs(u.to);
      }
      return res;
    }
};


int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll n;
  cin >> n;
  dijkstra d(n);
  rep(i,n-1){
    ll a,b;
    cin >> a >> b;
    --a,--b;
    d.push(a,b,1);
  }
  auto dis = d.shorter_path(0);
  int p = n - 1;
  while(1){
    bool f = true;
    for(auto k : d.g[p]){
      if(dis[k.to] == dis[p] -1){
        if(dis[k.to] == dis[n-1] / 2){
          f = false;
          for(auto it = d.g[k.to].begin(); it != d.g[k.to].end();){
            if(*it == Edge{p,1LL}){
              it = d.g[k.to].erase(it);
            }
            else
              ++it;
          }
          for(auto it = d.g[p].begin(); it != d.g[p].end();){
            if(*it == Edge{k.to,1LL}){
              it = d.g[p].erase(it);
            }
            else
              ++it;
          }
          break;
        }
        p = k.to;
      }
    }
    if(!f) break;
  }
  ll b = d.dfs(n-1);

  ll a = d.dfs(0);
  cout << a << ' ' << b << endl;
  cout << (a > b ? "Fennec": "Snuke") << endl;
  return 0;
}
