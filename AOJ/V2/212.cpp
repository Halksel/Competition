#include <bits/stdc++.h>
using namespace std ;

#define pb(n) push_back(n)
#define fi first
#define se second
#define X real()
#define Y imag()
#define value(x,y,w,h) (x >= 0 && x < w && y >= 0 && y < h)
#define all(r) (r).begin(),(r).end()
#define gsort(st,en) sort((st),(en),greater<int>())
#define vmax(ary) *max_element(all(ary))
#define vmin(ary) *min_element(all(ary))
#define debug(x) cout<<#x<<": "<<x<<endl
#define fcout(n) cout<<fixed<<setprecision((n))
#define scout(n) cout<<setw(n)

#define rep(i,n) for(int i = 0; i < (int)(n);++i)
#define REP(i,a,b) for(int i = (a);i < (int)(b);++i)
#define repi(it,array) for(auto it = array.begin(),end = array.end(); it != end;++it)
#define repa(n,array) for(auto &n :(array))

typedef long long ll ;
typedef deque<int> di ;
typedef deque<ll> dl ;
typedef map<string,int> dict;
typedef complex<double> comd;
typedef pair<int,int> pii;

constexpr int imax = ((1<<30)-1)*2+1 ;
constexpr int inf = 100000000;
constexpr double PI = acos(-1.0) ;
double eps = 1e-10 ;
const int dy[] = {-1,0,1,0};
const int dx[] = {0,-1,0,1};

double CalcDist(comd p1, comd p2){
  return sqrt(pow(p1.X - p2.X,2.0) + pow(p1.Y -p2.Y,2.0));
}

template <typename T>
void out(deque < T > d)
{
  for(size_t i = 0; i < d.size(); i++)
  {
    debug(d[i]);
  }
}

template<typename T>
T ston(string& str, T n){
  istringstream sin(str) ;
  T num ;
  sin >> num ;
  return num ;
}

int c,N,m,s,D;
const ll INF = 1e15;
const int MAX_V = 1000;
int d[MAX_V];
vector<vector<int>> cost(MAX_V,vector<int>(MAX_V,inf)),cp;
int pre[MAX_V];
bool used[MAX_V];

int V;
void dijkstra(int s){
  fill(d,d+V,inf);
  fill(used,used+V,false);
  fill(pre,pre+V,-1);
  d[s] = 0;
  while(1){
    int v = -1;
    for(int u = 0; u < V; u++){
      if(!used[u] && ( v == -1 || d[u] < d[v])) v = u;
    }
    if(v == -1){
      break;
    }
    used[v] = true;
    rep(u ,V){
      if(d[u] > d[v] + cost[v][u]){
        d[u] = d[v] + cost[v][u];
        pre[u] = v;
      }
    }
  }
}
vector<int> get_path(int t){
  vector<int> path;
  for(; t != -1; t = pre[t]) path.pb(t);
  reverse(all(path));
  return path;
}
int main(){
  cp = cost;
  while(  cin >> c >> N >> m >> s >> D){
    if(c+N+m+s+D == 0) break;
    V = N;
    cost = cp;
    int a,b,f;
    rep(i,N){
      cin >> a >> b >> f;
      --a,--b;
      cost[a][b] = f;
      cost[b][a] = f;
    }
    dijkstra(s-1);
    int ans = 0;
    auto path = get_path(D-1);
//     rep(i,path.size()){
//       cout << path[i]+1 << ":" << cost[path[i]][path[i+1]] <<endl;
//     }
    vector<int> v(0);
    rep(i,path.size()-1){
      v.pb(cost[path[i]][path[i+1]]);
    }
    sort(all(v),greater<int>());
    rep(i,v.size()){
      if(i < c){
        ans += v[i]/2;
      }
      else ans += v[i];
    }
    cout << ans << endl;
  }
  return 0;
}
