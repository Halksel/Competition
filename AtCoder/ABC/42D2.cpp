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
template<typename T,typename U>
ll FindErase(T &v,U tar){
  ll cnt = 0;
  for(auto it = v.begin(); it != v.end();){
    if(*it == tar){
      it = v.erase(it);
      ++cnt;
    }
    else{
      ++it;
    }
  }
  return cnt;
}

template<typename T>
bool SuffixErase(T &v,size_t suf){
  if(suf > v.size()) return false;
  for(auto it = v.begin(); it != v.end();){
    if(distance(v.begin(),it) == suf){
      v.erase(it);
      return true;
    }
    else{
      ++it;
    }
  }
  return false;
}

template<typename T>
T ston(string& str, T n){
  istringstream sin(str) ;
  T num ;
  sin >> num ;
  return num ;
}

void DP(vector<vector<ll>> &dp,int h,int w,bool f){
  rep(i,h){
    if(f)
      dp[0][i+1] += dp[0][i] % mod;
    rep(j,w){
      if(i == 0 && f){
        dp[j+1][0] += dp[j][0];
      }
      dp[j+1][i+1] += dp[j][i+1] % mod + dp[j+1][i] % mod;
    }
  }
}


int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll h,w,a,b;
  cin >> h >> w >> a >> b;
  vector<vector<ll>> dp1(b+3,vector<ll>(h-a+2));
  vector<vector<ll>> dp2(w-b+3,vector<ll>(h-a+2));
  vector<vector<ll>> dp3(w-b+3,vector<ll>(a+2));
  dp1[0][0] = 1;
  DP(dp1,h-a,b,true);
  rep(i,h-a){
    dp2[0][i] = dp1[b-1][i];
  }
  DP(dp2,h-a,w-b,false);
  rep(i,w-b){
    dp3[i][0] = dp2[i][h-a];
  }
  DP(dp3,a,w-b,false);
  cout << dp3[w-b-1][a-1] % mod << endl;
  return 0;
}

