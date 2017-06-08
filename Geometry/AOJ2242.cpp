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

template<typename T>
void O(T t){
  cout << t << endl;
}

const ll mod = 1e9+7;
constexpr ll inf = ((1<<30)-1)*2+1 ;

const double EPS = 1e-8;
const double INF = 1e12;
const double PI = acos(-1);
typedef complex<double> P;//複素数を平面における点と解釈
namespace std {
  bool EQ(double a, double b) {
    return abs(a - b) < EPS;
  }
  bool operator < (const P& a, const P& b) {//x軸を優先
    return real(a) != real(b) ? real(a) < real(b) : imag(a) < imag(b);
  }
  bool sorty(const P& a, const P& b) {//y軸を優先
    return imag(a) != imag(b) ? imag(a) < imag(b) : real(a) < real(b);
  }
  bool same(const P& a, const P& b) {
    return EQ(a.real(), b.real()) && EQ(a.imag(), b.imag());
  }
}
double cross(const P& a, const P& b) {//外積
  return imag(conj(a)*b);
}
double dot(const P& a, const P& b) {//内積
  return real(conj(a)*b);
}

struct L : public vector<P> {//直線
  L(){};
  L(const P &a, const P &b) {
    push_back(a); push_back(b);
  }
};

typedef vector<P> G;

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
int linejudge(const L &ab,const L &cd){ //2直線間の関係
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
// Lに対するPの反射点
P reflection(const L &l, const P &p) {
  return p + 2.0 * (projection(l, p) - p);
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
  return min(min(distanceSP(s, t[0]), distanceSP(s, t[1])), min(distanceSP(t, s[0]), distanceSP(t, s[1])));
}
double distancePP(const P &p,const P &q){
  return abs(p - q) ;
}
P crosspoint(const L &l, const L &m) {
  double A = cross(l[1] - l[0], m[1] - m[0]);
  double B = cross(l[1] - l[0], l[1] - m[0]);
  if (abs(A) < EPS && abs(B) < EPS) return m[0]; // same line
  if (abs(A) < EPS) assert(false); // !!!PRECONDITION NOT SATISFIED!!!
  return m[0] + B / A * (m[1] - m[0]);
}
P verticalvector(const P &a,const P &b){//2点の単位法線ベクトルを返す
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
#define curr(P, i) P[i]
#define next(P, i) P[(i+1)%P.size()]
#define diff(P, i) (next(P, i) - curr(P, i))
G convex_cut(G &g, L &l) {
  G h;
  rep(i, (int)g.size()) {
    P p = curr(g, i), q = next(g, i);
    if (ccw(p, q, l[0]) == 0 && ccw(p, q, l[1]) == 0) {
      if (ccw(p, l[1], l[0]) == 0) return g;    // p -- l.a -- l.b -- q
      else return G{};                        // p -- l.b -- l.a -- q
    }
    if (ccw(l[0], l[1], p) != -1) h.emplace_back(p);
    if (ccw(l[0], l[1], p) * ccw(l[0], l[1], q) < 0)
      h.emplace_back(crosspoint(L(p, q), l));
  }
  return h;
}
P center(const G &g){
  int n = g.size();
  P p(0,0);
  rep(i,n){
    p = p + g[i];
  }
  return p / (1.0 * n);
}
P rotP(P p, P q, double theta) {
    p -= q;
    double x = p.real(), y = p.imag();
    p = P(x * cos(theta) - y * sin(theta), x * sin(theta) + y * cos(theta));
    p += q;
    return p;
}

G rotG(G g, P &p, double theta) {
    rep(i, g.size()) {
        g[i] = rotP(g[i], p, theta);
    }
    return g;
}
bool EqG(G &g, G &h) {
    if (g.size() != h.size()) return false;
    rep(k, g.size()) {
        bool flag = true;
        rep(i, g.size()) {
            if (!same(g[(i + k) % g.size()], h[i])) {
                flag = false;
                break;
            }
        }
        if (flag) {
            return true;
        }
    }
    return false;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll n;
  cin >> n;
  G g;
  double x,y;
  rep(i,n){
    cin >> x >> y;
    g.push_back(P(x,y));
  }
  P gp = center(g);
  G h = rotG(g, gp, PI);
  if(EqG(g,h))
    fcout(10) << real(gp) << ' ' << imag(gp) << endl;
  else
    cout << "NA" << endl;
  return 0;
}
