#include <bits/stdc++.h>
using namespace std ;

#define pb(n) push_back(n)
#define fi first
#define se second
#define X real()
#define Y imag()
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
using comd = complex<double>;
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

double CalcDist(comd p1, comd p2){
  return sqrt(pow(p1.X - p2.X,2.0) + pow(p1.Y -p2.Y,2.0));
}

template<typename T>
void Unique(vector<T> &v){
  sort(all(v));
  v.erase(all(v),v.end());
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
int is_prime[100001];
void Eratosthenes(int N){
  for(int i = 0; i < N; i++){
    is_prime[i] = 1;
  }
  is_prime[1] = 0;
  for(int i = 2; i*i < N ; i++){
    if(is_prime[i]){
      for(int j = 0; i * (j + 2) < N; j++){
        is_prime[i *(j + 2)] = 0;
      }
    }
  }
}
double ceilN(double a, int N){
  double ans,sign;
  sign = (a < 0)? -1 : 1;
  ans = a * pow(10.0,N);
  ans = (double)(int)(ans+ 0.5 * sign);
  return ans * pow(10.0,-N);
}
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n;
  P p1,p2,p3;
  cin >> n;
  rep(i,n){
    cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y;
    P p12,p23,ans;
    double slp12,slp23,t1,t2;
    p12 = p1.GetCenter(p2);
    p23 = p2.GetCenter(p3);
    slp12 = p1.GetSlope(p2),slp23 = p2.GetSlope(p3);
    if(p1.y == p2.y && p2.x == p3.x){
      ans.x = p12.x;
      ans.y = p23.y;
    }
    else if(p2.y == p3.y && p1.x == p2.x){
      ans.x = p23.x;
      ans.y = p12.y;
    }
    else{
      if(p1.y == p2.y){
        ans.x = p12.x;
        t2 = (slp23 != inf)?p23.y + p23.x / slp23: 0;
        ans.y = (-1/slp23) * ans.x + t2;
      }
      else if(p2.y == p3.y){
        ans.x = p23.x;
        t1 = (slp12 != inf)?p12.y + p12.x / slp12: 0;
        ans.y = (-1/slp12) * ans.x + t1;
      }
      else{
        t1 = (slp12 != inf)?p12.y + p12.x / slp12: 0;
        t2 = (slp23 != inf)?p23.y + p23.x / slp23: 0;
        ans.x = (t1-t2)/(1/slp12 - 1/slp23);
        if(slp12 != inf){
          ans.y = (-1/slp12) * ans.x + t1;
        }
        else{
          ans.y = (-1/slp23) * ans.x + t2;
        }
      }
    }
    fcout(3) << ceilN(ans.x,3) << " " << ceilN(ans.y,3) << " " << ceilN(sqrt(ans.dist2(p1)),3)<<endl;
  }
  return 0;
}
