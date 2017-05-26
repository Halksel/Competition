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
  vector<Edge> g[100000],rg[100000];
  bool visit[100000];

  int N;
  const ll INF = 1e15;
  dijkstra(){};
  dijkstra(int n):N(n){};
  void push(int p,int to,int c){
    g[p].push_back({to,c});
    rg[to].push_back({p,c});
  }
  pll farthest_point(int n,int p){
    pll r = {0,n};
    for (auto&& k : g[n]) {
      if(k.to != p){
        pll res = farthest_point(k.to,n);
        res.fi += k.cost;
        if(r.fi < res.fi) r = res;
      }
    }
    return r;
  }
  ll diameter(){
    pll a = farthest_point(0,-1);
    pll b = farthest_point(a.se,-1);
    return b.fi;
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
  cout << d.diameter() << endl;
  return 0;
}
