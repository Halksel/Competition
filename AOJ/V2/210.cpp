#include <bits/stdc++.h>
using namespace std ;

#define pb(n) push_back(n)
#define fi first
#define se second
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
using pii = pair<int,int> ;
using pll = pair<ll,ll> ;

const int mod = 1000000007;
constexpr int imax = ((1<<30)-1)*2+1 ;
constexpr int inf = 100000000;
constexpr double PI = acos(-1.0) ;
double eps = 1e-10 ;
const int dy[] = {-1,0,1,0};
const int dx[] = {0,-1,0,1};

inline bool value(int x,int y,int w,int h){
  return (x >= 0 && x < w && y >= 0 && y < h);
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll w,h;
  while(cin >> w >> h){
    char maze[w][h] = {};
    vector<pll> pos;
    vector<pll> goal;
    rep(i,h){
      rep(j,w){
        cin >> maze[j][i] ;
        if(maze[j][i] == 'E' || maze[j][i] == 'W' || maze[j][i] == 'E' || maze[j][i] == 'S'){
          pos.push_back(make_pair(j,i));
        }
        else if(maze[j][i] == 'X'){
          goal.push_back(make_pair(j,i));
        }
      }
    }
    ll ans = 0;
    while(pos.size()){
      bool flag[w][h] = {};
      rep(i,pos.size()){

      }
    }
  }
  return 0;
}
