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
    vvl(dp,m+1,1010,0);
    rep(i,m){
      cin >> v[i].fi >> v[i].se;
    }
    sort(all(v));
    rep(j,m){
      rep(i,1001){
        dp[j+1][i] += dp[j][i];
        if(v[j].se > 0 && i - v[j].fi >= 0){
          dp[j+1][i] += ((dp[j][i-v[j].fi]==0)?1:dp[j][i-v[j].fi]) * v[j].se;
          if(i % v[j].fi == 0){
            v[j].se--;
          }
        }
//         cout << dp[j+1][i]<< " ";
      }
//       cout << endl;
    }
    ll g,n;
    cin >> g;
    rep(i,g){
      cin >> n;
      rep(j,n+1){
        cout << dp[m][j]<< " ";
      }
      cout << dp[m][n]<<endl;
    }
  }
  return 0;
}
