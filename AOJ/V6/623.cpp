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
const int S = 100005;
vector<Edge> g[S],rg[S];

int N;
const ll INF = 1e15;
int n,m,k,s;
ll p,X;
bool F = false;
vector<int> dan(S);
vector<ll> cost(S);
vector<ll> dijkstra(vector<Edge> g[S], int start){
  priority_queue<NODE> Q;
  Q.push({start,0});
  vector<ll> res(N,INF);
  while(Q.size()){
    NODE q= Q.top();Q.pop();
    if(res[q.pos] == INF){
      res[q.pos] = q.cost;
      if(F && q.cost <= s){
        if(cost[q.pos] == p)
          cost[q.pos] = X;
      }
    }
    else{
      continue;
    }
    for(auto n : g[q.pos]){
      if(!F){
        Q.push({n.to,q.cost+n.cost});
      }
      else if(q.cost + n.cost <= s){
        Q.push({n.to,q.cost+n.cost});
      }
    }
  }
  return res;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin >> n >> m >> k >> s ;
  N = n;
  cin >> p >> X;
  rep(i,k){
    cin >> dan[i];
    dan[i]--;
  }
  vector<int> a(m),b(m);
  rep(i,m){
    cin >> a[i] >> b[i];
    --a[i],--b[i];
    g[a[i]].push_back({b[i],1});
    g[b[i]].push_back({a[i],1});
  }
  fill(all(cost),p);
  F = true;
  rep(i,k){
    auto d = dijkstra(g,dan[i]);
    cost[dan[i]] = inf;
  }
//   rep(i,n){
//     cout << cost[i] << endl;
//   }
  F = false;
  rep(i,m){
    rg[a[i]].push_back({b[i],cost[b[i]]});
    rg[b[i]].push_back({a[i],cost[a[i]]});
  }
  auto d = dijkstra(rg,0);
  cout << d[n-1] - cost[n-1]<<endl;
  return 0;
}
