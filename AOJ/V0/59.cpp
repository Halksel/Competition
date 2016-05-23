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

#define rep(i,n) for(int i = 0; i < (int)(n);++i)
#define REP(i,a,b) for(int i = (a);i < (int)(b);++i)
#define repi(it,array) for(auto it = array.begin(),end = array.end(); it != end;++it)
#define repa(n,array) for(auto &n :(array))

using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using dict = map<string,int>;
using pii = pair<int,int> ;

constexpr int imax = ((1<<30)-1)*2+1 ;
constexpr int inf = 100000000;
constexpr double PI = acos(-1.0) ;
double eps = 1e-10 ;
const int dy[] = {-1,0,1,0};
const int dx[] = {0,-1,0,1};

inline bool value(int x,int y,int w,int h){
  return (x >= 0 && x < w && y >= 0 && y < h);
}

template<typename T>
void Unique(vector<T> &v){
  sort(all(v));
  v.erase(unique(all(v)),v.end());
}

template<typename T>
T ston(string& str, T n){
  istringstream sin(str) ;
  T num ;
  sin >> num ;
  return num ;
}

void Ans(bool f){
  if(f) cout << "YES"<<endl;
  else cout << "NO"<<endl;
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
bool AmongPoints(double a,double b, double c){
  return (a <= b && b <= c);
}
bool between(P p1,P p2,P p3, P p4){
  return ((p1.x <= p3.x && p3.x <= p2.x)||(p1.x <= p4.x && p4.x <= p2.x)) &&( (p1.y <= p4.y && p4.y <= p2.y)|| (p1.y <= p3.y && p3.y <= p2.y));
}
bool check(P p1,P p2, P p3 ,P p4){
  return ((p1.x <= p3.x && p3.x <= p2.x)&&(p1.x <= p4.x && p4.x <= p2.x)) &&( (p1.y <= p4.y && p4.y <= p2.y)|| (p1.y <= p3.y && p3.y <= p2.y));
}

bool Ans(P p1,P p2, P p3 ,P p4){
  if((p4.x < p1.x || p1.y > p4.y) || (p3.x > p2.x || p3.y > p2.y)){
    return false;
  }
  return true;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  P p1,p2,p3,p4;
  while(cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y >> p4.x >> p4.y){
//     if(between(p1,p2,p3,p4)){
//       Ans(true);
//     }
//     else if(AmongPoints(p3.x,p1.x,p4.x) ||AmongPoints(p3.x,p2.x,p4.x)){
//       if(AmongPoints(p3.y,p1.y,p4.y) || AmongPoints(p3.y,p2.y,p4.y)){
//         Ans(true);
//       }
//       else
//         Ans(false);
//     }
//     else if(AmongPoints(p1.x,p3.x,p2.x) || AmongPoints(p1.x,p4.x,p2.x)){
//       if(AmongPoints(p1.y,p3.y,p2.y) || AmongPoints(p1.y,p4.y,p2.y)){
//         Ans(true);
//       }
//       else
//         Ans(false);
//     }
//     else
//       Ans(false);
    Ans(Ans(p1,p2,p3,p4));
  }
  return 0;
}
