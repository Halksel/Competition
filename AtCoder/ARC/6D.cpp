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

vector<string> a = { ".......", "...o..." ,"..o.o..", ".o...o.", ".ooooo." ,".o...o." ,"......."};
vector<string> b = { ".......", ".oooo.." ,".o...o.", ".oooo..", ".o...o." ,".oooo.." ,"......."};
vector<string> c = { ".......", "..ooo.." ,".o...o.", ".o.....", ".o...o." ,"..ooo.." ,"......."};

ll ca,cb,cc;
ll h , w;
vector<string> v;
inline bool value(int x,int y,int w,int h){
  return (x >= 0 && x < w && y >= 0 && y < h);
}
int dfs(int x,int y){
  if(v[y][x] == '.') return 0;
  v[y][x] = '.';
  int res = 1;
  REP(i,-1,2){
    REP(j,-1,2){
      int nx = x + i,ny = y + j;
      if(!value(nx,ny,w,h) || v[ny][nx] == '.' ) continue;
      res += dfs(nx,ny); 
    }
  }
  return res;
}

int ans(int c){
  if(c <= 16) return c;
  REP(i,2,150){
    int k = c / (i*i);
    if(c % (i * i) == 0 && (k == 11 || k == 16 || k == 12)){
      return k;
    }
  }
  return 1;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin >> h >> w;
  v.resize(h);
  rep(i,h){
    cin >> v[i];
  }
  rep(i,h){
    rep(j,w){
      if(v[i][j] == 'o'){
        int c = ans(dfs(j,i));
        switch (c){
          case 12:
            ++ca;
            break;
          case 16:
            ++cb;
            break;
          case 11:
            ++cc;
        } 
        /* debug(c); */
      }
    }
  }
  std::cout << ca << ' ' << cb << ' ' << cc << std::endl;
  return 0;
}
