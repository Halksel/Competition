#include <bits/stdc++.h>
using namespace std ;

#define pb(n) push_back(n)
#define fi first
#define se second
#define all(r) (r).begin(),(r).end()
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
constexpr int inf = ((1<<30)-1)*2+1 ;
constexpr double PI = acos(-1.0) ;
double eps = 1e-10 ;
const int dy[] = {-1,0,1,0,1,-1,1,-1};
const int dx[] = {0,-1,0,1,1,-1,-1,1};

inline bool value(int x,int y,int w,int h){
  return (x >= 0 && x < w && y >= 0 && y < h);
}

double EPS = 1e-10;
double add(double a, double b){
  if(abs(a+b) < EPS* (abs(a) + abs(b))) return 0;
  return a+b;
}

struct P{
  double x,y;
  P(){}
  P(double _x,double _y):x(_x),y(_y){}
  P operator + (P p){
    return P(add(x,p.x) ,add(y,p.y));
  }
  P operator - (P p){
    return P(add(x,-p.x) ,add(y,-p.y));
  }
  P operator * (double d){
    return P(x * d,y * d);
  }
  bool operator==(const P p){
    return (x == p.x && y == p.y);
  }
  friend ostream& operator<<(ostream& os,const P& p){
    os << "("<<p.x <<","<<p.y<<")";
    return os;
  }
  double norm(){
    return sqrt(x*x + y*y);
  }
  double dot(P p){
    return add(x * p.x,y*p.y);
  }
  double det(P p){
    return add(x*p.y,-y*p.x);
  }
  double dist2(P p){
    return ((*this-p).x * (*this-p).x) + ((*this-p).y * (*this-p).y);
  }
  P GetCenter(P &p){
    return P((*this+p).x/2,(*this+p).y/2);
  }
  double GetSlope(P &p){
    P tmp = *this - p;
    return tmp.y/tmp.x;
  }
};
//線分上に点が存在するか
bool on_seg(P p1,P p2,P q){
  return (p1-q).det(p2-q) == 0 && (p1-q).dot(p2-q) <= 0;
}
//交点導出
P intersection(P p1, P p2, P q1,P q2){
  return p1 + (p2-p1) * ((q2 - q1).det(q1-p1) / (q2 - q1).det(p2-p1)) ;
}

const double r30 = 30 * PI/180.0;
const double r60 = 60 * PI/180.0;
const double rs = {0,r60,r30};

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll n,x,ans = 0;
  cin >> n >> x;
  vector<P> vp;
  vp.push_back({n * cos(r60),n * cos(r30)});
  vp.push_back({n,0});
  vp.push_back({0,0});
//   vp.push_back({(n-x) * cos(r60),(n-x)* cos(r30)});
  double ans = 0,0;
  for(int i = 3; ;++i){
  P tmpP = {2 * n,vp[i].y};
  auto cp = intersection(vp[i],tmpP,vp[i-3],vp[i-2]);
  vp.push_back();
  }
  return 0;
}

