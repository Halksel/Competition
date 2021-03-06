#include <bits/stdc++.h>
using namespace std ;

#define pb(n) push_back(n)
#define fi first
#define se second
#define all(r) (r).begin(),(r).end()
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
using vi = vector<int>;
using vl = vector<ll>;
using dict = map<string,int>;
using pii = pair<int,int> ;
using pll = pair<ll,ll> ;

const int mod = 1000000007;
constexpr int inf = ((1<<30)-1)*2+1 ;
constexpr double PI = acos(-1.0) ;
double eps = 1e-10 ;
const int dy[] = {-1,0,1,0,1,-1,1,-1};
const int dx[] = {0,-1,0,1,1,-1,-1,1};

inline bool value(int x,int y,int w,int h){
  return (x >= 0 && x < w && y >= 0 && y < h);
}

template<typename T>
void Unique(vector<T> &v){
  sort(all(v));
  v.erase(unique(all(v)),v.end());
}


ll tax(double a,double b, double r){
  a *= double((100+r)/100);
  b *= double((100+r)/100);
  debug(a);
  debug(b);
  a = (int)(a);
  b = (int)(b);
  return a+b;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  double x,y,s;
  while(cin >> x >> y >> s && x && y && s){
    vector<ll> v;
    double r = (100+x)/100,r2 = (100+y)/100;
    REP(i,1,s){
      double a,b;
      int f = 0;
      for(int j = 0; j <i+1;++j ){
        if(floor(r * j +eps)== i){
          a = floor(j*r2+eps);
//           cout << i<< "j:" << j<<":"<<a<<endl;
          ++f;
          break;
        }
      }
      for(int j = 0; j < s-1; ++j ){
        if(floor(r * j+eps) == s-i){
          b = floor(j*r2+eps);
//           cout << j << ":"<<b<<endl;
          ++f;
          break;
        }
      }
      if(f == 2){
        ll ans = a+b;
//         cout << ans<<endl;
        v.pb(ans);
      }
    }
    cout << *max_element(all(v))<<endl;
  }
  return 0;
}
