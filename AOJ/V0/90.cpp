#include <bits/stdc++.h>
using namespace std ;

#define pb(n) push_back(n)
#define mp(a,b) make_pair(a,b)
#define fi first
#define se second
#define np string::npos
#define X real()
#define Y imag()
#define value(x,y,w,h) (x >= 0 && x < w && y >= 0 && y < h)
#define all(r) (r).begin(),(r).end()
#define gsort(st,en) sort((st),(en),greater<int>())
#define vmax(ary) *max_element(all(ary))
#define vmin(ary) *min_element(all(ary))
#define debug(x) cout<<#x<<": "<<x<<endl
#define fcout(n) cout<<fixed<<setprecision((n))
#define scout(n) cout<<setw(n)

#define rep(i,n) for(int i = 0; i < (int)(n);++i)
#define REP(i,a,b) for(int i = (a);i < (int)(b);++i)
#define repi(it,array) for(auto it = array.begin(),end = array.end(); it != end;++it)
#define repa(n,array) for(auto &n :(array))

typedef long long ll ;
typedef deque<int> di ;
typedef deque<ll> dl ;
typedef map<string,int> dict;
typedef complex<double> comd;
typedef pair<int,int> pii;

constexpr int imax = ((1<<30)-1)*2+1 ;
constexpr int inf = 100000000;
constexpr double PI = acos(-1.0) ;
double eps = 1e-10 ;
const int dy[] = {-1,0,1,0};
const int dx[] = {0,-1,0,1};

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
// L:line,S:segment,P:point
bool in_field(double x,double y,double x1,double y1,P p){
  return x <= real(p) && real(p) <= x1 && y <= imag(p) && imag(p) <= y1;
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
int n;
C ps[100];
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  char c;
  while(1){
    cin >> n;
    if(n == 0){
      break;
    }
    double x,y;
    rep(i,n){
      cin >> x >> c >> y ;
      ps[i] = {P(x,y),1.0};
    }
    int ans = 1,resa=0,resb = 0;
    rep(i,n){
      REP(j,i+1,n){
        if(distancePP(ps[i].p,ps[j].p) >= 2.0){
          continue ;
        }
        else{
          auto ab = crosspointCircle(ps[i],ps[j]);
          P a = ab.first,b = ab.second;
          resa = 0;
          resb = 0;
          rep(k,n){
            if(distancePP(ps[k].p,a) <= 1.0 + EPS){
              ++resa;
            }
          }
          rep(k,n){
            if(distancePP(ps[k].p,b) <= 1.0 + EPS){
              ++resb;
            }
          }
        }
        ans = max(ans,max(resa,resb));
      }
    }
    std::cout << ans << std::endl;
  }
  return 0;
}
