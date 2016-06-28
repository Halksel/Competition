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

template<typename T>
void Unique(vector<T> &v){
  sort(all(v));
  v.erase(unique(all(v)),v.end());
}
template<typename T,typename U>
ll FindErase(T &v,U tar){
  ll cnt = 0;
  for(auto it = v.begin(); it != v.end();){
    if(*it == tar){
      it = v.erase(it);
      ++cnt;
    }
    else{
      ++it;
    }
  }
  return cnt;
}

struct Edge{
  int to;
  long long cost;
};

struct NODE{
  ll pos;
  long long cost;
};
bool operator >(const NODE &a,const NODE &b){
  return a.cost < b.cost;
}
vector<Edge> g[200001],rg[200000];

int N;
const ll INF = 1e15;
vector<bool> fil(200001,false);
vector<ll> dijkstra(vector<Edge> g[200001], int s){
  priority_queue<NODE,vector<NODE>, greater<NODE>> Q;
  Q.push({s,s});
  vector<ll> res(N,INF);
  while(Q.size()){
    NODE q= Q.top();Q.pop();
    if(res[q.pos] == INF){
      res[q.pos] = min(q.cost,q.pos);
    }
    else{
      continue;
    }
    for(auto n : g[q.pos]){
      Q.push({n.to,min(q.cost,n.cost)});
    }
  }
  return res;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll m,s,u,v;
  cin >> N >> m >> s ;
  rep(i,m){
    cin >> u >> v;
    --u,--v;
    g[u].push_back({v,u});
    g[v].push_back({u,v});
  }
  --s;
  auto d = dijkstra(g,s);
  rep(i,N){
    if(d[i] == i){
      cout << i+1 << endl;
    }
  }
  return 0;
}
