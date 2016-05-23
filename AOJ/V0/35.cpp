#include<iostream>
#include<iomanip>
#include<sstream>
#include<string>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<map>
#include<vector>
#include<queue>
#include<set>
#include<numeric>

using namespace std ;

#define pb(n) push_back(n)
#define fi first
#define se second
#define np string::npos
#define all(r) (r).begin(),(r).end()
#define gsort(st,en) sort((st),(en),greater<int>())
#define vmax(ary) *max_element(all(ary))
#define vmin(ary) *min_element(all(ary))
#define debug(x) cout<<#x<<": "<<x<<endl

#define rep(i,n) for(int i = 0; i < (int)(n);++i)
#define repc(i,a,b) for(int i = (a);i < (int)(b);++i)
#define repi(it,array) for(auto it = array.begin(),end = array.end(); it != end;++it)
#define repa(n,array) for(auto n :(array))

typedef long long ll ;
typedef vector<int> vi ;
typedef vector<ll> vl ;
typedef map<string,int> dict;

constexpr int imax = ((1<<30)-1)*2+1 ;
constexpr int inf = 100000000;
double eps = 1e-10 ;

template <typename T>
void out(vector < T > v)
{
  for(size_t i = 0; i < v.size(); i++)
  {
    debug(v[i]);
  }
}

template<typename T>
string ntos( T i ) {
  ostringstream s ;
  s << i ;
  return s.str() ;
}

template<typename T>
T ston(string str, T n){
  istringstream sin(str) ;
  T num ;
  sin >> num ;
  return num ;
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
  double dot(P p){
    return add(x * p.x,y*p.y);
  }
  double det(P p){
    return add(x*p.y,-y*p.x);
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

bool cmp_x(const P& p, const P& q){
  if(p.x != q.x) return p.x < q.x;
  return p.y < q.y;
}
void Ans(bool f){
  if(f) cout << "YES"<<endl;
  else cout << "NO"<<endl;
}
vector<P> convex_hull(P *ps,int n){
  sort(ps,ps+n,cmp_x);
  int k = 0;
  vector<P> qs(n*2);
  rep(i,n){
    while(k > 1 && (qs[k-1] -qs[k-2]).det(ps[i] - qs[k-1]) <= 0){
      k--;
    }
    qs[k++] = ps[i];
  }
  for(int i = n-2,t = k; i >= 0; i--){
    while(k>t && (qs[k-1] - qs[k-2]).det(ps[i]-qs[k-1]) <= 0){
      k--;
    }
    qs[k++] = ps[i] ;
  }
  qs.resize(k-1);
//   cout << n-qs.size() << endl;
  Ans(n-qs.size() == 0);
  return qs;
}

double dist(P p,P q){
  return (p - q).dot(p - q);
}

constexpr int MAX_N = 5;
P ps[MAX_N];
void Solve(){
  vector<P> qs = convex_hull(ps,4);
}
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  char c;
  while(cin >> ps[0].x >>c >> ps[0].y >> c >> ps[1].x >> c >> ps[1].y >>c >> ps[2].x >> c >> ps[2].y >> c >>ps[3].x>>c>>ps[3].y){
    Solve();
    }
  return 0;
}
