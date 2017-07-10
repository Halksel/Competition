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

const ll mod = 1e9+7;
constexpr double PI = acos(-1.0) ;
double eps = 1e-10 ;

const long double EPS = 1e-10;
double add(double a, double b) {
  if (abs(a + b) < EPS * (abs(a) + abs(b))) return 0;
  return a + b;
}
int sgn(double a, double b = 0.0) {// sign function
  return a < b - EPS ? -1 : a > b + EPS ? 1 : 0;
}

struct Point {
  double x, y, z;
  Point() {}
  Point(double _x, double _y, double _z) : x(_x), y(_y), z(_z) {}
  void input(){
    cin >> x >> y >> z;
  }
  const Point operator+ (const Point &p) {
    return Point(add(this->x, p.x), add(this->y, p.y), add(this->z, p.z));
  }
  const Point operator- (const Point &p) {
    return Point(add(this->x, -p.x), add(this->y, -p.y), add(this->z, -p.z));
  }
  const Point operator* (double d) {
    return Point(this->x * d, this->y * d, this->z * d);
  }
  double norm() {
    return this->x * this->x + this->y * this->y + this->z * this->z;
  }
  double distance() {
    return sqrt(this->norm());
  }
};

double dot(const Point &p1, const Point &p2) {
  return p1.x * p2.x + p1.y * p2.y + p1.z * p2.z;
}
Point cross(const Point &p1, const Point &p2) {
  return Point(p1.y * p2.z - p2.y * p1.z, -(p1.x * p2.z - p2.x * p1.z), p1.x * p2.y - p2.x * p1.y);
}

struct Line {
  Point a, b, dis;
  Line() {}
  Line(const Point &_a, const Point &_b) : a(_a), b(_b), dis(b - a) {}
  void input(){
    a.input();
    b.input();
    *this = Line(a,b);
  }
  double dist2() {
    const double X = this->a.x - this->b.x;
    const double Y = this->a.y - this->b.y;
    const double Z = this->a.z - this->b.z;
    return X * X + Y * Y + Z * Z;
  }
  double dist() {
    return sqrt(this->dist2());
  }
};
using Segment = Line;

double distanceLineToPoint(Line &l, Point &p) {
  return cross(l.dis, p - l.a).distance() / l.dis.distance();
}

double distanceSegmentToPoint(Segment &l, Point &p) {
  if (dot(l.b - l.a, p - l.a) < 0) {
    auto buf = p - l.a;
    return buf.distance();
  }
  if (dot(l.a - l.b, p - l.b) < 0) {
    auto buf = p - l.b;
    return buf.distance();
  }
  return distanceLineToPoint(l, p);
}

struct Ball {
  Point center;
  double r;
  Ball() {}
  Ball(double _x, double _y, double _z, double _r) : center(_x, _y, _z), r(_r) {}
  Ball(const Point &_c, double _r) : center(_c), r(_r) {}
  void input(){
    center.input();
    cin >> r;
  }
  bool inside(const Point &p) {
    const double X = p.x - this->center.x;
    const double Y = p.y - this->center.y;
    const double Z = p.z - this->center.z;
    return sgn(X * X + Y * Y + Z * Z, -(this->r * this->r)) == -1;
  }
  bool inside(Segment &s) {
    return sgn(distanceSegmentToPoint(s, this->center) - this->r) == -1;
  }
  bool on_surface(const Point &p) {
    const double X = p.x - this->center.x;
    const double Y = p.y - this->center.y;
    const double Z = p.z - this->center.z;
    return sgn(X * X + Y * Y + Z * Z, -(this->r * this->r)) == 0;
  }
  bool on_surface(Segment &s) {
    return sgn(distanceSegmentToPoint(s, this->center) - this->r) == 0;
  }
};

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll n,q;
  cin >> n >> q;
  vector<pair<Ball,ll>> ball(n);
  double x,y,z,r;
  rep(i,n){
    ll l;
    cin >> x >> y >> z >> r >> l;
    ball[i] = mp(Ball(x,y,z,r),l);
  }
  vector<Segment> line(q);
  rep(i,q){
    line[i].input();
  }
  rep(j,q){
    ll cnt = 0;
    rep(i,n){
      auto b = ball[i].fi;
      if(b.inside(line[j]) || b.on_surface(line[j])){
        cnt += ball[i].se; 
      }
    }
    std::cout << cnt << std::endl;
  }
  return 0;
}
