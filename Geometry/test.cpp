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

const double EPS = 1e-8;
const double INF = 1e12;
typedef complex<double> P;//複素数を平面における点と解釈
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
    void readL() {
      double a, b,c,d;
      cin >> a >> b >> c >> d;
      l.clear();
      l.push_back(P(a,b)),l.push_back(P(c,d));
    }
};

typedef vector<P> G;
G readG(int n){
  double x,y;
  G g;
  rep(i,n){
    cin >> x >> y;
    g.push_back(P(x,y));
  }
  return g;
}

struct C {//円
  P p; double r;
  C(){};
  C(const P &p, double r) : p(p), r(r) { }
};
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
bool intersectLL( L &l,  L &m) {
  return abs(cross(l[1]-l[0], m[1]-m[0])) > EPS || // non-parallel
    abs(cross(l[1]-l[0], m[0]-l[0])) < EPS;   // same line
}
bool intersectLS( L &l,  L &s) {
  return cross(l[1]-l[0], s[0]-l[0])*       // s[0] is left of l
    cross(l[1]-l[0], s[1]-l[0]) < EPS; // s[1] is right of l
}
bool intersectLP( L &l,  P &p) {
  return abs(cross(l[1]-p, l[0]-p)) < EPS;
}
bool intersectSS( L &s,  L &t) {
  return ccw(s[0],s[1],t[0])*ccw(s[0],s[1],t[1]) <= 0 &&
    ccw(t[0],t[1],s[0])*ccw(t[0],t[1],s[1]) <= 0;
}
bool intersectSP( L &s,  P &p) {
  return abs(s[0]-p)+abs(s[1]-p)-abs(s[1]-s[0]) < EPS; // triangle inequality
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
double distanceLP( L &l,  P &p) {
  return abs(p - projection(l, p));
}
double distanceLL( L &l,  L &m) {
  return intersectLL(l, m) ? 0 : distanceLP(l, m[0]);
}
double distanceLS( L &l,  L &s) {
  if (intersectLS(l, s)) return 0;
  return min(distanceLP(l, s[0]), distanceLP(l, s[1]));
}
double distanceSP( L &s,  P &p) {
  P r = projection(s, p);
  if (intersectSP(s, r)) return abs(r - p);
  return min(abs(s[0] - p), abs(s[1] - p));
}
double distanceSS( L &s,  L &t) {
  if (intersectSS(s, t)) return 0;
  return min(min(distanceSP(s, t[0]), distanceSP(s, t[1])), min(distanceSP(t, s[0]), distanceSP(t, s[1])));
}
double distancePP( P &p, P &q){
  return abs(p - q) ;
}
P crosspoint(L &l,L &m) {
  double A = cross(l[1] - l[0], m[1] - m[0]);
  double B = cross(l[1] - l[0], l[1] - m[0]);
  if (abs(A) < EPS && abs(B) < EPS) return m[0]; // same line
  if (abs(A) < EPS) assert(false); // !!!PRECONDITION NOT SATISFIED!!!
  return m[0] + B / A * (m[1] - m[0]);
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
double calc_area(const G &g){
  double res = 0;
  rep(i,g.size()-2){
    res += calc_triangle(g[0],g[(i+1) % g.size()],g[(i+2) % g.size()]);
  }
  return res;
}
bool is_convex(const G &g){
  if(g.size() == 3) return true;
  rep(i,g.size()){
    if(ccw(g[i],g[(i+1) % g.size()],g[(i+2) % g.size()]) != 1 && ccw(g[i],g[(i+1) % g.size()],g[(i+2) % g.size()]) != -2){
      return false;
    }
  }
  return true;
}
int convex_point(const G &g,const P &p){
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
#define curr(P, i) P[i]
#define next(P, i) P[(i+1)%P.size()]
#define diff(P, i) (next(P, i) - curr(P, i))
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
    if (ccw(l[0], l[1], p) != -1) h.emplace_back(p);
    if (ccw(l[0], l[1], p) * ccw(l[0], l[1], q) < 0){
      L t = L(p,q);
      h.emplace_back(crosspoint(t, l));
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

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  return 0;
}
