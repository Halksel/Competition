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
  ll n,m;
  cin >> n >> m;
  vector<ll> w(n),b(n),r(n);
  char c;
  rep(i,n){
    rep(j,m){
      cin >> c;
      if(c == 'W'){
        w[i]++;
      }
      else if(c == 'R'){
        r[i]++;
      }
      else
        b[i]++;
    }
  }
  ll ans = inf;
  REP(i,1,n-1){
    ll tmp =0;
    rep(k,i){
      tmp += r[k] + b[k];
    }
    ll tmp3 = inf;
    REP(j,1,n-1){
      ll tmp2 = 0;
      if(j+i >= n) continue;
      REP(l,i,i+j){
        tmp2 += r[l] + w[l];
      }
      REP(l,j+i,n){
        tmp2 += w[l] + b[l];
      }
      tmp3 = min(tmp3,tmp2);
    }
    ans = min(ans,tmp+tmp3);
  }
  cout << ans << endl;
  return 0;
}

