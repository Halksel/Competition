#include <bits/stdc++.h>
using namespace std ;

#define pb(n) push_back(n)
#define fi first
#define se second
#define all(r) (r).begin(),(r).end()
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
using vi = vector<int>;
using vl = vector<ll>;
using dict = map<string,int>;
using pii = pair<int,int> ;
using pll = pair<ll,ll> ;

const int mod = 1000000007;
constexpr int inf = ((1<<30)-1)*2+1 ;
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
vector<Edge> g[100000],rg[100000];
const int MAX_V = 105;
//infで初期化
vector<vector<ll>> cost;
ll mincost[MAX_V];
bool used[MAX_V];
ll V,path;
ll prim(){
  ll res = 0;
  path = 0;
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
      if(v.cost)
        path += v.cost/100 - 1;
      for(auto n : g[v.pos]){
        q.push({n.to,n.cost});
      }
    }
  }
  rep(i,V){
    g[i].clear();
  }
  return res;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll n,m;
  while(cin >> n && n){
    V = n;
    cin >> m;
    int a,b,c;
    char d;
    rep(i,m){
      cin >> a >> d >> b >> d >> c;
      g[a].push_back({b,c});
      g[b].push_back({a,c});
    }
    ll ans = prim();
    cout << ans/100-n+1 << endl;
  }
  return 0;
}
