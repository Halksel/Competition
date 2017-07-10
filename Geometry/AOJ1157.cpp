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

double add(double a, double b) {
  if (abs(a + b) < EPS * (abs(a) + abs(b))) return 0;
  return a + b;
}
inline int sgn(double a, double b = 0) { return a < b - EPS ? -1 : a > b + EPS ? 1 : 0; }

#define curr(P, i) P[i]
#define next(P, i) P[(i+1)%P.size()]
#define diff(P, i) (next(P, i) - curr(P, i))
typedef complex<double> P;//複素数を平面における点と解釈
P inputP(){
  double x,y;
  cin >> x >> y;
  return P(x,y);
}
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
bool intersectSS( L s,  L t) {
  return ccw(s[0],s[1],t[0])*ccw(s[0],s[1],t[1]) <= 0 &&
    ccw(t[0],t[1],s[0])*ccw(t[0],t[1],s[1]) <= 0;
}
bool intersectSP( L &s,  P &p) {
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
P projection(L &l,  P &p) {
  double t = dot(p-l[0], l[0]-l[1]) / norm(l[0]-l[1]);
  return l[0] + t*(l[0]-l[1]);
}
// Lに対するPの反射点
P reflection(L &l,  P &p) {
  return p + 2.0 * (projection(l, p) - p);
}
double distanceLP(L &l,  P &p) {
  return abs(p - projection(l, p));
}
double distanceLL(L &l,  L &m) {
  return intersectLL(l, m) ? 0 : distanceLP(l, m[0]);
}
double distanceLS(L &l,  L &s) {
  if (intersectLS(l, s)) return 0;
  return min(distanceLP(l, s[0]), distanceLP(l, s[1]));
}
double distanceSP(L &s,  P &p) {
  P r = projection(s, p);
  if (intersectSP(s, r)) return abs(r - p);
  return min(abs(s[0] - p), abs(s[1] - p));
}
double distanceSS(L s,  L t) {
  if (intersectSS(s, t)) return 0;
  return min(min(distanceSP(s, t[0]), distanceSP(s, t[1])), min(distanceSP(t, s[0]), distanceSP(t, s[1])));
}
double distancePP(P &p, P &q){
  return abs(p - q) ;
}

double distanceSG(L l, G g) {
  double d = INF;
  rep(i, g.size()) {
    d = min(d, distanceSS(l, L(curr(g, i), next(g, i))));
  }
  return d;
}

bool in(double a,double b,double c){
  return a <= b && b <= c;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll n;
  while(cin >> n,n){
    L l;
    l.input();
    vector<G> rs(n);
    vector<ll> h(n);
    bool f = true;
    rep(i,n){
      double a,b,c,d;
      cin >> a >> b >> c >> d >> h[i];
      rs[i].push_back(P(a,b));
      rs[i].push_back(P(c,b));
      rs[i].push_back(P(c,d));
      rs[i].push_back(P(a,d));
      if(in(a,real(l[0]),c) && in(b,imag(l[0]),d) && in(a,real(l[1]),c)&& in(b,imag(l[1]),d) ){
        f = false; 
      } 
    }
    if(!f){
      cout << 0 << endl;
      continue;
    }
    auto check = [&](double r){
      rep(i,n){
        rep(j,4){
          double d = distanceSG(l,rs[i]);
          if(d < r && r < h[i]) return true;
          else if(h[i] > r - sqrt(r * r - d * d)) return true;
        }
      }
      return false;
    };
    double lb = 0,ub = 1001;
    rep(i,100){
      double r = (lb+ub)/2;
      bool f = check(r);
      if(f){
        ub = r; 
      }
      else{
        lb = r;
      }
    }
    fcout(10) << lb << endl;
  }
  return 0;
}
