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

const int mod = 1000000007;
constexpr ll inf = ((1<<30)-1)*2+1 ;
constexpr double PI = acos(-1.0) ;
double eps = 1e-10 ;
const int dy[] = {-1,0,1,0,1,-1,1,-1};
const int dx[] = {0,-1,0,1,1,-1,-1,1};

inline bool value(int x,int y,int w,int h){
  return (x >= 0 && x < w && y >= 0 && y < h);
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll n,m,k,x,y,t;
  cin >> n >> m >> k >> x >> y;
  if(n == 1){
    cout << k / m + (k % m != 0) << ' ' << k/m << ' ' << k/m + (k % m >= y ) << endl;
    return 0;
  }
  vector<vector<ll>> v(n,vector<ll>(m));
  t = 2 * m + (n-2) * 2 * m;
  ll a = k / t;
  ll b = k % t,ans1 = inf,ans2 = 0,ans3 = 0;
  int c = 0;
  if(b == 0){
    if(x == 1 || x == n) ans3 = a;
    else ans3 = 2 * a;
    if(n != 2)
      cout << 2 * a << ' ' << a << ' ' << ans3 << endl;
    else
      cout << a << ' ' << a << ' ' << a << endl;
    return 0;
  }
  while(1){
    rep(i,n){
      rep(j,m){
        v[i][j]++;
        if(c == b-1){
          rep(tt,m){
            ans1 = min(ans1,min(v[0][tt],v[n-1][tt]));
          }
          ans1 += a ;
          rep(p,n){
            rep(q,m){
              ll tmp = 0;
              if(p == 0 || p == n-1)tmp = a;
              else tmp = 2 * a;
              ans3 = max(ans3,tmp + v[p][q]);
            }
          }
          ans2 = v[x-1][y-1];
          if(x == 1 || x == n) ans2 += a;
          else ans2 += 2*a;
          cout << ans3 << ' ' << ans1 << ' ' << ans2 << endl;
          return 0;
        }
        ++c;
      }
    }
    for(int i = n-2; i >= 1;--i){
      rep(j,m){
        v[i][j]++;
        if(c == b-1){
          rep(tt,m){
            ans1 = min(ans1,min(v[0][tt],v[n-1][tt]));
          }
          ans1 += a ;
          rep(p,n){
            rep(q,m){
              ll tmp = 0;
              if(p == 0 || p == n-1)tmp = a;
              else tmp = 2 * a;
              ans3 = max(ans3,tmp + v[p][q]);
            }
          }
          ans2 = v[x-1][y-1];
          if(x == 1 || x == n) ans2 += a;
          else ans2 += 2*a;
          cout << ans3 << ' ' << ans1 << ' ' << ans2 << endl;
          return 0;
        }
        ++c;
      }
    }
  }
  return 0;
}
