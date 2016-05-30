#include <bits/stdc++.h>
using namespace std ;

#define pb(n) push_back(n)
#define fi first
#define se second
#define all(r) (r).begin(),(r).end()
#define gsort(st,en) sort((st),(en),greater<int>())
#define vmax(ary) *max_element(all(ary))
#define vmin(ary) *min_element(all(ary))
#define debug(x) cout<<#x<<": "<<x<<endl
#define fcout(n) cout<<fixed<<setprecision((n))
#define scout(n) cout<<setw(n)
#define vary(type,name,size,init) vector< type> name(size,init)
#define vvl(v,w,h,init) vector<vector<ll>> v(w,vector<ll>(h,init));

#define rep(i,n) for(int i = 0; i < (int)(n);++i)
#define REP(i,a,b) for(int i = (a);i < (int)(b);++i)
#define repi(it,array) for(auto it = array.begin(),end = array.end(); it != end;++it)
#define repa(n,array) for(auto &n :(array))

using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using dict = map<string,int>;
using pii = pair<int,int> ;
using pll = pair<ll,ll> ;

const int mod = 1000000007;
constexpr int imax = ((1<<30)-1)*2+1 ;
constexpr int inf = 100000000;
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
bool on_seg(P p1,P p2,P q){
  return (p1-q).det(p2-q) == 0 && (p1-q).dot(p2-q) <= 0;
}
P intersection(P p1, P p2, P q1,P q2){
  return p1 + (p2-p1) * ((q2 - q1).det(q1-p1) / (q2 - q1).det(p2-p1)) ;
}

int check(P p1,P p2,P p3){
  P a = p2-p1,b = p3 - p1;
  if(a.det(b) > EPS) return 1;
  else if(a.det(b) < -EPS) return -1;
  return 0;
}
bool solve(double a,double b,double c,double d,double e,double f,double xp,double yp){
  P p1 = P(a,b),p2 = P(c,d),p3 = P(e,f),p4 = P(xp,yp);
  int A = check(p1,p2,p4);
  int B = check(p2,p3,p4);
  int C = check(p3,p1,p4);
  if(A == B && B == C && (B == 1 || B == -1)){
    return true;
  }
  return false;
}
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll n;
  cin >> n;
  double a,b,c,d,e,f,xk,yk,xs,ys;
  rep(i,n){
    cin >> a >> b >> c >> d >> e >> f >> xk >> yk >> xs >> ys;
    if(solve(a,b,c,d,e,f,xk,yk) == solve(a,b,c,d,e,f,xs,ys)){
      cout << "NG"<<endl;
    }
    else{
      cout << "OK"<<endl;
    }
  }
  return 0;
}
