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

const double EPS = 1e-10;
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

class L{
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
bool intersectSS(L &s,L &t) {
  return ccw(s[0],s[1],t[0])*ccw(s[0],s[1],t[1]) < 0 &&
    ccw(t[0],t[1],s[0])*ccw(t[0],t[1],s[1]) < 0;
}
P crosspointSS(L &l1,L &l2) {
  double d1 = abs(cross(l2.v, l1[0] - l2[0])); // l1.a - l2.b???
  double d2 = abs(cross(l2.v, l1[1] - l2[0]));
  double t = d1 / (d1 + d2);
  return l1[0] + t * l1.v;
}
G readG(int n){
  double x,y;
  G g;
  rep(i,n){
    cin >> x >> y;
    g.push_back(P(x,y));
  }
  return g;
}
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll n;
  G g;
  g.push_back(P(-100,-100));
  g.push_back(P(100,-100));
  g.push_back(P(100,100));
  g.push_back(P(-100,100));
  while(cin >> n && n){
    ll cnt = 1;
    vector<L> v(n);
    rep(i,n){
      v[i].readL();
      ll c = 0;
      vector<P> ps;
      rep(j,i){
        if(intersectSS(v[i],v[j]))
          ps.emplace_back(crosspointSS(v[i],v[j]));
      }
      c = 0;
      rep(k,ps.size()){
        bool f = true;
        rep(j,k){
          if(same(ps[j],ps[k])){
            f = false;
            break;
          }
        }
        c += f;
      }
      cnt += c + 1;
    }
    cout << cnt << endl;
  }
  return 0;
}
