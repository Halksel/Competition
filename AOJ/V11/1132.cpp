//http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1132&lang=jp
//AC -- http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=2332681#1
#include <bits/stdc++.h>
using namespace std ;

#define pb(n) push_back(n)
#define fi first
#define se second
#define all(r) begin(r),end(r)
#define mp(a,b) make_pair(a,b)

#define rep(i,n) for(int i = 0; i < (int)(n);++i)
#define REP(i,a,b) for(int i = (a);i < (int)(b);++i)

using ll = long long;

const double EPS = 1e-6;
const double INF = 1e12;
  typedef complex<double> P;//複素数を平面における点と解釈
  struct C {//円
    P p; double r;
    C(){};
    C(const P &p, double r) : p(p), r(r) { }
  };
  P verticalvector(const P &a,const P &b){//2点の単位法線ベクトルを返す
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

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll n;
  double x,y;
  while(cin >> n && n){
    vector<P> ps(n);
    rep(i,n){
      cin >> x >> y;
      ps[i] = {x,y};
    }
    ll ans = 1;
    rep(i,n){
      REP(j,i+1,n){
        if (norm(ps[i] - ps[j]) > 4.0 + EPS) continue;
        P m = (ps[i]+ps[j])/2.0;
        P vv = verticalvector(ps[i],ps[j]);
        double x = sqrt(1 - norm((ps[i] - ps[j]) / 2.0));
        P c1 = vv * x + m,c2 = vv * (-x) + m;
        ll cnt1 = 2,cnt2 = 2;
        rep(k,n){
          if(i == k || j == k) continue;
          if(norm(ps[k] - c1) <= 1.0 + EPS){
            cnt1++;
          }
          if(norm(ps[k] - c2) <= 1.0 + EPS){
            cnt2++;
          }
        }
        ans = max(ans,max(cnt1,cnt2));
      }
    }
    cout << ans << endl;
  }
  return 0;
}
