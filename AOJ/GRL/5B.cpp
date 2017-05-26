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
  vector<Edge> g[10000],rg[10000];
  vector<ll> T[10000];

  int N;
  const ll INF = 1e15;
  dijkstra(){};
  dijkstra(int n):N(n){};
  void push(int p,int to,int c){
    g[p].push_back({to,c});
    rg[to].push_back({p,c});
    T[p].push_back(-1);
  }
  ll visit(int i,int j){
    if(T[i][j] >= 0) return T[i][j];
    T[i][j] = g[i][j].cost;
    int u = g[i][j].to;
    rep(k,g[u].size()){
      if(g[u][k].to == i) continue;
      ll r = visit(u,k);
      T[i][j] = max(T[i][j],r + g[i][j].cost);
    }
    return T[i][j];
  }
  vector<ll> height(){
    rep(i,N){
      rep(j,g[i].size()){
        if(T[i][j] < 0){
          T[i][j] = visit(i,j);
        }
      }
    }
    vector<ll> res(N);
    rep(i,N){
      rep(j,g[i].size()){
        res[i] = max(res[i],T[i][j]);
      }
    }
    return res;
  }
};

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll n;
  cin >> n;
  ll s,t,w;
  dijkstra d(n);
  rep(i,n-1){
    cin >> s >> t >> w;
    d.push(s,t,w);
    d.push(t,s,w);
  }
  auto res = d.height();
  rep(i,n){
    cout << res[i] << endl;
  }
  return 0;
}
