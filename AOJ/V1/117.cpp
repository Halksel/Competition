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

int N;
const ll INF = 1e15;
vector<ll> dijkstra(vector<Edge> g[100000],int start){
  priority_queue<NODE> Q;
  Q.push({start,0});
  vector<ll> res(N+1,INF);
  while(Q.size()){
    NODE q= Q.top();Q.pop();
    if(res[q.pos] == INF){
      res[q.pos] = q.cost;
    }
    else{
      continue;
    }
    for(auto n : g[q.pos]){
      Q.push({n.to,q.cost+n.cost});
    }
  }
  return res;
}
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int m,a,b,d,e,x,x2,y,y2;
  char c;
  cin >>N>>m;
  rep(i,m){
    cin >> a>>c>>b>>c>>d>>c>>e;
    g[a].push_back(Edge{b,d});
    g[b].push_back(Edge{a,e});
  }
  cin >> x >>c>> x2>>c >> y>>c >> y2;
  auto res = dijkstra(g,x);
  auto res2 = dijkstra(g,x2);
  cout << y - res[x2]-res2[x] -y2 << endl;
  return 0;
}
