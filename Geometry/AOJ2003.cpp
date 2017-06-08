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
// a < b : -1, a > b : 1, a == b : 0
inline int sgn(double a, double b = 0) { return a < b - EPS ? -1 : a > b + EPS ? 1 : 0; }
P crosspointSS(L &l1,L &l2) {
  double d1 = abs(cross(l2.v, l1[0] - l2[0])); // l1.a - l2.b???
  double d2 = abs(cross(l2.v, l1[1] - l2[0]));
  double t = d1 / (d1 + d2);
  return l1[0] + t * l1.v;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll n,m,x,y,x2,y2;
  cin >> n;
  int o,h;
  rep(i,n){
    cin >> x >> y >> x2 >> y2;
    P a(x,y),b(x2,y2);
    L l(a,b);
    if(b < a) l = L(b,a);
    cin >> m;
    vector<pair<P,pair<int,int>>> ab;//a[i](crosspoint,h)
    rep(j,m){
      cin >> x >> y >> x2 >> y2;
      P a(x,y),b(x2,y2);
      L t(a,b);
      if(b < a) t = L(b,a);
      cin >> o >> h;
      if(intersectSS(l,t)){
        P p = crosspointSS(l,t);
        ab.push_back(mp(p,mp(o,h)));
      }
    }
    sort(all(ab));
    int cnt = 0;
    if(ab.size()){
      int s = 0;
      if(ab[0].se.se){
        s = ab[0].se.fi;
      }
      else{
        s = !ab[0].se.fi;
      }
      REP(u,1,ab.size()){
        o = ab[u].se.fi,h = ab[u].se.se;
        if(o && s != h){
          ++cnt;
          s = h;
        }
        else if(!o && s == h){
          ++cnt;
          s = !h;
        }
      }
    }
    cout << cnt << endl;
    // 最初に全直線と路線との交差判定を行う
    // もし始点と路線との交点の距離が最小のものが、自分なら地下高架を合わせて、そうじゃないなら逆
    // そこからライバル路線とぶつかるたびに、h = !h、ans++
    // 自社路線とぶつかるたび
  }
  return 0;
}
