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

const int mod = 1000000007;
constexpr ll inf = ((1<<30)-1)*2+1 ;
constexpr double PI = acos(-1.0) ;
double eps = 1e-10 ;
const int dy[] = {-1,0,1,0,1,-1,1,-1};
const int dx[] = {0,-1,0,1,1,-1,-1,1};

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
  C(const P &p, double r) : p(p), r(r) { };
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
  return abs(cross(l[1]-l[0], m[1]-m[0])) > EPS || abs(cross(l[1]-l[0], m[0]-l[0])) < EPS;   // same line
}
bool intersectLS(const L &l, const L &s) {
  return cross(l[1]-l[0], s[0]-l[0])*cross(l[1]-l[0], s[1]-l[0]) < EPS; // s[1] is right of l
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
  return min(min(distanceSP(s, t[0]), distanceSP(s, t[1])),min(distanceSP(t, s[0]), distanceSP(t, s[1])));
}
P crosspoint(const L &l, const L &m) {
  double A = cross(l[1] - l[0], m[1] - m[0]);
  double B = cross(l[1] - l[0], l[1] - m[0]);
  if (abs(A) < EPS && abs(B) < EPS) return m[0]; // same line
  if (abs(A) < EPS) assert(false); // !!!PRECONDITION NOT SATISFIED!!!
  return m[0] + B / A * (m[1] - m[0]);
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll n;
  while(cin >> n && n){
    vector<C> w(n);
    double a,b,r;
    double c,d;
    rep(i,n){
      cin >> a >> b >> r;
      w[i] = C(P(a,b),r);
    }
    ll m;
    cin >> m;
    vector<L> l(m);
    rep(i,m){
      cin >> a >> b >> c >> d;
      l[i] = L(P(a,b),P(c,d));
    }
    rep(i,m){
      bool ans = false;
      rep(j,n){
        if(w[j].r >= distanceSP(l[i],w[j].p)){
          ans = true;
        }
      }
      cout << ((ans) ? "Safe" : "Danger") << endl;
    }
  }
  return 0;
}

