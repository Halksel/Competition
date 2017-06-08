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
const double EPS = 1e-6;
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


int ccw(P a, P b, P c) {//3点がどの順番で並んでいるかの判定
  b -= a; c -= a;
  if (cross(b, c) > 0)   return +1;       // counter clockwise
  if (cross(b, c) < 0)   return -1;       // clockwise
  if (dot(b, c) < 0)     return +2;       // c--a--b on line
  if (norm(b) < norm(c)) return -2;       // a--b--c on line
  return 0; // a--c--b on line
}
// L:line,S:segment,P:point
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
const double PI = acos(-1);
double d2r(int d){
  return (1.0 * d/180)*PI;
}

class star{
  public:
    P p[5],c;
    L l[5];
    star(){};
    star(double x,double y,int a,double r){
      int d = a + 90;
      c = P(x,y);
      rep(i,5){
        p[i] = c + polar(r,d2r(d));
        d += 72;
      }
      rep(i,5){
        l[i] = L(p[i],p[(i+2)%5]);
      }
    }
    P& operator[](int i){
      return p[i];
    }
    bool operator<(const star &s) const {
      return c < s.c;
    }
    void show(){
      rep(i,5){
        cout << p[i] << endl;
      }
      cout << endl;
    }
};
double distanceStar(star &s, star &t){
  double res = INF;
  rep(i,5){
    rep(j,5){
      res = min(res,distanceSS(s.l[i],t.l[j]));
    }
  }
  return res;
}

double dis[101][101];
double ans[101][101];

void warshall(int n){
  rep(k,n){
    rep(i,n){
      rep(j,n){
        dis[i][j] = min(dis[i][j],dis[i][k] + dis[k][j]);
      }
    }
  } 
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n,m,l;
  while(cin >> n >> m >> l,n+m+l){
    --l,--m;
    vector<pair<star,int>> vs(n);
    double x,y,b,r;
    rep(i,n){
      cin >> x >> y >> b >> r;
      vs[i] = mp(star(x,y,b,r),i);
    }
    REP(i,0,n){
      rep(j,n){
        dis[i][j] = distanceStar(vs[i].fi,vs[j].fi);
      }
    }
    warshall(n);
    fcout(10) << dis[l][m] << endl;
  }
  return 0;
}
