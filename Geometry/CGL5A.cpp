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

const ll mod = 1e9+7;
constexpr ll inf = ((1<<30)-1)*2+1 ;
constexpr double PI = acos(-1.0) ;
double eps = 1e-10 ;
const int dy[] = {-1,0,1,0,1,-1,1,-1};
const int dx[] = {0,-1,0,1,1,-1,-1,1};

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

double closestPair_calc(P *p,int n){
  if(n < 2) return inf;
  int m = n/2;
  double x=real(p[m]);
  double d = min(closestPair_calc(p,m),closestPair_calc(p+m,n-m));
  inplace_merge(p,p+m,p+n,sorty);
  vector<P> q;
  double dx,dy;
  rep(i,n) {
    if(abs(real(p[i])-x)>=d)continue;

    for(int j=q.size()-1;j>=0;j--)
    {
      dx=real(p[i])-real(q[j]);
      dy=imag(p[i])-imag(q[j]);
      if(dy>=d)break;
      d=min(d,sqrt(dx*dx+dy*dy));
    }
    q.push_back(p[i]);
  }
  return d;
}

double closestPair(vector<P> &p,int n) {
  if(n < 2) return 0.0;
  sort(all(p));
  double ans = closestPair_calc(&p[0],n);
  return ans == inf ? 0.0 : ans;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll n;
  cin >>n;
  double x,y;
  vector<P> ps(n);
  rep(i,n){
    cin >> x >> y;
    ps[i] = P{x,y};
  }
  fcout(10) << closestPair(ps,n) << endl;
  return 0;
}
