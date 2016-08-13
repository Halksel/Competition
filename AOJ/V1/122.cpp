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
const int dx[] = {-1,0,1,1,1,-1,-1,1};

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

bool check(vector<vector<ll>> dp){
  rep(i,10){
    rep(j,10){
      if(dp[i][j]){
        return true;
      }
    }
  }
  return false;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll x,y;
  while(cin >> x >> y && x+y){
    ll n;
    cin >> n;
    vector<vector<vector<ll>>> dp(n+2,vector<vector<ll>>(10,vector<ll>(10,0)));
    auto sp = dp;
    vector<pll> p(n);
    rep(i,n){
      cin >> p[i].fi >> p[i].se;
      rep(j,3){
        rep(k,3){
          if(value(p[i].fi+dx[j],p[i].se+dy[k],10,10))
            sp[i+1][p[i].fi+dx[j]][p[i].se+dy[k]] = 1;
        }
      }
    }
    dp[0][x][y] = 1;
    int d[3] = {-1,0,1};
    int sig[2] = {-1,1};
    rep(i,n){
      rep(j,10){
        rep(k,10){
          if(dp[i][k][j]){
            rep(l,2){
              rep(m,3){
                int nx = k + d[m],ny = 2 * sig[l] + j;
                if(value(nx,ny,10,10) && sp[i+1][nx][ny] == 1){
                  dp[i+1][nx][ny] = 1;
                }
              }
            }
            rep(l,2){
              rep(m,3){
                int ny = j + d[m],nx = 2 * sig[l] + k;
                if(value(nx,ny,10,10) && sp[i+1][nx][ny] == 1){
                  dp[i+1][nx][ny] = 1;
                }
              }
            }
          }
        }
      }
    }
    if(check(dp[n])){
      cout << "OK" << endl;
    }
    else{
      cout << "NA" << endl;
    }
  }
  return 0;
}

