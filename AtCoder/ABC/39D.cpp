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

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll h,w;
  cin >> h >> w;
  vector<vector<int>> v(w,vector<int>(h,0));
  char c;
  string s = "possible",s2 = "impossible";
  rep(i,h){
    rep(j,w){
      cin >> c;
      v[j][i] = (c == '.')?0:1;
    }
  }
  auto ans = v;
  rep(i,h){
    rep(j,w){
      rep(k,8){
        ll nx = j + dx[k],ny = i + dy[k];
        if(value(nx,ny,w,h)&& v[nx][ny] == 0){
          ans[j][i] = 0;
          break;
        }
      }
    }
  }
  auto v2 = ans;
  rep(i,h){
    rep(j,w){
      rep(k,8){
        ll nx = j + dx[k],ny = i + dy[k];
        if(value(nx,ny,w,h)&& ans[nx][ny] == 1){
          v2[j][i] = 1;
          break;
        }
      }
    }
  }
  if(v == v2){
    cout << s<<endl;
    rep(i,h){
      rep(j,w){
        cout << ((ans[j][i] == 1)?'#':'.');
      }
      cout << endl;
    }
  }
  else{
    cout << s2<<endl;
  }
  return 0;
}
