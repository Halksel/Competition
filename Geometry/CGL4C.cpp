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
constexpr double PI = acos(-1.0) ;
double eps = 1e-10 ;
const int dy[] = {-1,0,1,0,1,-1,1,-1};
const int dx[] = {0,-1,0,1,1,-1,-1,1};

int ans = 0;
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
P crosspoint(const L &l1,const L &l2) {
    return l1[0] + (l1[1] - l1[0]) * cross(l2[1]-l2[0], l2[0] - l1[0]) / cross(l2[1]-l2[0], l1[1]-l1[0]);
}
double calc_triangle(P a,P b,P c){
  P ba = (b - a);
  P ca = (c - a);
  return (real(ba) * imag(ca) - imag(ba) * real(ca))/2.0;
}
double calc_area(const G &g){
  double res = 0;
  if(g.size() < 3) return 0;
  rep(i,g.size()-2){
    res += calc_triangle(g[0],g[(i+1) % g.size()],g[(i+2) % g.size()]);
  }
  return res;
}
#define here(g, i) g[i]
#define next(g, i) g[(i + 1) % g.size()]
#define prev(g, i) g[(i - 1 + g.size()) % g.size()]
G convex_cut(G &g, L &l) {
    G h;
    rep(i, (int)g.size()) {
        P p = here(g, i), q = next(g, i);
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

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll n;
  double x,y;
  cin >> n;
  vector<P> v(n);
  rep(i,n){
    cin >> x >> y;
    v[i] = P{x,y};
  }
  /* std::cout << crosspoint(L(v[0],v[1]),L(P(-1,0),P(2,0))) << std::endl; */
  ll q;
  cin >> q;
  rep(i,q){
    cin >> x >> y;
    P a = P(x,y);
    cin >> x >> y;
    P b = P(x,y);
    L ab(a,b);
    auto res = convex_cut(v,ab);
    fcout(10) << calc_area(res) << endl;
  }
  return 0;
}
