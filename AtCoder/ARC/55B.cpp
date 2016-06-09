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

template<typename T>
T ston(string& str, T n){
  istringstream sin(str) ;
  T num ;
  sin >> num ;
  return num ;
}

void Ans(bool f){
  if(f) cout << "YES"<<endl;
  else cout << "NO"<<endl;
}
double dp[1010][1010][2];
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n,k;
  cin >> n>>k;
  for(int j = k; j >= 0; --j){
    dp[n][j][1] = 1.0;
    dp[n][j][0] = 0.0;
  }
  for(int i = n-1; i >=0;--i){
    double p = 1.0/(i+1.0);
    rep(j,k+1){
      dp[i][j][1] = (1.0-p)*dp[i+1][j][1]+p * max(dp[i+1][j+1][1],dp[i+1][j][0]);
      dp[i][j][0] = (1.0-p)*dp[i+1][j][0]+p * max(dp[i+1][j+1][1],dp[i+1][j][0]);
    }
  }
  fcout(10) << dp[0][0][0] << endl;
  return 0;
}