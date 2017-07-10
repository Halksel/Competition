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

template<typename T>
void O(T t){
  cout << t << endl;
}

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
  P crosspoint(const L &l, const L &m) {
    double A = cross(l[1] - l[0], m[1] - m[0]);
    double B = cross(l[1] - l[0], l[1] - m[0]);
    if (abs(A) < EPS && abs(B) < EPS) return m[0]; // same line
    if (abs(A) < EPS) assert(false); // !!!PRECONDITION NOT SATISFIED!!!
    return m[0] + B / A * (m[1] - m[0]);
  }

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll q;
  cin >> q;
  double x,y;
  rep(i,q){
    cin >> x >> y;
    P a(x,y);
    cin >> x >> y;
    P b(x,y);
    cin >> x >> y;
    P c(x,y);
    cin >> x >> y;
    P d(x,y);
    L ab(a,b),cd(c,d);
    P p = crosspoint(ab,cd);
    fcout(10) << real(p) << ' ' << imag(p) << endl;
  }
  return 0;
}