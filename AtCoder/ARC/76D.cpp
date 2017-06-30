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
const int MAX_V = 1000000;
struct Edge{
  ll to;
  long long cost;
};
struct NODE{
  ll pos;
  long long cost;
};
bool operator < (const NODE &a,const NODE &b){
  return a.cost > b.cost;
}
//infで初期化
vector<vector<ll>> cost;
vector<Edge> g[100000],rg[100000];
ll mincost[MAX_V];
bool used[MAX_V];
ll V;

ll Prim(){
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
  ll x,y;
  int n;
  cin >> n;
  vector<pll> v;
  set<pll> s;
  int k ;
  rep(i,n){
    cin >> x >> y;
    s.insert(mp(x,y));
  }
  for(auto u : s){
    v.emplace_back(u);
  }
  n = v.size();
  auto vy = v;
  rep(i,n){
    v[i].se = i;
    swap(vy[i].fi,vy[i].se);
    vy[i].se = i;
  }
  sort(all(vy));
  V = n;
  rep(i,n){
    for(int j = max(0,i - 10); j < min(n,i + 10);++j){
      if(i == j) continue;
      g[v[i].se].push_back({v[j].se,abs(v[i].fi - v[j].fi)});
    }
  }
  rep(i,n){
    for(int j = max(0,i - 10); j < min(n,i + 10);++j){
      if(i == j) continue;
      g[vy[i].se].push_back({vy[j].se,abs(vy[i].fi - vy[j].fi)});
    }
  }
  /* rep(i,V){                                              */
  /*   debug(i);                                            */
  /*   rep(j,g[i].size()){                                  */
  /*     cout << g[i][j].to << ' ' << g[i][j].cost << endl; */
  /*   }                                                    */
  /* }                                                      */
  std::cout << Prim() << std::endl;
  return 0;
}
