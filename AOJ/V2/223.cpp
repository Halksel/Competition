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

constexpr ll inf = ((1<<30)-1)*2+1 ;
const int dy[] = {-1,0,1,0,1,-1,1,-1};
const int dx[] = {0,-1,0,1,1,-1,-1,1};

inline bool value(int x,int y,int w,int h){
  return (x >= 0 && x < w && y >= 0 && y < h);
}

inline void func(int &x,int w){
  if(x < 0) x = 0;
  if(x == w) --x;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll x,y;
  int tx,ty,kx,ky;
  while(cin >> x >> y && x+y){
    cin >> tx >> ty >> kx >> ky;
    tx--,ty--,kx--,ky--;
    int v[x][y];
    rep(i,y){
      rep(j,x){
        cin >> v[j][i];
      }
    }
    using pp = pair<pii,pii>;
    queue<pp> q;
    q.push(mp(mp(tx,ty),mp(kx,ky)));
    int ans = 0;
    while(q.size()){
      int S = q.size();
      bool f = false;
      rep(l,S){
        pp Q = q.front();q.pop();
        pii T = Q.fi,K = Q.se;
        rep(i,4){
          tx = T.fi + dx[i],ty = T.se + dy[i];
          if(value(tx,ty,x,y) && v[tx][ty] == 0){
            kx = K.fi - dx[i],ky = K.se - dy[i];
            if(value(kx,ky,x,y) && v[kx][ky] == 1){
              if(dx[i]){
                kx += dx[i];
              }
              else{
                ky += dy[i];
              }
            }
            else{
              func(kx,x),func(ky,y);
            }
            if(tx == kx && ty == ky){
              cout << ans << endl;
              f = true;
              break;
            }
            q.push(mp(mp(tx,ty),mp(kx,ky)));
          }
        }
        if(f) break;
      }
      if(f) break;
      ++ans;
      if(ans == 100){
        cout << "NA" << endl;
        break;
      }
    }
  }
  return 0;
}

