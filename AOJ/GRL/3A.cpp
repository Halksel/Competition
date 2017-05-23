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

vector<Edge> g[100001];
int prenum[100001],parent[100001],lowest[100001],visited[100001],cnt = 1,child[100001];

void Articulation_Points(int k,int p){
  visited[k] = true;
  prenum[k] = cnt;
  lowest[k] = cnt;
  ++cnt;
  for (auto&& n : g[k]) {
    if(!visited[n.to]){
      parent[n.to] = k;
      Articulation_Points(n.to,k);
      child[k]++;
      lowest[k] = min(lowest[k],lowest[n.to]);
    }
    else if(n.to != p){
      lowest[k] = min(lowest[k],prenum[n.to]);
    }
  }
}


int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n ,a,b,e;
  cin >> n >> e;
  rep(i,e){
    cin >> a >> b;
    g[a].push_back({b,0LL});
    g[b].push_back({a,0LL});
  }
  Articulation_Points(0,-1);
  set<int> ans;
  int np = 0;
  for (int i = 1; i < n; i++) {
    int p = parent[i];
    if(p == 0){
      ++np;
    }
    else{
      if(prenum[p] <= lowest[i]){
        ans.insert(p);
      }
    }
  }
  if(np > 1) ans.insert(0);
  for (auto&& k : ans) {
    std::cout << k << std::endl;
  }
  return 0;
}
