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
const int dx[] = {1,0,-1,-1,0,1};
const int dy[] = {1,1,0,-1,-1,0};
inline bool value(int x,int y,int w,int h){
  return (x >= 0 && x < w && y >= 0 && y < h);
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll t,n,x,y,cnt;
  while(cin >> t >> n && t+n){
    vector<vector<ll>> v(65,vector<ll>(65,inf));

    rep(i,n){
      cin >> x >> y;
      x += 30;
      y += 30;
      v[x][y] = -1;
    }
    cin >> x >> y;
    x += 30;
    y += 30;
    cnt = 1;
    queue<pll> q;
    q.push(mp(x,y));
    v[x][y] = 0;
    while(q.size()){
      auto Q = q.front();q.pop();
      int x = Q.fi,y = Q.se;
      int d = v[x][y];
      if(d >= t) continue;
      rep(i,6){
        ll nx = x + dx[i],ny = y + dy[i];
        if(value(nx,ny,61,61) && v[nx][ny] > d){
          q.push(mp(nx,ny));
          if(v[nx][ny] == inf)
            ++cnt;
          v[nx][ny] = d + 1;
        }
      }
    }
    cout << cnt << endl;
  }
  return 0;
}
