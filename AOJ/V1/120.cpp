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
using pdl = pair<double,ll> ;

const int mod = 1000000007;
constexpr int inf = ((1<<30)-1)*2+1 ;
constexpr double PI = acos(-1.0) ;
double eps = 1e-6 ;
const int dy[] = {-1,0,1,0,1,-1,1,-1};
const int dx[] = {0,-1,0,1,1,-1,-1,1};

inline bool value(int x,int y,int w,int h){
  return (x >= 0 && x < w && y >= 0 && y < h);
}


double calc(int r1,int r2){
  return sqrt((r1+r2)*(r1+r2) - (r1-r2)*(r1-r2));
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  string s;
  stringstream ss;
  ll w;
  while(getline(cin,s)){
    ss.clear();
    ss << s;
    ss >> w;
    vector<ll> v(12);
    ll n = 0,k;
    while(ss >> k){
      v[n] = k;
      ++n;
    }
    vector<vector<double>> dp(1 << n,vector<double>(n,1e9));
    bool f = false;
    rep(i,n){
      dp[1 << i][i] = v[i];
    }
    double ans = 10000000.0;
    REP(i,1,(1 << n)){
      REP(j,0,n){
        if(i & (1 << j)) continue;
        ll nxt = i | (1 << j);
        REP(k,0,n){
          if((i & (1 << k)) == 0) continue;
          double bw = 0;
          if(nxt == (1 << n)-1){
            bw += v[j];
          }
          bw += calc(v[k],v[j]);
          dp[nxt][j] = min(dp[nxt][j],bw + dp[i][k]);
        }
      }
    }
    rep(i,n){
      ans = min(ans,dp[(1 << n)-1][i]);
    }
    if(ans <= w){
      cout << "OK" << endl;
    }
    else{
      cout << "NA"<<endl;
    }
  }
  return 0;
}

