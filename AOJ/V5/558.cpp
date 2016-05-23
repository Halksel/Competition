#include <bits/stdc++.h>
using namespace std ;

#define pb(n) push_back(n)
#define fi first
#define se second
#define X real()
#define Y imag()
#define value(x,y,w,h) (x >= 0 && x < w && y >= 0 && y < h)
#define all(r) (r).begin(),(r).end()
#define gsort(st,en) sort((st),(en),greater<int>())
#define vmax(ary) *max_element(all(ary))
#define vmin(ary) *min_element(all(ary))
#define debug(x) cout<<#x<<": "<<x<<endl
#define fcout(n) cout<<fixed<<setprecision((n))
#define scout(n) cout<<setw(n)
#define vary(type,name,size,init) vector< type> name(size,init)

#define rep(i,n) for(int i = 0; i < (int)(n);++i)
#define REP(i,a,b) for(int i = (a);i < (int)(b);++i)
#define repi(it,array) for(auto it = array.begin(),end = array.end(); it != end;++it)
#define repa(n,array) for(auto &n :(array))

using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using dict = map<string,int>;
using comd = complex<double>;
using pii = pair<int,int> ;

constexpr int imax = ((1<<30)-1)*2+1 ;
constexpr int inf = 10000000;
constexpr double PI = acos(-1.0) ;
double eps = 1e-10 ;
const int dy[] = {-1,0,1,0};
const int dx[] = {0,-1,0,1};

int N,W,H,S;
vector<vector<int>> maps;
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  char c;
  int n = 0;
  cin >> W >> H >> N;
  char area[H][W];
  maps = vector<vector<int>>(H,vector<int>(W,-1));
  pii pos;
  rep(i,W){
    rep(j,H){
      cin >> c ;
      area[j][i] = c;
      if(c == 'S'){
        pos = make_pair(j,i);
        ++n;
      }
    }
  }
  queue<pii> q;
  q.push(pos);
  maps[pos.fi][pos.se] = 0;
  n = 1;
  int ans = 0;
  for(n = 1; n < N+1;++n){
    maps = vector<vector<int>>(H,vector<int>(W,-1));
    q = queue<pii>();
    q.push(pos);
    maps[pos.fi][pos.se] = 0;
    while(!q.empty()){
      pii p = q.front();q.pop();
      rep(i,4){
        int x = p.fi + dx[i],y = p.se+dy[i];
        if(value(x,y,H,W)){
          if(area[x][y] - '0' == n){
            ans += maps[p.fi][p.se] + 1;
            pos = make_pair(x,y);
            q = queue<pii>();
            break;
          }
          else if(area[x][y] != 'X' && ( maps[x][y] == -1)){
            q.push(make_pair(x,y));
            maps[x][y] = maps[p.fi][p.se] +1 ;
          }
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}
