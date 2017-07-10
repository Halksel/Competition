//reference to
//http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=2243124#1

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

#define curr(P, i) P[i]
#define next(P, i) P[(i+1)%P.size()]
#define diff(P, i) (next(P, i) - curr(P, i))
const double EPS = 1e-8;
const double INF = 1e12;
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
vector<P> crosspoint(const C &a,const C &b){
  vector<P> res;
  double d = abs(a.p - b.p);
  double rc = (d * d + a.r * a.r - b.r * b.r) / (2 * d);
  double dfr = a.r * a.r - rc * rc;
  if (abs(dfr) < eps) dfr = 0.0;
  else if (dfr < 0.0) return res;
  double rs = sqrt(dfr);
  P diff = (b.p - a.p) / d;
  res.push_back(a.p + diff * P(rc, rs));
  if (dfr != 0.0) res.push_back(a.p + diff * P(rc, -rs));
  return res;
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
ll n;
using pd = pair<P,double>;
vector<pd> v;

P interDiv(P p,P q,double a,double b){
  return ((p * b + q * a)/(a+b));
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  while(cin >> n,n){
    v.resize(n);
    rep(i,n){
      ll k;
      P p = inputP();
      cin >> k;
      v[i] = mp(p,k);
    }
    auto check = [&](double h){
      vector<double> rs(n);
      rep(i,n){
        double r = v[i].se * v[i].se - h * h;
        if(r < 0) return false;
        rs[i] = sqrt(r);
      }
      vector<C> cs;
      rep(i,n){
        cs.pb(C(v[i].fi,rs[i]));
      }
      vector<P> kh;
      rep(i,n){
        kh.pb(cs[i].p);
      }
      rep(i,n){
        REP(j,i+1,n){
          auto vs = crosspoint(cs[i],cs[j]);
          for(auto &u : vs){
            kh.pb(u);
          }
        }
      }
      for(auto &p : kh){
        bool f = true;
        rep(i,n){
          if(abs(p - v[i].fi) > rs[i] + EPS){
            f = false;
            break;
          }
        }
        if(f) return true;
      }
      return false;
    };
    double lb = 0,ub = 1000.0;
    rep(i,100){
      double h = (lb+ub)/2;
      if(check(h)){
        lb = h;
      }
      else
        ub = h;
    }
    std::fcout(10) << ub << std::endl;
  }
  return 0;
}
