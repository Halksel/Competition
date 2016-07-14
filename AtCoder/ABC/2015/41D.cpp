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

vector<int> v[17];

ll dp[(1 << 17)][17];
int n,m;
ll ans = 0;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin >> n >> m;
  ll a,b;
  rep(i,m){
    cin >> a >> b;
    v[b-1].push_back(a-1);
  }
  dp[0][0] = 1;
  rep(i,n){
    rep(bfr,(1 << n)){
      rep(k,n){
        if( bfr & (1 << k)) continue;
        bool f = true;
        ll nxt = bfr | (1 << k);
        rep(l,v[k].size()){
          if(!(bfr & (1 << v[k][l]))){
            f= false;
            break;
          }
        }
        if(f){
          dp[nxt][i+1] += dp[bfr][i];
        }
      }
    }
  }
  cout << dp[(1 << n)-1][n] << endl;
  return 0;
}
