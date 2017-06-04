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
  pair<P,P> crosspointCircle(const C &a,const C &b){
    P m = (a.p+b.p)/2.0;
    P vv = verticalvector(a.p,b.p);
    double u = sqrt( a.r * a.r - norm(a.p - b.p) / 4.0);
    P A = m + u * vv,B = m - u * vv;
    return mp(A,B);
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
      if (ccw(l[0], l[1], p) * ccw(l[0], l[1], q) < 0)
        h.emplace_back(crosspoint(L(p, q), l));
    }
    return h;
  }
  double closestPair_calc(P *p,int n){
    if(n < 2) return inf;
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
    return ans == inf ? 0.0 : ans;
  }
  P unit(const L &l){
    P p = l[1] - l[0];
    return p/abs(p);
  }
  P unit(const P &a,const P &b){
    P p = b - a;
    return p/abs(p);
  }
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll n;
  cin >> n;
  vector<L> lx,ly;
  double x,y;
  L xp = L(P(0,0),P(1,0));
  L yp = L(P(0,0),P(0,1));
  rep(i,n){
    cin >> x >> y;
    P a(x,y);
    cin >> x >> y;
    P b(x,y);
    if(b < a) swap(a,b);
    L l(a,b);
    if(linejudge(l,xp) == 2){
      lx.emplace_back(l);
    }
    else{
      ly.emplace_back(l);
    }
  }
  sort(all(lx));
  sort(all(ly));
  ll cnt = 0;
  rep(i,lx.size()){
    int l = 0,r = ly.size(),tl,tr;
    double x1 = real(lx[i][0]),x2 = real(lx[i][1]);
    rep(j,100){
      int m = (l+r)/2;
      if(real(ly[m][0]) < x1){
        l = m;
      }
      else{
        r = m;
      }
    }
    tl = l;
    l = 0,r = ly.size();
    rep(j,100){
      int m = (l+r)/2;
      if(real(ly[m][0]) > x2){
        r = m;
      }
      else{
        l = m;
      }
    }
    tr = r;
    /* cout << endl;                                          */
    /* std::cout << lx[i][0] << ' ' << lx[i][1] << std::endl; */
    /* cout << endl;                                          */
    REP(j,tl,tr){
      /* std::cout << ly[j][0] << ' ' << ly[j][1]; */
      if(intersectSS(lx[i],ly[j])){
        ++cnt;
        /* cout << 'o'; */
      }
      /* cout << endl; */
    }
  }
  cout << cnt << endl;
  return 0;
}
