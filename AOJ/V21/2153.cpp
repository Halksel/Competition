#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <string.h>
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
using pii = pair<int,int>;
const int dy[] = {-1,0,1,0,1,-1,1,-1};
const int dx[] = {0,-1,0,1,1,-1,-1,1};

inline bool value(int x,int y,int w,int h){
  return (x >= 0 && x < w && y >= 0 && y < h);
}
ll w,h;

vector<string> l,r;

/* bool search(int lx,int ly,int rx,int ry){                                       */
/*   if(!value(lx,ly,w,h) || !value(rx,ry,w,h) || f[lx][ly][rx][ry]) return false; */
/*   (f[lx][ly][rx][ry]) = true;                                                   */
/*   bool res = false;                                                             */
/*   rep(i,4){                                                                     */
/*     int nlx = lx + dx[i],nly = ly + dy[i],nrx = rx - dx[i],nry = ry + dy[i];    */
/*     cout << nlx << ' ' << nly << ' ' << nrx << ' ' << nry << endl;              */
/*     if(value(nlx,nly,w,h) && value(nrx,nry,w,h) ){                              */
/*       if( l[nly][nlx] == '.' && r[nry][nrx] == '.')                             */
/*         res |= search(nlx,nly,nrx,nry);                                         */
/*     }                                                                           */
/*     if(value(nlx,nly,w,h) && value(nrx,nry,w,h) ){                              */
/*       if( l[nly][nlx] == '.' && r[nry][nrx] == '#')                             */
/*         res |= search(nlx,nly,rx,ry);                                           */
/*     }                                                                           */
/*     if(value(nlx,nly,w,h) && value(nrx,nry,w,h) ){                              */
/*       if( l[nly][nlx] == '#' && r[nry][nrx] == '.')                             */
/*         res |= search(lx,ly,nrx,nry);                                           */
/*     }                                                                           */
/*     if(value(nlx,nly,w,h) && value(nrx,nry,w,h) ){                              */
/*       if( l[nly][nlx] == '%' && r[nry][nrx] == '%')                             */
/*         return true;                                                            */
/*     }                                                                           */
/*   }                                                                             */
/*   return res;                                                                   */
/* }                                                                               */

bool f[51][51][51][51] ={};
queue<pair<pii,pii>> q;
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll lx,ly,rx,ry;
  while(cin >> w >> h &&  w + h ){
    l.resize(h),r.resize(h);
    rep(i,h){
      cin >> l[i] >> r[i];
      rep(j,w){
        if(l[i][j] == 'L'){
          ly = i;
          lx = j;
        }
        if(r[i][j] == 'R'){
          ry = i;
          rx = j;
        }
      }
    }
    auto make = [](int lx,int ly,int rx,int ry){return mp(mp(lx,ly),mp(rx,ry));};
    bool ans = false;
    while(q.size()){
      q.pop();
    }
    q.push(make(lx,ly,rx,ry));
    memset(f,0,51*51*51*51);
    while(q.size()){
      pii lp = q.front().fi,rp = q.front().se;
      q.pop();
      lx = lp.fi,ly = lp.se,rx = rp.fi,ry = rp.se;
      rep(i,4){
        int nlx = lx + dx[i],nly = ly + dy[i],nrx = rx - dx[i],nry = ry + dy[i];
        if(value(nlx,nly,w,h) && value(nrx,nry,w,h) ){
          if( l[nly][nlx] == '.' && r[nry][nrx] == '.' && !f[nlx][nly][nrx][nry]){
            f[nlx][nly][nrx][nry] = true;
            q.push(make(nlx,nly,nrx,nry));
          }
          else if( l[nly][nlx] == '.' && r[nry][nrx] == '#'&& !f[nlx][nly][rx][ry]){
            f[nlx][nly][rx][ry] = true;
            q.push(make(nlx,nly,rx,ry));
          }
          else if( l[nly][nlx] == '#' && r[nry][nrx] == '.'&& !f[lx][ly][nrx][nry]){
            f[lx][ly][nrx][nry] = true;
            q.push(make(lx,ly,nrx,nry));
          }
          else if( l[nly][nlx] == '%' && r[nry][nrx] == '%'){
            ans = true;
            while(q.size()){
              q.pop();
            }
          }
        }
        else{
          if( value(nlx,nly,w,h) && l[nly][nlx] == '.' && !f[nlx][nly][rx][ry]){
            f[nlx][nly][rx][ry] = true;
            q.push(make(nlx,nly,rx,ry));
          }
          else if( value(nrx,nry,w,h) && r[nry][nrx] == '.'&& !f[lx][ly][nrx][nry]){
            f[lx][ly][nrx][nry] = true;
            q.push(make(lx,ly,nrx,nry));
          }
        }
      } 
    }
    std::cout << (ans ? "Yes" : "No") << std::endl; 
  }
  return 0;
}
