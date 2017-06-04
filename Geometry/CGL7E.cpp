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

constexpr ll inf = ((1<<30)-1)*2+1 ;
const double EPS = 1e-8;
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
pair<P,P> crosspoint(const C &a,const C &b){
  double d = abs(b.p-a.p);
  double c = acos((a.r*a.r+d*d-b.r*b.r)/(2.0*a.r*d));
  double t = arg(b.p-a.p);
  P A = a.p + polar(a.r,t+c),B = a.p + polar(a.r,t-c);
  if(A < B)
  return mp(A,B);
  return mp(B,A);
}
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  double x,y,r;
  cin >> x >> y >> r;
  C c1(P(x,y),r); 
  cin >> x >> y >> r;
  C c2(P(x,y),r); 
  auto res = crosspoint(c1,c2);
  fcout(10) << real(res.fi) << ' ' << imag(res.fi) << ' ' << real(res.se) << ' ' << imag(res.se) << endl;
  return 0;
}
