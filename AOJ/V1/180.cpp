#include <bits/stdc++.h>
using namespace std ;

#define pb(n) push_back(n)
#define fi first
#define se second
#define all(r) (r).begin(),(r).end()
#define gsort(st,en) sort((st),(en),greater<int>())
#define vmax(ary) *max_element(all(ary))
#define vmin(ary) *min_element(all(ary))
#define debug(x) cout<<#x<<": "<<x<<endl
#define fcout(n) cout<<fixed<<setprecision((n))
#define scout(n) cout<<setw(n)
#define vary(type,name,size,init) vector< type> name(size,init)

#define rep(i,n) for(int i = 0; i < (int)(n);++i)
#define REP(i,a,b) for(int i = (a);i < (int)(b);++i)
#define repi(it,array) for(auto it = array.begin(),end = array.end(); it != end;++it)
#define repa(n,array) for(auto &n :(array))

using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using dict = map<string,int>;
using pii = pair<int,int> ;

const int mod = 1000000007;
constexpr int imax = ((1<<30)-1)*2+1 ;
constexpr int inf = 100000000;
constexpr double PI = acos(-1.0) ;
double eps = 1e-10 ;
const int dy[] = {-1,0,1,0};
const int dx[] = {0,-1,0,1};

inline bool value(int x,int y,int w,int h){
  return (x >= 0 && x < w && y >= 0 && y < h);
}

template<typename T>
void Unique(vector<T> &v){
  sort(all(v));
  v.erase(unique(all(v)),v.end());
}

template<typename T>
T ston(string& str, T n){
  istringstream sin(str) ;
  T num ;
  sin >> num ;
  return num ;
}

void Ans(bool f){
  if(f) cout << "YES"<<endl;
  else cout << "NO"<<endl;
}
int N,M;
const int MAX_V = 10000;
//infで初期化
vector<vector<ll>> cost;
ll mincost[MAX_V];
bool used[MAX_V];
ll V;

ll Prim(){
  for(ll i = 0; i < V; ++i){
    mincost[i] = inf;
    used[i] = false;
  }
  mincost[0] = 0;
  ll res =0;

  while(1){
    int v = -1;
    for(ll u = 0; u < V; ++u){
      if( !used[u] && (v == -1 || mincost[u] < mincost[v])) v = u;
    }

    if( v == -1){
      break;
    }
    used[v] = true;
    res += mincost[v];
    for(ll u = 0; u < V; ++u){
      mincost[u] = min(mincost[u],cost[v][u]);
    }
  }
  return res;
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
vector<Edge> g[100000],rg[100000];
ll prim(){
  ll res = 0;
  for(ll i = 0; i < V; ++i){
    mincost[i] = inf;
    used[i] = false;
  }
  priority_queue<NODE> q;
  q.push({0,0});
  while(q.size()){
    auto v = q.top();q.pop();
    if(mincost[v.pos] == inf){
      mincost[v.pos] = v.cost;
      res += v.cost;
      for(auto n : g[v.pos]){
        q.push({n.to,n.cost});
      }
    }
  }
  return res;
}
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  while(cin >> N >> M && N && M){
    int a,b,c;
    V = N;
    cost = vector<vector<ll>>(V,vector<ll>(V,inf));
    rep(i,100){
      g[i].clear();
    }
    rep(i,M){
      cin >> a >> b >> c;
      g[a].push_back({b,c});
      g[b].push_back({a,c});
//       cost[a][b] = c;
//       cost[b][a] = c;
    }
    cout << prim() << endl;
  }
  return 0;
}
