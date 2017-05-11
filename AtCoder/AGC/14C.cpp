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

template<typename T>
void O(T t){
  cout << t << endl;
}

const ll mod = 1e9+7;
constexpr ll inf = ((1<<30)-1)*2+1 ;
constexpr double PI = acos(-1.0) ;
double eps = 1e-10 ;

int dx[] = {0,-1, 0,1};
int dy[] = {1, 0,-1,0};

inline bool value(int x,int y,int w,int h){
  return (x > 0 && x < w-1 && y > 0 && y < h-1);
}

int dirjudge(int x,int y,int w,int h){
  x -= w/2;
  y -= h/2;
  if(x < 0 && y < 0){
    if(abs(x) < abs(y)){
      return 0;
    }
    else{
      return 1;
    }
  }
  if(x < 0 && y > 0){
    if(abs(x) < abs(y)){
      return 2;
    }
    else return 1;
  }
  if(x > 0 && y > 0){
    if (abs(x) < abs(y)) {
      return 2;
    } else {
      return 3;
    }
  }
  if (x > 0 && y < 0) {
    if (abs(x) < abs(y)) {
      return 0;
    }
    else {
      return 3;
    }
  }
  return 0;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll h,w,k;
  cin >> h >> w >> k;
  vector<vector<char>> v(h,vector<char>(w,'.'));
  ll sx,sy,tx,ty;
  rep(i,h){
    rep(j,w){
      cin >> v[i][j];
      if(v[i][j] == 'S')
      {
        sx = i;
        sy = j;
      }
    }
  }
  queue<pll> p;
  queue<ll> q;
  p.push({sx,sy});
  q.push(0);
  while (p.size()) {
    pll np = p.front();
    ll cnt = q.front();
    q.pop();
    p.pop();
    rep(i,4){

    }

  }

  return 0;
}
