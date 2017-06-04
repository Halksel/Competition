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
  pair<P,P> crosspointCircle(const C &a,const C &b){
    P m = (a.p+b.p)/2.0;
    P vv = verticalvector(a.p,b.p);
    double u = sqrt( a.r * a.r - norm(a.p - b.p) / 4.0);
    P A = m + u * vv,B = m - u * vv;
    return mp(A,B);
  }

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  double x,y;
  cin >> x >> y;
  P a(x,y);
  cin >> x >> y;
  P b(x,y);
  L ab(a,b);
  ll q;
  cin >> q;
  rep(i,q){
    cin >> x >> y;
    P c(x,y);
    P d = reflection(ab,c);
    fcout(10) << real(d) << ' ' << imag(d) << endl;
  }
  return 0;
}
