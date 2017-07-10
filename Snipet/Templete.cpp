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

const ll mod = 1e9+7;
constexpr ll inf = ((1<<30)-1)*2+1 ;
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
class dijkstra{
  public:
    const int MAX_V = 1000000;
    vector<Edge> g[100000],rg[100000];
    bool visit[100000];

    int N;
    const ll INF = 1e15;
    dijkstra(){};
    dijkstra(int n):N(n){};
    vector<ll> shorter_path(int s){
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
    void push(int p,int to,int c){
      g[p].push_back({to,c});
      rg[to].push_back({p,c});
    }
    deque<ll> Topological_sort(){
      deque<ll> res;
      rep(i,N){
        dfs(res,i);
      }
      return res;
    }
    void dfs(deque<ll> &res,int k){
      if(!visit[k]){
        visit[k] = true;
        for (auto&& nxt : g[k]) {
          dfs(res,nxt.to);
        }
        res.emplace_front(k);
      }
    }
    pll farthest_point(int n,int p){
      pll r = {0,n};
      for (auto&& k : g[n]) {
        if(k.to != p){
          pll res = farthest_point(k.to,n);
          res.fi += k.cost;
          if(r.fi < res.fi) r = res;
        }
      }
      return r;
    }
    ll diameter(){
      pll a = farthest_point(0,-1);
      pll b = farthest_point(a.se,-1);
      return b.fi;
    }
};
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
namespace Flow {

  struct edge {int to, cap, rev;};
  const ll MAX_V = 101;
  vector<edge> G[MAX_V];
  bool used[MAX_V];

  void add_edge(int from, int to, int cap){
    G[from].push_back(edge{to,cap,G[to].size()});
    G[to].push_back(edge{from,0,G[from].size()-1});
  }

  int dfs(int v,int t,int f){
    if(v == t) return f;
    used[v] = true;
    rep(i,G[v].size()){
      auto &e = G[v][i];
      if(!used[e.to] && e.cap > 0){
        int d = dfs(e.to,t,min(f,e.cap));
        if(d > 0){
          e.cap -= d;
          G[e.to][e.rev].cap += d;
          return d;
        }
      }
    }
    return 0;
  }

  int max_flow(int s,int t){
    int flow = 0;
    for(;;){
      memset(used, 0,sizeof(used));
      int f = dfs(s,t,inf);
      if(f == 0) return flow;
      flow += f;
    }
  }
} // namespace Flow

namespace Bipartite_matching {
  int V;
  const ll MAX_V = 101;
  vector<ll> G[MAX_V];
  int match[MAX_V];
  bool used[MAX_V];

  void add_edge(int u,int v){
    G[u].push_back(v);
    G[v].push_back(u);
  }

  bool dfs(int v){
    used[v] = true;
    rep(i,G[v].size()){
      int u = G[v][i], w = match[u];
      if(w < 0 || !used[w] && dfs(w)){
        match[v] = u;
        match[u] = v;
        return true;
      }
    }
    return false;
  }
  ll bipartite_matching(){
    ll res = 0;
    memset(match,-1,sizeof(match));
    rep(v,V){
      if(match[v] < 0){
        memset(used,-1,sizeof(used));
        if(dfs(v)) ++res;
      }
    }
    return res;
  }
  const int MAX_N = 100;

  int N;
  ll minimum_cover_path(){
    V = N * 2;
    rep(i,V) G[i].clear();
    rep(i,N){
      rep(j,N){
        if(i == j) continue;
        bool f = true;
        /*
          ここにi と jを結ぶことのできる条件を設定する
         */
        if(f) add_edge(i,N+j);
      }
    }
    return N - bipartite_matching();
  }
} // namespace Bipartite_matching



namespace Geometry{
#define curr(P, i) P[i]
#define next(P, i) P[(i+1)%P.size()]
#define diff(P, i) (next(P, i) - curr(P, i))
  const double EPS = 1e-8;
  const double INF = 1e12;
  const double PI = acos(-1);
  double d2r(int d){
    return (1.0 * d/180)*PI;
  }
  typedef complex<double> P;//複素数を平面における点と解釈
  P inputP(){
    double x,y;
    cin >> x >> y;
    return P(x,y);
  }
  class L{// line
    public:
      vector<P> l;
      P v;
      L(){};
      L(const P &a, const P &b) {
        l.push_back(a); l.push_back(b);
        v = (b-a);
      }
      L(double a,double b,double c,double d){
        l.push_back(P(a,b)),l.push_back(P(c,d));
      }
      P& operator[](const int i){
        return l[i];
      }
      void input() {
        double a, b,c,d;
        cin >> a >> b >> c >> d;
        l.clear();
        l.push_back(P(a,b)),l.push_back(P(c,d));
      }
  };

  class G {
    public:
      vector<P> g;
      vector<L> l;
      ll n;
      G(){};
      G(int _n):n(_n){
        double x,y;
        l.resize(n),g.resize(n);
        rep(i,n){
          cin >> x >> y;
          g[i] = (P(x,y));
        }
        rep(i,n){
          l[i] = L(g[i],g[(i+1)%n]);
        }
      }
      G (vector<P> ps){
        n = ps.size();
        g.resize(n),l.resize(n);
        rep(i,n){
          g[i] = ps[i];
        }
        rep(i,n){
          l[i] = L(g[i],g[(i+1)%n]);
        }
      }
      P& operator[](int i){
        return g[i];
      }
      void push_back(P p){
        g.push_back(p);
      }
      size_t size(){
        return g.size();
      }
      void resize(int n){
        g.resize(n),l.resize(n);
      }
      friend ostream& operator<<(ostream& os,const G& g){
        rep(i,g.n){
          if(i) os << ' ';
          os << g.g[i] ;
        }
        return os;
      }
  };

  struct C {//円
    P p; double r;
    C(){};
    C(const P &p, double r) : p(p), r(r) { }
    void input(){
      double x,y;
      cin >> x >> y >> r;
      p = P(x,y);
    }
  };
  namespace std {
    bool operator < (const P& a, const P& b) {//x軸を優先
      return real(a) != real(b) ? real(a) < real(b) : imag(a) < imag(b);
    }
    bool sorty(const P& a, const P& b) {//y軸を優先
      return imag(a) != imag(b) ? imag(a) < imag(b) : real(a) < real(b);
    }
    bool same(const P& a, const P& b) {
      P p = a - b;
      if(abs(real(p)) < EPS && abs(imag(p)) < EPS){
        return true;
      }
      return false;
    }
  }
  double cross(const P& a, const P& b) {//外積
    return imag(conj(a)*b);
  }
  double dot(const P& a, const P& b) {//内積
    return real(conj(a)*b);
  }

  int ccw(P a, P b, P c) {//3点がどの順番で並んでいるかの判定
    b -= a; c -= a;
    if (cross(b, c) > 0)   return +1;       // counter clockwise
    if (cross(b, c) < 0)   return -1;       // clockwise
    if (dot(b, c) < 0)     return +2;       // c--a--b on line
    if (norm(b) < norm(c)) return -2;       // a--b--c on line
    return 0; // a--c--b on line
  }
  int linejudge(L &ab,L &cd){ //2直線間の関係
    P a = ab[1] - ab[0],b = cd[1] - cd[0];
    if(abs(cross(a,b)) < EPS){ // Parallel
      return 2;
    }
    else if(abs(dot(a,b)) < EPS){ //Orthogonal
      return 1;
    }
    return 0;
  }
  // L:line,S:segment,P:point
  bool intersectLL( L l,  L m) {
    return abs(cross(l[1]-l[0], m[1]-m[0])) > EPS || // non-parallel
      abs(cross(l[1]-l[0], m[0]-l[0])) < EPS;   // same line
  }
  bool intersectLS( L l,  L s) {
    return cross(l[1]-l[0], s[0]-l[0])*       // s[0] is left of l
      cross(l[1]-l[0], s[1]-l[0]) < EPS; // s[1] is right of l
  }
  bool intersectLP( L l,  P p) {
    return abs(cross(l[1]-p, l[0]-p)) < EPS;
  }
  bool intersectSS( L s,  L t) {
    return ccw(s[0],s[1],t[0])*ccw(s[0],s[1],t[1]) <= 0 &&
      ccw(t[0],t[1],s[0])*ccw(t[0],t[1],s[1]) <= 0;
  }
  bool intersectSP( L s,  P p) {
    return abs(s[0]-p)+abs(s[1]-p)-abs(s[1]-s[0]) < EPS; // triangle inequality
  }
  bool intersectSG(L l, G g) {
    int n = g.size();
    rep(i, n) {
      if (intersectSS(l, L(curr(g, i), next(g, i)))) {
        return true;
      }
    }
    return false;
  }
  // L & P intersection
  P projection( L &l,  P &p) {
    double t = dot(p-l[0], l[0]-l[1]) / norm(l[0]-l[1]);
    return l[0] + t*(l[0]-l[1]);
  }
  // Lに対するPの反射点
  P reflection( L &l,  P &p) {
    return p + 2.0 * (projection(l, p) - p);
  }
  double distanceLP( L l,  P p) {
    return abs(p - projection(l, p));
  }
  double distanceLL( L l,  L m) {
    return intersectLL(l, m) ? 0 : distanceLP(l, m[0]);
  }
  double distanceLS( L l,  L s) {
    if (intersectLS(l, s)) return 0;
    return min(distanceLP(l, s[0]), distanceLP(l, s[1]));
  }
  double distanceSP( L s,  P p) {
    P r = projection(s, p);
    if (intersectSP(s, r)) return abs(r - p);
    return min(abs(s[0] - p), abs(s[1] - p));
  }
  double distanceSS( L s,  L t) {
    if (intersectSS(s, t)) return 0;
    return min(min(distanceSP(s, t[0]), distanceSP(s, t[1])), min(distanceSP(t, s[0]), distanceSP(t, s[1])));
  }
  double distancePP( P p, P q){
    return abs(p - q) ;
  }
  double distanceSG(L l, G g) {
    double d = INF;
    rep(i, g.size()) {
      d = min(d, distanceSS(l, L(curr(g, i), next(g, i))));
    }
    return d;
  }
  P crosspoint(L &l,L &m) {
    double A = cross(l[1] - l[0], m[1] - m[0]);
    double B = cross(l[1] - l[0], l[1] - m[0]);
    if (abs(A) < EPS && abs(B) < EPS) return m[0]; // same line
    if (abs(A) < EPS) assert(false); // !!!PRECONDITION NOT SATISFIED!!!
    return m[0] + B / A * (m[1] - m[0]);
  }
  P crosspointSS(L &l1,L &l2) {
    double d1 = abs(cross(l2.v, l1[0] - l2[0])); // l1.a - l2.b???
    double d2 = abs(cross(l2.v, l1[1] - l2[0]));
    double t = d1 / (d1 + d2);
    return l1[0] + t * l1.v;
  }
  P verticalvector( P &a, P &b){//2点の単位法線ベクトルを返す
    if(a.real() == b.real()){
      return {1.0,0};
    }
    if(a.imag() == b.imag()){
      return {0,1.0};
    }
    P p = a - b;
    P res = {-p.imag(),p.real()};
    return res / abs(p);
  }
  pair<P,P> crosspoint(const C &a,const C &b){
    double d = abs(b.p-a.p);
    double c = acos((a.r*a.r+d*d-b.r*b.r)/(2.0*a.r*d));
    double t = arg(b.p-a.p);
    P A = a.p + polar(a.r,t+c),B = a.p + polar(a.r,t-c);
    if(A < B)
      return mp(A,B);
    return mp(B,A);
  }
  // a < b : -1, a > b : 1, a == b : 0
  inline int sgn(double a, double b = 0) { return a < b - EPS ? -1 : a > b + EPS ? 1 : 0; }
  int circle_judge(C &a,C &b){ // return tangent count
    double d = distancePP(a.p,b.p);
    double e = a.r,f = b.r;
    if(sgn(d,e+f) == 1) return 4;
    if(sgn(d,e+f) == 0) return 3;
    if(sgn(d,abs(e-f)) == -1) return 0;
    if(sgn(d,abs(e-f)) == 0 ) return 1;
    return 2;
  }
  double calc_triangle(P a,P b,P c){
    P ba = (b - a);
    P ca = (c - a);
    return (real(ba) * imag(ca) - imag(ba) * real(ca))/2.0;
  }
  double calc_area(G &g){
    double res = 0;
    rep(i,g.size()-2){
      res += calc_triangle(g[0],g[(i+1) % g.size()],g[(i+2) % g.size()]);
    }
    return res;
  }
  bool is_convex(G &g){
    if(g.size() == 3) return true;
    rep(i,g.size()){
      if(ccw(g[i],g[(i+1) % g.size()],g[(i+2) % g.size()]) != 1 && ccw(g[i],g[(i+1) % g.size()],g[(i+2) % g.size()]) != -2){
        return false;
      }
    }
    return true;
  }
  int convex_point(G &g,const P &p){
    P q = p-P(-INF,imag(p));
    double x = real(p),y = imag(p);
    L l1(p,q);
    ll cn = 0;
    rep(i,g.size()){
      P a = g[i],b = g[(i+1) % g.size()];
      L l2 = L(a,b);
      int k = ccw(a,b,p);
      if(k == 0){
        return 1; // p on g
      }
    }
    rep(i,g.size()){
      P a = g[i],b = g[(i+1) % g.size()];
      double y1 = imag(a),y2 = imag(b);
      if(!(y1 == y && y2 == y) && ((y1 <= y && y < y2) || (y2 <= y && y < y1))){
        L l2 = L(a,b);
        P c = crosspoint(l1,l2);
        if(x < real(c))
          ++cn;
      }
    }
    if(cn % 2) return 2; // p in g
    return 0; // p out g
  }
  double distance(G &g, P &p){
    if(convex_point(g,p)) return 0;
    double res = INF;
    ll N = g.size();
    rep(i,N){
      L l = L(g[i],g[(i+1)%N]);
      res = min(res,distanceSP(l,p));
    }
    return res;
  }

  double distance(G &g, G &h){
    double res = INF;
    ll N = g.size();
    ll M = h.size();
    rep(i,N){
      L l = L(g[i],g[(i+1)%N]);
      rep(j,M){
        L k = L(h[j],h[(j+1)%M]);
        res = min(res,distanceSS(l,k));
      }
    }
    return res;
  }
  vector<P> convex_hull(vector<P> &ps){
    sort(all(ps));
    int k = 0;
    int n = ps.size();
    vector<P> qs(ps.size() * 2);
    rep(i,ps.size()){
      while(k > 1 && cross((qs[k-1] -qs[k-2]),(ps[i] - qs[k-1])) < 0){
        k--;
      }
      qs[k++] = ps[i];
    }
    for(int i = n-2,t = k; i >= 0; i--){
      while(k>t && cross((qs[k-1] - qs[k-2]),(ps[i]-qs[k-1])) < 0){
        k--;
      }
      qs[k++] = ps[i] ;
    }
    qs.resize(k-1);
    return qs;
  }
  double convex_diameter(vector<P> &ps){
    const int n = ps.size();
    int is = 0,js = 0;
    REP(i,1,n){
      if(imag(ps[i]) > imag(ps[is])) is = i;
      if(imag(ps[i]) < imag(ps[js])) js = i;
    }
    double d = norm(ps[is]-ps[js]);
    int im,jm,i,j;
    i = im = is;
    j = jm = js;
    do {
      if(cross(diff(ps,i),diff(ps,j)) >= 0) j = (j+1) % n;
      else i = (i+1) % n;
      if(norm(ps[i]-ps[j]) > d){
        d = norm(ps[i]-ps[j]);
        im = i,jm = j;
      }
    } while (i != is || j != js);
    return sqrt(d);
  }
  G convex_cut(G &g, L &l) {
    G h;
    rep(i, (int)g.size()) {
      P p = curr(g, i), q = next(g, i);
      if (ccw(p, q, l[0]) == 0 && ccw(p, q, l[1]) == 0) {
        if (ccw(p, l[1], l[0]) == 0) return g;    // p -- l.a -- l.b -- q
        else return G{};                        // p -- l.b -- l.a -- q
      }
      if (ccw(l[0], l[1], p) != -1) h.push_back(p);
      if (ccw(l[0], l[1], p) * ccw(l[0], l[1], q) < 0){
        L t = L(p,q);
        h.push_back(crosspoint(t, l));
      }
    }
    return h;
  }
  double closestPair_calc(P *p,int n){
    if(n < 2) return INF;
    int m = n/2;
    double x=real(p[m]);
    double d = min(closestPair_calc(p,m),closestPair_calc(p+m,n-m));
    inplace_merge(p,p+m,p+n,sorty);
    vector<P> q;
    double dx,dy;
    rep(i,n) {
      if(abs(real(p[i])-x)>=d)continue;

      for(int j=q.size()-1;j>=0;j--)
      {
        dx=real(p[i])-real(q[j]);
        dy=imag(p[i])-imag(q[j]);
        if(dy>=d)break;
        d=min(d,sqrt(dx*dx+dy*dy));
      }
      q.push_back(p[i]);
    }
    return d;
  }

  double closestPair(vector<P> &p,int n) {
    if(n < 2) return 0.0;
    sort(all(p));
    double ans = closestPair_calc(&p[0],n);
    return ans == INF ? 0.0 : ans;
  }
  //3D
  double add(double a, double b) {
    if (abs(a + b) < EPS * (abs(a) + abs(b))) return 0;
    return a + b;
  }
  struct Point {
    double x, y, z;
    Point() {}
    Point(double _x, double _y, double _z) : x(_x), y(_y), z(_z) {}
    void input(){
      cin >> x >> y >> z;
    }
    const Point operator+ (const Point &p) {
      return Point(add(this->x, p.x), add(this->y, p.y), add(this->z, p.z));
    }
    const Point operator- (const Point &p) {
      return Point(add(this->x, -p.x), add(this->y, -p.y), add(this->z, -p.z));
    }
    const Point operator* (double d) {
      return Point(this->x * d, this->y * d, this->z * d);
    }
    double norm() {
      return this->x * this->x + this->y * this->y + this->z * this->z;
    }
    double distance() {
      return sqrt(this->norm());
    }
  };

  double dot(const Point &p1, const Point &p2) {
    return p1.x * p2.x + p1.y * p2.y + p1.z * p2.z;
  }
  Point cross(const Point &p1, const Point &p2) {
    return Point(p1.y * p2.z - p2.y * p1.z, -(p1.x * p2.z - p2.x * p1.z), p1.x * p2.y - p2.x * p1.y);
  }

  struct Line {
    Point a, b, dis;
    Line() {}
    Line(const Point &_a, const Point &_b) : a(_a), b(_b), dis(b - a) {}
    void input(){
      a.input();
      b.input();
      *this = Line(a,b);
    }
    double dist2() {
      const double X = this->a.x - this->b.x;
      const double Y = this->a.y - this->b.y;
      const double Z = this->a.z - this->b.z;
      return X * X + Y * Y + Z * Z;
    }
    double dist() {
      return sqrt(this->dist2());
    }
  };
  using Segment = Line;

  double distanceLineToPoint(Line &l, Point &p) {
    return cross(l.dis, p - l.a).distance() / l.dis.distance();
  }

  double distanceSegmentToPoint(Segment &l, Point &p) {
    if (dot(l.b - l.a, p - l.a) < 0) {
      auto buf = p - l.a;
      return buf.distance();
    }
    if (dot(l.a - l.b, p - l.b) < 0) {
      auto buf = p - l.b;
      return buf.distance();
    }
    return distanceLineToPoint(l, p);
  }

  struct Ball {
    Point center;
    double r;
    Ball() {}
    Ball(double _x, double _y, double _z, double _r) : center(_x, _y, _z), r(_r) {}
    Ball(const Point &_c, double _r) : center(_c), r(_r) {}
    void input(){
      center.input();
      cin >> r;
    }
    bool inside(const Point &p) {
      const double X = p.x - this->center.x;
      const double Y = p.y - this->center.y;
      const double Z = p.z - this->center.z;
      return sgn(X * X + Y * Y + Z * Z, -(this->r * this->r)) == -1;
    }
    bool inside(Segment &s) {
      return sgn(distanceSegmentToPoint(s, this->center) - this->r) == -1;
    }
    bool on_surface(const Point &p) {
      const double X = p.x - this->center.x;
      const double Y = p.y - this->center.y;
      const double Z = p.z - this->center.z;
      return sgn(X * X + Y * Y + Z * Z, -(this->r * this->r)) == 0;
    }
    bool on_surface(Segment &s) {
      return sgn(distanceSegmentToPoint(s, this->center) - this->r) == 0;
    }
  };
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
    double x,y;
    int i;
  };

  vector<datas> d ;
  bool sortys(const datas& a,const datas& b){
    return a.y < b.y;
  }
  bool sortx(const datas& a,const datas& b){
    return a.x < b.x;
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
          nth_element(first, nth, last, sortys);
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
      void query(int l,int r,int depth,double sx,double sy,double tx,double ty, vector<int>& idxs){
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
      double distance(const datas &a,const datas &b){
        return sqrt((a.x - b.x) * (a.x - b.x)+ (a.y - b.y) * (a.y - b.y));
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
        x2[i] = find(all(xs),x2[i])-xs.begin();
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
  const int mod = 1e9+7;
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
      fact[i] = (fact[i-1]*i) % mod;
    }
    revfact[N-1] = powmod(fact[N-1],mod-2);//逆元を求める
    for(int i = N-2;i >= 0;--i){
      revfact[i] = (revfact[i+1] * (i+1)) % mod;
    }
  }

  ll getP(int a,int b){
    return (fact[a] * revfact[b]) % mod;
  }

  ll getC(int a, int b){
    return (fact[a] * revfact[b] % mod) * revfact[a-b] % mod;
  }

  ll mod_add(ll a, ll b) {
    return (a + b) % mod;
  }

  ll mod_sub(ll a, ll b) {
    return (a - b + mod) % mod;
  }

  ll mod_mul(ll a, ll b) {
    return a*b % mod;
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
long long C[1010][1010];

void make_C(){
  memset(C, 0, (int)sizeof(C));
  for(int i = 0; i < 1010; i++){
    C[i][0] = C[i][i] = 1;
    for(int j = 1; j < i; j++) C[i][j] = (C[i-1][j-1] + C[i-1][j]) % mod;
  }
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  return 0;
}
