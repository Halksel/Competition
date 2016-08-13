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
using pll = pair<ll,ll> ;

const int mod = 1000000007;
constexpr int imax = ((1<<30)-1)*2+1 ;
constexpr int inf = 100000000;
constexpr double PI = acos(-1.0) ;
double eps = 1e-10 ;
const int dy[] = {-1,0,1,0};
const int dx[] = {0,-1,0,1};

inline bool value(int x,int y,int w,int h){
  return (x >= 0 && x < w && y >= 0 && y < h);
}
struct Edge{
  int to;
  double cost;
};

struct NODE{
  int pos;
  double cost;
};
bool operator < (const NODE &a,const NODE &b){
  return a.cost > b.cost;
}
vector<Edge> g[100000],rg[100000];

int N;
int s,t;
const ll INF = 1e15;
vector<double> dijkstra(vector<Edge> g[100000], int s){
  priority_queue<NODE> Q;
  Q.push({s,0});
  vector<double> res(N,INF);
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
struct Bill{
  ll id,x,y;
};
vector<Bill> B(1000);
vector<int> r;
vector<double> dis;
vector<bool> f;

void rdfs(int rs){
  if(f[rs]) return ;
  r.push_back(rs);
  f[rs] = true;
  if(rs == s) return ;
  for(auto e:g[rs]){
    if(dis[rs] == dis[e.to] + e.cost){
      rdfs(e.to);
    }
  }
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll n,m;
  while(cin >> n && n){
    N = n;
    rep(i,1000){
      g[i].clear();
    }
    map<int,int> b;
    rep(i,n){
      cin >> B[i].id >> B[i].x >> B[i].y;
      b[B[i].id] = i;
    }
    rep(i,n){
      rep(j,n){
        if(i != j){
          double dis = (B[i].x - B[j].x) * (B[i].x - B[j].x) +  (B[i].y - B[j].y) * (B[i].y - B[j].y);
          dis = sqrt(dis);
          if(dis  <= 50.0){
            g[i].push_back({j,dis});
//             g[j].push_back({i,dis});
          }
        }
      }
    }
    cin >> m;
    rep(i,m){
      cin >> s >> t;
      s = b[s];
      t = b[t];
      dis = dijkstra(g,s);
      r.clear();
      f = vector<bool>(n,false);
      rdfs(t);
      if(dis[t] == INF){
        cout << "NA" << endl;
      }
      else{
        reverse(all(r));
        rep(i,r.size()){
          if(i) cout << ' ';
          cout << B[r[i]].id;
        }
        cout << endl;
      }
    }
  }
  return 0;
}
