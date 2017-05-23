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
class Prim{
  public:
  const int MAX_V = 1000000;
  vector<Edge> g[100000],rg[100000];
  //infで初期化
  ll mincost[100000];
  bool used[100000];
  ll V;
  Prim(){};
  Prim(ll n):V(n){};
  ll MST(int r = 0){
    ll res = 0;
    for(ll i = 0; i < V; ++i){
      mincost[i] = inf;
      used[i] = false;
    }
    priority_queue<NODE> q;
    q.push({r,0});
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
  void push(int p,int to,int c){
    g[p].push_back({to,c});
    rg[to].push_back({p,c});
  }
};

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll v,e,a,b,c,r;
  cin >> v >> e >> r;
  Prim p(v);
  rep(i,e){
    cin >> a >> b >> c;
    p.push(a,b,c);
  }
  cout << p.MST(r) << endl;
  return 0;
}
