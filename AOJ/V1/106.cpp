#include <bits/stdc++.h>
using namespace std ;

#define pb(n) push_back(n)
#define fi first
#define se second
#define all(r) (r).begin(),(r).end()
#define gsort(st,en) sort((st),(en),greater<int>())
#define vmax(ary) *max_element(all(ary))
#define vmin(ary) *min_element(all(ary))
#define debug(x) cout<<#x<<": "<<x<<endl
#define fcout(n) cout<<fixed<<setprecision((n))
#define scout(n) cout<<setw(n)
#define vary(type,name,size,init) vector< type> name(size,init)

#define rep(i,n) for(int i = 0; i < (int)(n);++i)
#define REP(i,a,b) for(int i = (a);i < (int)(b);++i)
#define repi(it,array) for(auto it = array.begin(),end = array.end(); it != end;++it)
#define repa(n,array) for(auto &n :(array))

using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using dict = map<string,int>;
using pii = pair<int,int> ;

constexpr int imax = ((1<<30)-1)*2+1 ;
constexpr int inf = 100000000;
constexpr double PI = acos(-1.0) ;
double eps = 1e-10 ;
const int dy[] = {-1,0,1,0};
const int dx[] = {0,-1,0,1};

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

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n;
  double ans;
  vary(double,dp,51,0);
  dp[0] = 0;
  dp[1] = inf;
  dp[2] = 380;
  dp[3] = 550;
  dp[4] = 380*2;
  dp[5] = 850;
  dp[6] = 550 * 2;
  REP(i,7,51){
    ans = 380 + dp[i-2];
    ans = min(ans,550 + dp[i-3]);
    ans = min(ans,850 + dp[i-5]);
    if(i >= 10)
      ans = min(ans,dp[i-10] + 380 * 5 * 0.8);
    if(i >= 12)
      ans = min(ans,dp[i-12] + 550 * 4 * 0.85);
    if(i >= 15)
      ans = min(ans,dp[i-15] + 850 * 3 * 0.88);
    dp[i] += ans;
  }
  while(cin>>n&&n){
    cout << dp[n/100] << endl;
  }
  return 0;
}
