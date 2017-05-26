//http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0090
//http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=2338630#1
#include <bits/stdc++.h>
using namespace std ;

#define pb(n) push_back(n)
#define mp(a,b) make_pair(a,b)
#define fi first
#define se second
#define np string::npos
#define value(x,y,w,h) (x >= 0 && x < w && y >= 0 && y < h)
#define all(r) (r).begin(),(r).end()
#define gsort(st,en) sort((st),(en),greater<int>())

#define rep(i,n) for(int i = 0; i < (int)(n);++i)
#define REP(i,a,b) for(int i = (a);i < (int)(b);++i)

typedef long long ll ;

const double EPS = 1e-10;
const double INF = 1e12;
typedef complex<double> P;//????´???°????????¢?????????????????¨?§£???
namespace std {
  bool operator < (const P& a, const P& b) {//x????????????
    return real(a) != real(b) ? real(a) < real(b) : imag(a) < imag(b);
  }
  bool sorty(const P& a, const P& b) {//y????????????
    return imag(a) != imag(b) ? imag(a) < imag(b) : real(a) < real(b);
  }
}

typedef vector<P> G;

struct C {//???
  P p; double r;
  C(){};
  C(const P &p, double r) : p(p), r(r) { }
};
// L:line,S:segment,P:point
double distancePP(const P &p,const P &q){
  return abs(p - q) ;
}
P verticalvector(const P &a,const P &b){//2???????????????????????????????????????
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
