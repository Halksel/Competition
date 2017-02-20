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
const int dx[] = {-1, 0, 1};
const int dy[] = {-1, 0, 1};

inline bool value(int x,int y,int w,int h){
  return (x >= 0 && x < w && y >= 0 && y < h);
}

ll h,w;
int im[1000][1000];
template<class T>
bool solve(T &v){
  auto tmp = v;
  bool f = true;
  rep(i,h){
    rep(j,w){
      if(v[i][j] != '.'){
        ll cnt = 0;
        rep(y,3){
          rep(x,3){
            ll nx = j+dx[x],ny = i + dy[y];
            if(value(nx,ny,w,h)){
              if(v[ny][nx] == '.')
                ++cnt;
            }
          }
        }
        if(cnt >= v[i][j] - '0'){
          tmp[i][j] = '.';
          f = false;
        }
      }
    }
  }
  v = tmp;
  return f;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin >> h >> w;
  vector<vector<char>> v(h,vector<char>(w));
  rep(i,h){
    rep(j,w){
      cin >> v[i][j];
    }
  }

  ll ans = 0;
  while(1){
    if(solve(v)){
      cout << ans << endl;
      break;
    }
    ++ans;
  }
  return 0;
}

