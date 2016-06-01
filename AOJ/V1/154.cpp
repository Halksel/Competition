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

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll m,a,b;
  while(cin >> m && m){
    vector<pll> v(m);
    vary(ll,dp,1010,-1);
    rep(i,m){
      cin >> v[i].fi >> v[i].se;
      dp[v[i].fi] = 1;
      v[i].se--;
    }
    sort(all(v));
    rep(i,m){
      rep(j,1001){
        if(dp[j] >= 0){
          if(dp[j] == 0) dp[j] = v[i].se;
          else
            dp[j] *= v[i].se;
        }
        else if(j < v[i].fi || dp[j-v[i].fi] <= 0){
          dp[j] = -1;
        }
        else{
          dp[j] = dp[j-v[i].fi] - 1;
        }
      }
    }
    ll g,n;
    cin >> g;
    rep(i,g){
      cin >> n;
      cout << dp[n]<<endl;
    }
  }
  return 0;
}
