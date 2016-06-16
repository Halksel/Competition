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

inline bool value(int x,int y,int w,int h){
  return (x >= 0 && x < w && y >= 0 && y < h);
}
ll V,E;
const int MAX_V = 1000000;
vector<int> g[MAX_V];
vector<int> rg[MAX_V];
vector<ll> vs;
array<bool,MAX_V> use;
array<int,MAX_V> cmp;

void add_edge(int from,int to){
  g[from].push_back(to);
  rg[to].push_back(from);
}

void dfs(int v){
  use[v] = true;
  rep(i,g[v].size()){
    if(!use[g[v][i]]){
      dfs(g[v][i]);
    }
  }
  vs.push_back(v);
}

void rdfs(int v,int k){
  use[v] = true;
  cmp[v] = k;
  rep(i,rg[v].size()){
    if(!use[rg[v][i]]) rdfs(rg[v][i],k);
  }
}

int scc(){
  fill(all(use),false);
  vs.clear();
  rep(i,V){
    if(!use[i]) dfs(i);
  }
  fill(all(use),false);
  int k = 0;
  for(int i = vs.size()-1; i >= 0; --i){
    if(!use[vs[i]]) rdfs(vs[i],k++);
  }
  return k;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin >> V >> E;
  int s,t;
  rep(i,E){
    cin >> s >> t;
    add_edge(s,t);
  }
  scc();
  ll q;
  cin >> q;
  rep(i,q){
    cin >> s >> t;
    cout << (cmp[s] ==cmp[t]) <<endl;
  }
  return 0;
}
