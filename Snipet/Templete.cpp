#include <bits/stdc++.h>
using namespace std ;

#define pb(n) push_back(n)
#define fi first
#define se second
#define X real()
#define Y imag()
#define vmax(ary) *max_element(all(ary))
#define vmin(ary) *min_element(all(ary))
#define debug(x) cout<<#x<<": "<<x<<endl
#define fcout(n) cout<<fixed<<setprecision((n))
#define scout(n) cout<<setw(n)
#define vary(type,name,size,init) vector< type> name(size,init)

#define rep(i,a,b) for(int i = (a); i < (int)(b);++i)
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
  vector<Edge> g[100000],rg[100000];
  bool operator < (const NODE &a,const NODE &b){
    return a.cost > b.cost;
  }

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
  const double EPS = 1e-8;
  const double INF = 1e12;
  typedef complex<double> P;
  namespace std {
    bool operator < (const P& a, const P& b) {
      return real(a) != real(b) ? real(a) < real(b) : imag(a) < imag(b);
    }
  }
  double cross(const P& a, const P& b) {
    return imag(conj(a)*b);
  }
  double dot(const P& a, const P& b) {
    return real(conj(a)*b);
  }

  struct L : public vector<P> {
    L(){};
    L(const P &a, const P &b) {
      push_back(a); push_back(b);
    }
  };

  typedef vector<P> G;

  struct C {
    P p; double r;
    C(){};
    C(const P &p, double r) : p(p), r(r) { }
  };
  int ccw(P a, P b, P c) {
    b -= a; c -= a;
    if (cross(b, c) > 0)   return +1;       // counter clockwise
    if (cross(b, c) < 0)   return -1;       // clockwise
    if (dot(b, c) < 0)     return +2;       // c--a--b on line
    if (norm(b) < norm(c)) return -2;       // a--b--c on line
    return 0;
  }
  // L:line,S:segment,P:point
  bool intersectLL(const L &l, const L &m) {
    return abs(cross(l[1]-l[0], m[1]-m[0])) > EPS || // non-parallel
      abs(cross(l[1]-l[0], m[0]-l[0])) < EPS;   // same line
  }
  bool intersectLS(const L &l, const L &s) {
    return cross(l[1]-l[0], s[0]-l[0])*       // s[0] is left of l
      cross(l[1]-l[0], s[1]-l[0]) < EPS; // s[1] is right of l
  }
  bool intersectLP(const L &l, const P &p) {
    return abs(cross(l[1]-p, l[0]-p)) < EPS;
  }
  bool intersectSS(const L &s, const L &t) {
    return ccw(s[0],s[1],t[0])*ccw(s[0],s[1],t[1]) <= 0 &&
      ccw(t[0],t[1],s[0])*ccw(t[0],t[1],s[1]) <= 0;
  }
  bool intersectSP(const L &s, const P &p) {
    return abs(s[0]-p)+abs(s[1]-p)-abs(s[1]-s[0]) < EPS; // triangle inequality
  }
  // L & P intersection
  P projection(const L &l, const P &p) {
    double t = dot(p-l[0], l[0]-l[1]) / norm(l[0]-l[1]);
    return l[0] + t*(l[0]-l[1]);
  }
  // L & P Symmetry
  P reflection(const L &l, const P &p) {
    return p + 2 * (projection(l, p) - p);
  }
  double distanceLP(const L &l, const P &p) {
    return abs(p - projection(l, p));
  }
  double distanceLL(const L &l, const L &m) {
    return intersectLL(l, m) ? 0 : distanceLP(l, m[0]);
  }
  double distanceLS(const L &l, const L &s) {
    if (intersectLS(l, s)) return 0;
    return min(distanceLP(l, s[0]), distanceLP(l, s[1]));
  }
  double distanceSP(const L &s, const P &p) {
    const P r = projection(s, p);
    if (intersectSP(s, r)) return abs(r - p);
    return min(abs(s[0] - p), abs(s[1] - p));
  }
  double distanceSS(const L &s, const L &t) {
    if (intersectSS(s, t)) return 0;
    return min(min(distanceSP(s, t[0]), distanceSP(s, t[1])),
        min(distanceSP(t, s[0]), distanceSP(t, s[1])));
  }
  double distancePP(const P &p,const P &q){
    return dot((p - q), (p - q));
  }
  P crosspoint(const L &l, const L &m) {
    double A = cross(l[1] - l[0], m[1] - m[0]);
    double B = cross(l[1] - l[0], l[1] - m[0]);
    if (abs(A) < EPS && abs(B) < EPS) return m[0]; // same line
    if (abs(A) < EPS) assert(false); // !!!PRECONDITION NOT SATISFIED!!!
    return m[0] + B / A * (m[1] - m[0]);
  }
#define d(k) (dot(P[k], l[1] - l[0]))
  point extreme(const vector<point> &P, const line &l) {
    int k = 0;
    for (int i = 1; i < P.size(); ++i)
      if (d(i) > d(k)) k = i;
    return P[k];
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
const ll PrimeMax = 10000001;
int is_prime[PrimeMax];
void Eratosthenes(){
  for(int i = 0; i < PrimeMax; i++){
    is_prime[i] = 1;
  }
  is_prime[0] = 0;
  is_prime[1] = 0;
  for(int i = 2; i < PrimeMax ; i++){
    if(is_prime[i]){
      for(int j = 0; i * (j + 2) < PrimeMax; j++){
        is_prime[i *(j + 2)] = 0;
      }
    }
  }
}
int ans[1000000];
int suf = 0;
void Solve(ll n){
  for(ll i = 2; i * i <= n;++i){
    if(n % i == 0){
      ans[suf] = i;
      ++suf;
    }
  }
}

const int MAX_N = 1 << 17;
class RMQ{
  public:
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
  //min = query(a,b,0,0,n)
  int rec(int a,int b,int k,int l, int r){
    int vl,vr;
    if(r <= a || b <= l){
      return INT_MAX;
    }
    if(a <= l && r <= b){
      return dat[k];
    }
    else{
      vl = rec(a,b,k*2+1,l,(l+r)/2);
      vr = rec(a,b,k*2+2,(l+r)/2,r);
    }
    return min(vl,vr);
  }
  int query(int a,int b){
    return rec(a,b+1,0,0,n);
  }
};
class Bucket{
  public:
  vector<ll> buc,v;
  ll N,sqn,K;
  Bucket(){};
  Bucket(ll n){
    N = n;
    sqn = sqrt(N);
    K = (n + sqn - 1) /sqn;
    buc.assign(K,0);
    v.assign(K * sqn,0);
  }
  void add(int x,int y){
    v[x] += y;
    ll sum = 0;
    int k = x / sqn;
    for(int i = k * sqn; i < (k + 1) * sqn;++i){
      sum += v[i];
    }
    buc[k] = sum;
  }
  ll query(int x,int y){
    ll res = 0;
    for (int k = 0; k < K; ++k) {
      int l = k * sqn, r = (k + 1) * sqn;
      if (r <= x || y <= l)
        continue;
      if (x <= l && r <= y) {
        res += buc[k];
      } else {
        for (int i = max(x, l); i < min(y, r); ++i) {
          res += v[i];
        }
      }
    }
    return res;
  }
  void Debug(){
    for(int i = 0; i < N;++i){
      cout << buc[i/sqn] << ' ';
    }
    cout << endl;
    for(int i = 0; i < N;++i){
      cout << v[i] << ' ';
    }
    cout << endl;
  }
};
class LazyBucket{
  public:
  vector<ll> buc,v;
  ll N,sqn,K;
  LazyBucket(){};
  LazyBucket(ll n){
    N = n;
    sqn = sqrt(N);
    K = (n + sqn - 1) /sqn;
    buc.assign(K,-inf);
    v.assign(K * sqn,-inf);
  }
  ll find(int x){
    lazyupdate(x/sqn);
    return v[x];
  }
  void lazyupdate(int k){
    if(k >= K) return ;
    if(buc[k] != -inf){
      for(int i = k * sqn; i < (k+1) * sqn;++i){
        v[i] = buc[k];
      }
    }
    buc[k] = -inf;
  }
  void update(int x,int y,int n){
    for (int k = 0; k < K; ++k) {
      int l = k * sqn, r = (k + 1) * sqn;
      if (r <= x || y <= l)
        continue;
      if (x <= l && r <= y) {
        buc[k] = n;
      } else {
        lazyupdate(k);
        for (int i = max(x, l); i < min(y, r); ++i) {
          v[i] = n;
        }
      }
    }
  }
  void Debug(){
    for(int i = 0; i < N;++i){
      cout << buc[i/sqn] << ' ';
    }
    cout << endl;
    for(int i = 0; i < N;++i){
      cout << v[i] << ' ';
    }
    cout << endl;
  }
};
class BIT{
  private:
    int n,MAX_N;
    vector<int> bit;
    BIT(){};
    BIT(int _n){
      n = _n;
      MAX_N = _n;
      bit.resize(MAX_N+1);
    }
    int sum(int i){
      int s= 0;
      while(i > 0){
        s += bit[i];
        i -= i & -i;
      }
      return s;
    }
    void add(int i,int x){
      while(i <= n){
        bit[i] += x;
        i += i & -i;
      }
    }
};
//kDTree
{
  struct datas{
    ll x,y,i;
  };

  vector<datas> d ;
  bool sortx(const datas& a,const datas& b){
    return a.x < b.x;
  }
  bool sorty(const datas& a,const datas& b){
    return a.y < b.y;
  }

  const int K = 2;
  class kDTree{
    public:
      int depth;
      ll n;
      vector<datas> nodes,tree;
      kDTree(){};
      kDTree(const vector<datas> &v): n(v.size()),nodes(n),tree(n){
        rep(i,n){
          nodes[i] = v[i];
        }
        build(0,n,0);
      }
      void build(int l,int r,int _depth){
        if(l >= r) return ;
        int m = (l+r)/2;
        int axis = _depth % K;
        auto first = nodes.begin() + l, nth = nodes.begin() + m, last = nodes.begin() + r;
        if (axis == 0)
          nth_element(first, nth, last, sortx);
        else
          nth_element(first, nth, last, sorty);
        tree[m] = *nth;
        build(l,m,_depth+1);
        build(m+1,r,_depth+1);
      }
      bool range(const datas &p, int sx, int sy, int tx, int ty) {
        return sx <= p.x&&p.x <= tx&&sy <= p.y&&p.y <= ty;
      }
      void query(int sx, int sy, int tx, int ty, vector<int> &idxs) {
        query(0, n, 0, sx, sy, tx, ty, idxs);
      }
      void query(int l,int r,int depth,int sx,int sy,int tx,int ty, vector<int>& idxs){
        if(l >= r) return ;
        int m = (l+r)/2;
        datas node = tree[m];
        int axis = depth % K;
        if(axis == 0){
          if (tx < node.x) {
            query(l, m, depth+1, sx, sy, tx, ty, idxs);
          }
          else if (node.x < sx) {
            query(m + 1, r, depth+1, sx, sy, tx, ty, idxs);
          }
          else {
            if (range(node, sx, sy, tx, ty))idxs.emplace_back(node.i);
            query(l, m, depth+1, sx, sy, tx, ty, idxs);
            query(m + 1, r, depth+1, sx, sy, tx, ty, idxs);
          }
        }
        else{
          if (ty < node.y) {
            query(l, m, depth+1, sx, sy, tx, ty, idxs);
          }
          else if (node.y < sy) {
            query(m + 1, r, depth+1, sx, sy, tx, ty, idxs);
          }
          else {
            if (range(node, sx, sy, tx, ty))idxs.emplace_back(node.i);
            query(l, m, depth+1, sx, sy, tx, ty, idxs);
            query(m + 1, r, depth+1, sx, sy, tx, ty, idxs);
          }
        }
      }
      void show(){
        rep(i,n){
          cout << tree[i].x << ' ' << tree[i].y << ' ' << tree[i].i << endl;
        }
      }
  };
}
class Union_Find{
  public:
  Union_Find(){
    init();
  };
  static const ll MAX_N = 100000*2+1;
  int par[MAX_N];
  int ranks[MAX_N];
  void init(){
    rep(i,MAX_N){
      par[i] = i;
      ranks[i] = 0;
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
      if(ranks[a] == ranks[b]) ranks[a]++;
    }
  }
  bool same(int a,int b){
    return find(a) == find(b);
  }
};
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
class Time{
  public:
    int h,m,s,sec;
    Time(){
      h = m = 0;
      sec = 0;
    }
    Time(int _sec):sec(_sec){
      *this = Time().Convert(sec);
    }
    Time(int _h,int _m,int _s):h(_h),m(_m),s(_s){
      *this = Time().Convert(h,m,s);
    }
    Time& Convert(int _sec){
      int tmp = _sec;
      sec = _sec;
      h = sec / 3600;
      sec %= 3600;
      m = sec / 60;
      s = sec % 60;
      sec = tmp;
      return *this;
    }
    Time& Convert(int _h,int _m,int _s){
      h = _h,m = _m,s = _s;
      sec = s + m * 60 + h * 3600;
      return *this;
    }
    Time& operator+(const Time& a){
      sec += a.sec;
      return Convert(sec);
    }
    friend ostream& operator<<(ostream& os,const Time& t){
      os << t.h << ':' << t.m << ':' << t.s << endl;
      os << t.sec ;
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
      if((p & 1) == 1) ans = ( ans * mul) % mod;//最下位Bitが1なら ansの値を更新
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
//Useful

int numofbits5(long bits)
{
  bits = (bits & 0x55555555) + (bits >> 1 & 0x55555555);
  bits = (bits & 0x33333333) + (bits >> 2 & 0x33333333);
  bits = (bits & 0x0f0f0f0f) + (bits >> 4 & 0x0f0f0f0f);
  bits = (bits & 0x00ff00ff) + (bits >> 8 & 0x00ff00ff);
  return (bits & 0x0000ffff) + (bits >>16 & 0x0000ffff);
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

template<typename T>
bool SuffixErase(T &v,size_t suf){
  if(suf > v.size()) return false;
  for(auto it = v.begin(); it != v.end();){
    if(distance(v.begin(),it) == suf){
      v.erase(it);
      return true;
    }
    else{
      ++it;
    }
  }
  return false;
}

template<typename T>
T ston(string& str, T n){
  istringstream sin(str) ;
  T num ;
  sin >> num ;
  return num ;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  return 0;
}
