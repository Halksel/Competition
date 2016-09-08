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
constexpr ll inf = ((1<<30)-1)*2+1 ;
constexpr double PI = acos(-1.0) ;
double eps = 1e-10 ;
const int dy[] = {-1,0,1,0,1,-1,1,-1};
const int dx[] = {0,-1,0,1,1,-1,-1,1};

inline bool value(int x,int y,int w,int h){
  return (x >= 0 && x < w && y >= 0 && y < h);
}
ll w,h;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  while(cin >> w >> h && w+h){
    vector<vector<int>> v(w,vector<int>(h));
    vector<vector<int>> v2(w,vector<int>(h,0));
    rep(i,h){
      rep(j,w){
        cin >> v[j][i];
      }
    }
    int cnt = 0;
    rep(i,h){
      rep(j,w){
        if(!v[j][i]){
          rep(k,4){
            int nx = j + dx[k],ny = i + dy[k];
            if(value(nx,ny,w,h) && !v[nx][ny]){
              v2[j][i]++;
            }
          }
          if(v2[j][i] % 2){
            ++cnt;
          }
        }
      }
    }
    debug(cnt);
    if(cnt % 2 == 0){
      cout << "Yes" << endl;
    }
    else{
      cout << "No" << endl;
    }
  }
  return 0;
}

