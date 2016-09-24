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

const int mod = 1000000007;
constexpr double inf = 10000000000 ;
constexpr double PI = acos(-1.0) ;
double eps = 1e-3 ;
const int dy[] = {-1,0,1,0,1,-1,1,-1};
const int dx[] = {0,-1,0,1,1,-1,-1,1};

struct Data{
  ll f,a,x,y;
  bool u ;
  double ti,di;
  double dis(ll s,ll t){
    return sqrt((x - s) * (x - s) + (y - t) * (y - t));
  }
};

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll n,f,a,t,x,y;
  cin >> n;
  Data A[2];
  A[0].u = false;
  A[1].u = false;
  A[0].di = 0;
  A[1].di = 0;
  rep(i,n){
    cin >> f >> a >> t >> x >> y;
    if(A[t].u == false){
      A[t] = {f,a,x,y,true,inf,0};
    }
    else{
      if(A[t].a != a){
        if(A[t].di < A[t].dis(x,y)){
          A[t].di = A[t].dis(x,y);
          A[t].ti = f - A[t].f;
        }
        else if(abs(A[t].di- A[t].dis(x,y)) <= eps){
          if(A[t].ti > f - A[t].f)
            A[t].ti = f - A[t].f;
        }

      }
      A[t] = {f,a,x,y,true,A[t].ti,A[t].di};
    }
  }
  rep(i,2){
    if(A[i].di == 0){
      cout << -1 << ' ' << -1 << endl;
    }
    else
      fcout(10) << A[i].di << ' ' << A[i].ti/60.0 << endl;
  }
  return 0;
}


