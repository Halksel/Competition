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
constexpr int inf = ((1<<30)-1)*2+1 ;
constexpr double PI = acos(-1.0) ;
double eps = 1e-10 ;
const int dy[] = {-1,0,1,0,1,-1,1,-1};
const int dx[] = {0,-1,0,1,1,-1,-1,1};

inline bool value(int x,int y,int w,int h){
  return (x >= 0 && x < w && y >= 0 && y < h);
}
ll n,m,sum;
vector<vector<ll>> scene(100,vector<ll>(100,0));
vector<vector<vector<ll>>> pic(4,vector<vector<ll>>(50,vector<ll>(50,0)));

bool check(int x,int y){
  rep(i,4){
    ll cnt = 0;
    rep(j,m){
      rep(k,m){
        if(value(x+k,y+j,n,n)){
          if(pic[i][k][j] != -1 && pic[i][k][j] != scene[x+k][y+j]) break;
          else if(pic[i][k][j] == scene[x+k][y+j]) ++cnt;
        }
      }
    }
    if(cnt == sum){
      rep(j,m){
        rep(k,m){
          if(pic[i][k][j] != -1){
            cout << x+k+1 << ' ' << y+j+1 << endl;
            return true;
          }
        }
      }
    }
  }
  return false;
}

void solve(){
  rep(i,n){
    rep(j,n){
      if(check(j,i)){
        return ;
      }
    }
  }
  cout << "NA"<<endl;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  while(cin >> n >> m && n+m){
    rep(i,n){
      rep(j,n){
        cin >> scene[j][i];
      }
    }
    sum =0;
    rep(i,m){
      rep(j,m){
        cin >> pic[0][j][i];
        if(pic[0][j][i] != -1) ++sum;
      }
    }
    rep(i,m){
      rep(j,m){
        pic[1][m-i-1][j] = pic[0][j][i];
      }
    }
    rep(i,m){
      rep(j,m){
        pic[2][m-j-1][m-i-1] = pic[0][j][i];
      }
    }
    rep(i,m){
      rep(j,m){
        pic[3][i][m-j-1] = pic[0][j][i];
      }
    }
    solve();
  }
  return 0;
}

