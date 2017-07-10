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
    void input() {
      double a, b,c,d;
      cin >> a >> b >> c >> d;
      l.clear();
      l.push_back(P(a,b)),l.push_back(P(c,d));
    }
};

/* typedef vector<P> G; */

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
    void push_back(P p){
      g.push_back(p);
    }
    P& operator[](int i){
      return g[i];
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
int convex_point(G &g,P &p){
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

ll n,u;
int S,E;
double t,p;
vector<ll> h;
vector<G> g,sg;

P projection(P a,ll h){
  // tan p = (h/t)
  double w = h / tan(p); 
  P p = a - P(cos(t) * w,sin(t) * w);
  return p;
}

void shadow(){
  rep(i,n){
    vector<P> ps;
    ll S = g[i].size();
    rep(j,S){
      g[i].push_back(projection(g[i][j],h[i]));
    }
    sg[i] = G(convex_hull(g[i].g));
  }        
}
const int M = 103;
double dis[M][M] = {};
void warshall(){
  ll u = n+2;
  rep(i,n){
    rep(j,n){
      dis[i][j] = distance(sg[i],sg[j]);
    }
  }
  rep(k,u){
    rep(i,u){
      rep(j,u){
        dis[i][j] = min(dis[i][j],dis[i][k] + dis[k][j]);
      }
    }
  }
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  while(cin >> n,n){
    g.resize(n);
    sg.resize(n);
    h.resize(n);
    rep(i,M){
      rep(j,M){
        dis[i][j] = 1e9;
      }
    }
    rep(i,n){
      cin >> u;
      cin >> h[i];
      g[i] = G(u);
    }
    cin >> t >> p;
    t = d2r(t);
    p = d2r(p);
    shadow();
    P s,e;
    s = inputP();
    e = inputP();
    rep(i,n){
      dis[n][i] = dis[i][n] = distance(sg[i],s);
      dis[n+1][i] = dis[i][n+1] = distance(sg[i],e);
    }
    dis[n][n+1] = dis[n+1][n] = distancePP(s,e);
    warshall();
    std::fcout(10) << dis[n][n+1] << std::endl;
  }
  return 0;
}
