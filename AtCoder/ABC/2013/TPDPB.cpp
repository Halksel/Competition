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

ll dp[1001][1001];

vector<ll> v(1000+1),v2(1000+1);
ll n,m;
ll dfs(int i,int j){
  if(i == n && j == m) return 0;
  if(dp[i][j] != -1) return dp[i][j];
  if((i+j) % 2){
    if(i == n) return dp[i][j] = dfs(i,j+1);
    if(j == m) return dp[i][j] = dfs(i+1,j);
    return dp[i][j] = min(dfs(i,j+1),dfs(i+1,j));
  }
  if((i+j) % 2 == 0){
    if(i == n) return dp[i][j] = dfs(i,j+1)+v2[j];
    if(j == m) return dp[i][j] = dfs(i+1,j)+v[i];
    return dp[i][j] = max(dfs(i,j+1)+v2[j],dfs(i+1,j)+v[i]);
  }
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin >> n >> m;
  rep(i,n){
    cin >> v[i];
  }
  rep(i,m){
    cin >> v2[i];
  }
  rep(i,1001){
    rep(j,1001){
      dp[j][i] = 0;
    }
  }
  rep(i,n){
    dp[i+1][0] = (!(m+i)&1 ? 0 : dp[i][0] + v[i+1]);
  }
  rep(j,m){
    dp[0][j+1] = (!(n+j)&1 ? 0 : dp[0][j]+ v2[j+1]);
  }
  REP(i,0,n){
    REP(j,0,m){
      if((i+j)&1){
        dp[i+1][j+1] = min(dp[i][j+1],dp[i+1][j]);
      }
      else{
        dp[i+1][j+1] = max(dp[i][j+1] + v[i+1],dp[i+1][j]+v2[j+1]);
      }
    }
  }
  rep(i,n){
    rep(j,m){
      cout << dp[i][j] << ' ';
    }
    cout << endl;
  }
  cout << dp[n-1][m-1]<<endl;
  return 0;
}
