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
#define vary(type,name,size,init) vector< type> name(size,init)

#define rep(i,n) for(int i = 0; i < (int)(n);++i)
#define REP(i,a,b) for(int i = (a);i < (int)(b);++i)
#define repi(it,array) for(auto it = array.begin(),end = array.end(); it != end;++it)
#define repa(n,array) for(auto &n :(array))

using ll = long long;
using pii = pair<int,int> ;

constexpr int imax = ((1<<30)-1)*2+1 ;
constexpr int inf = 100000000;
constexpr double PI = acos(-1.0) ;
double eps = 1e-10 ;
const int dy[] = {-1,0,1,0,1,-1,1,-1};
const int dx[] = {0,-1,0,1,1,-1,-1,1};
namespace dijkstra{
  const int MAX_V = 1000000;
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
  vector<ll> dijkstra(vector<Edge> g[100000], int s){
    priority_queue<NODE> Q;
    Q.push({s,0});
    vector<ll> res(N,INF);
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
}
using namespace dijkstra;
namespace Prim{
  const int MAX_V = 1000000;
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
    rep(i,V){
      g[i].clear();
    }
    return res;
  }
}
using namespace Prim;
namespace SCC{
  const int MAX_V = 100000000;
  ll V;
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
}
using namespace SCC;
namespace Geometry{
  double EPS = 1e-10;
  double add(double a, double b){
    if(abs(a+b) < EPS* (abs(a) + abs(b))) return 0;
    return a+b;
  }

  struct P{
    double x,y;
    P(){}
    P(double _x,double _y):x(_x),y(_y){}
    P operator + (P p){
      return P(add(x,p.x) ,add(y,p.y));
    }
    P operator - (P p){
      return P(add(x,-p.x) ,add(y,-p.y));
    }
    P operator * (double d){
      return P(x * d,y * d);
    }
    bool operator==(const P p){
      return (x == p.x && y == p.y);
    }
    friend ostream& operator<<(ostream& os,const P& p){
      os << "("<<p.x <<","<<p.y<<")";
      return os;
    }
    double norm(){
      return sqrt(x*x + y*y);
    }
    double dot(P p){
      return add(x * p.x,y*p.y);
    }
    double det(P p){
      return add(x*p.y,-y*p.x);
    }
    double dist2(P p){
      return ((*this-p).x * (*this-p).x) + ((*this-p).y * (*this-p).y);
    }
    P GetCenter(P &p){
      return P((*this+p).x/2,(*this+p).y/2);
    }
    double GetSlope(P &p){
      P tmp = *this - p;
      return tmp.y/tmp.x;
    }
  };
  //線分上に点が存在するか
  bool on_seg(P p1,P p2,P q){
    return (p1-q).det(p2-q) == 0 && (p1-q).dot(p2-q) <= 0;
  }
  //交点導出
  P intersection(P p1, P p2, P q1,P q2){
    return p1 + (p2-p1) * ((q2 - q1).det(q1-p1) / (q2 - q1).det(p2-p1)) ;
  }
}
using namespace Geometry;
//四捨五入
double ceilN(double a, int N){
  double ans,sign;
  sign = (a < 0)? -1 : 1;
  ans = a * pow(10.0,N);
  ans = (double)(int)(ans+ 0.5 * sign);
  return ans * pow(10.0,-N);
}
//Eratosthenes
const int PrimeMax = 100001;
int is_prime[PrimeMax];
void Eratosthenes(int N){
  for(int i = 0; i < N; i++){
    is_prime[i] = 1;
  }
  is_prime[0] = 0;
  is_prime[1] = 0;
  for(int i = 2; i < N ; i++){
    if(is_prime[i]){
      for(int j = 0; i * (j + 2) < N; j++){
        is_prime[i *(j + 2)] = 0;
      }
    }
  }
}

namespace RMQ{
  const int MAX_N = 1 << 17;
  int n, dat[2*MAX_N - 1];

  void init(int n_){
    n = 1;
    while(n < n_){
      n *= 2;
    }

    for(int i =0; i < 2*n-1;++i){
      dat[i] = INT_MAX;
    }
  }

  void update(int k, int a){
    k += n-1;
    dat[k] = a;
    while(k>0){
      k = (k-1)/2;
      dat[k] = min(dat[k*2+1],dat[k*2+2]);
    }
  }

  int query(int a,int b,int k,int l, int r){
    int vl,vr;
    if(r <= a || b <= l){
      return INT_MAX;
    }
    if(a <= l && r <= b){
      return dat[k];
    }
    else{
      vl = query(a,b,k*2+1,l,(l+r)/2);
      vr = query(a,b,k*2+2,(l+r)/2,r);
    }
    return min(vl,vr);
  }
}
using namespace RMQ;
namespace Union_Find{
  const int MAX_N =10001;
  int par[MAX_N];
  int ranks[MAX_N];
  void init(int n){
    rep(i,n){
      par[i] = i;
      ranks[i] = 1;
    }
  }
  int find(int x){
    if(par[x] == x){
      return x;
    }
    else{
      return par[x] = find(par[x]);
    }
  }

  void Unite(int a, int b){
    a = find(a);
    b = find(b);
    if(a == b) return ;
    if(ranks[a] < ranks[b]){
      par[a] = b;
    }
    else{
      par[b] = a;
      if(ranks[a] == ranks[b]) ranks[b]++;
    }
  }

  bool same(int a,int b){
    return find(a) == find(b);
  }
}
using namespace Union_Find;
//GCD & LCM
int gcd(int a,int b){
  if(a < b) swap(a,b);
  if(b == 0) return a;
  return gcd(b,a%b);
}

int lcm(int a,int b){
  return a/ gcd(a,b) * b;
}
//Split
vector<string> Split(const string& s,const string d){
  string item(s);
  vector<string> res(0);
  for(auto pos = item.find(d); pos != string::npos; pos = item.find(d,pos)){
    item.replace(pos,d.size()," ");
  }
  stringstream buf(item);
  while(buf >> item){
    res.push_back(item);
  }
  return res;
}

template<typename T>
void Unique(vector<T> &v){
  sort(all(v));
  v.erase(unique(all(v)),v.end());
}

namespace Compress{
  int n;
  template<typename T>
    int Compress( T &x1, T &x2,int w){
      vector<int> xs;
      rep(i,n){
        for(int d = -1; d <= 1;++d){
          int tx1 = x1[i]+d,tx2 = x2[i]+d;
          if(1 <= tx1 && tx1 <= w) xs.push_back(tx1);
          if(1 <= tx2 && tx2 <= w) xs.push_back(tx2);
        }
      }
      Unique(xs);
      rep(i,n){
        x1[i] = find(all(xs),x1[i])-xs.begin();
        x2[i] = find(all(xs),x2[i]) - xs.begin();
      }
      return xs.size();
    }
}
using namespace Compress;
//Dice
enum{
  t = 0,f ,r ,b ,l ,d ,
};
template<typename S>
class Dice{
  public:
    array<S,6> D;
    Dice(){
    }
    Dice(array<S,6> d){
      copy(all(D),d.begin());
    }
    void Spin(int dir){
      if(dir == l){//
        swap(D[t],D[r]);
        swap(D[r],D[d]);
        swap(D[d],D[l]);
      }
      else if(dir == r){
        swap(D[t],D[l]);
        swap(D[l],D[d]);
        swap(D[d],D[r]);
      }
      else if(dir == f){
        swap(D[t],D[b]);
        swap(D[b],D[d]);
        swap(D[d],D[f]);
      }
      else if(dir == b){
        swap(D[t],D[f]);
        swap(D[f],D[d]);
        swap(D[d],D[b]);
      }
      else if(dir == d){//leftspin
        swap(D[f],D[r]);
        swap(D[r],D[b]);
        swap(D[b],D[l]);
      }
      else if(dir == t){
        swap(D[f],D[l]);
        swap(D[l],D[b]);
        swap(D[b],D[r]);
      }
    }
    void MatchDice(int T,int F){
      rep(i,4){
        Spin(r);
        if(D[t] == T)break;
      }
      if(D[t] != T){
        rep(i,4){
          Spin(f);
          if(D[t] == T)break;
        }
      }
      rep(i,4){
        Spin(t);
        if(D[f] == F) break;
      }
    }
    S& operator[](const int i){
      return D[i];
    }
    bool operator==(Dice& di2){
      rep(i,4){
        di2.Spin(r);
        rep(j,4){
          di2.Spin(t);
          rep(k,4){
            di2.Spin(r);
            if(D == di2.D){
              return true;
            }
          }
        }
      }
      return false;
    }
    friend ostream& operator<<(ostream& os,const Dice& di){
      os << "t f r l b d\n" ;
      rep(i,6){
        if(i) os << ' ';
        os << di.D[i] ;
      }
      return os;
    }
};
namespace CalcEquations{
  const int M = 4;

  double a[M][M], l[M][M] , u[M][M] , x[M], b[M], c[M];

  void CalcEquations(){
    rep(i,M){
      rep(j,M){
        cin >> a[i][j];
      }
      cin >> b[i];
    }
    rep(i,M){
      rep(j,M){
        u[i][j] = 0;
        if(i == j)
          l[i][j] = 1;
        else
          l[i][j] = 0;
      }
    }

    rep(i,M){
      int suf = i;
      double ma = abs(a[i][i]);
      for(int j = i; j < M; ++j){
        if(ma < abs(a[j][i])){
          suf = j;
          ma = a[j][i];
        }
      }
      for(int j = 0; j < M; ++j){
        swap(a[i][j],a[suf][j]);
      }
      swap(b[i],b[suf]);
      for(int j = 0; j < i; ++j){
        swap(l[i][j],l[suf][j]);
      }
      for(int j = i; j < M; ++j){
        u[i][j] = a[i][j];
        rep(k,i){
          u[i][j] -= u[k][j] * l[i][k];
        }
      }
      for(int j = i+1; j < M; ++j){
        l[j][i] = a[j][i];
        rep(k,i){
          l[j][i] -= u[k][i] * l[j][k];
        }
        l[j][i] /= u[i][i];
      }
    }
    rep(i,M){
      c[i] = b[i];
      rep(j,i){
        c[i] -= l[i][j] * c[j];
      }
    }
    for(int i = M - 1; i >= 0; --i){
      x[i] = c[i];
      for(int j = M - 1; j > i; --j){
        x[i] -= u[i][j] * x[j];
      }
      x[i] /= u[i][i];
    }

    cout << "Input" << endl;
    rep(j,M){
      rep(i,M){
        fcout(8) << a[j][i];
      }
      fcout(8) << b[j] << endl;
    }
    cout << "L Matrix" << endl;
    rep(j,M){
      rep(i,M){
        cout << l[j][i] ;
      }
      cout << endl;
    }
    cout << "U Matrix" << endl;
    rep(j,M){
      rep(i,M){
        cout << u[j][i] ;
      }
      cout << endl;
    }
    cout << "answer" << endl;
    rep(i,M){
      if(abs(x[i]) < eps){
        x[i] = 0.0;
      }
      cout << "x" << i << "=" << x[i] << endl;
    }
  }
}
using namespace CalcEquations;

namespace powmod{
  const ll mod = 1e9+7;
  ll powmod(ll a, ll p){
    ll ans = 1;
    ll mul = a;
    for(; p > 0; p >>= 1, mul = (mul*mul) % mod){ //初期条件なし、pを2で割り続け、mulの値を更新
      if((p & 1) == 1) ans = ( ans * mul) % mod;//pが1なら ansの値を更新
    }
    return ans;
  }

  const int MAX_N = 2000001;

  ll fact[MAX_N];
  ll revfact[MAX_N];

  void setFact(int N){
    fact[0] = 1;
    for(int i = 1; i < N; ++i){
      fact[i] = fact[i-1]*i;
      fact[i] %= mod;
    }
    revfact[N-1] = powmod(fact[N-1],mod-2);//逆元を求める
    for(int i = N-2;i >= 0;--i){
      revfact[i] = revfact[i+1] * (i+1);
      revfact[i] %= mod;//互いに素
    }
  }

  ll getC(int a, int b){
    return (fact[a] * revfact[b] % mod) * revfact[a-b] % mod;
  }
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  return 0;
}
