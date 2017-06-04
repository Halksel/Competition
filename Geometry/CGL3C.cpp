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
    return 0; // a--c--b on line
  }
  // L:line,S:segment,P:point
  P crosspoint(const L &l, const L &m) {
    double A = cross(l[1] - l[0], m[1] - m[0]);
    double B = cross(l[1] - l[0], l[1] - m[0]);
    if (abs(A) < EPS && abs(B) < EPS) return m[0]; // same line
    if (abs(A) < EPS) assert(false); // !!!PRECONDITION NOT SATISFIED!!!
    return m[0] + B / A * (m[1] - m[0]);
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
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll n;
  double x,y;
  cin >> n;
  G g;
  rep(i,n){
    cin >> x >> y;
    g.push_back({x,y});
  }
  ll q;
  cin >> q;
  rep(i,q){
    cin >> x >> y;
    std::cout << convex_point(g,P(x,y)) << std::endl;
  }
  return 0;
}
