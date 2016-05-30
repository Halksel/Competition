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

#define rep(i,n) for(int i = 0; i < (int)(n);++i)
#define REP(i,a,b) for(int i = (a);i < (int)(b);++i)
#define repi(it,array) for(auto it = array.begin(),end = array.end(); it != end;++it)
#define repa(n,array) for(auto &n :(array))

typedef long long ll ;
typedef deque<int> di ;
typedef deque<ll> dl ;
typedef map<string,int> dict;
typedef complex<double> comd;
typedef pair<int,int> pii;

constexpr int imax = ((1<<30)-1)*2+1 ;
constexpr int inf = 100000000;
constexpr double PI = acos(-1.0) ;
double eps = 1e-10 ;
const int dy[] = {-1,0,1,0};
const int dx[] = {0,-1,0,1};

double CalcDist(comd p1, comd p2){
  return sqrt(pow(p1.X - p2.X,2.0) + pow(p1.Y -p2.Y,2.0));
}
struct data{
  pii first;
  ll second;
};
bool operator<(const data& a ,const data& b){
  return a.second > b.second;
}

ll x;
pii S,G;
int H, W, T;
char c[11][11];
ll d[11][11];
void dijkstra(pii s){
  priority_queue<data> Q;
  rep(i,H) rep(j,W) d[j][i] = inf;
  Q.push(data{s,0});
  while(Q.size()){
    data q= Q.top();Q.pop();
    if(d[q.fi.fi][q.fi.se] == inf){
      d[q.fi.fi][q.fi.se] = q.se;
    }
    else{
      continue;
    }
    rep(i,4){
      int nx = q.fi.fi + dx[i],ny = q.fi.se + dy[i];
      if(!value(nx,ny,W,H) ) continue;
      ll t_c = (c[nx][ny] == '#' ? x:1LL) + q.se;
      Q.push(data{make_pair(nx,ny),t_c});
    }
  }
}
bool check(ll mid){
  x = mid;
  dijkstra(S);
  if (d[G.first][G.second] <= (ll)T) {
    return true;
  }
  return false;
}
ll bs(ll lb,ll ub){
  while( ub - lb >1){
    ll mid = (ub+lb)/2;
    if(check(mid)){
      lb = mid;
    }
    else ub = mid;
  }
  return lb;
}
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin >> H>>W>>T;
  rep(i,H){
    rep(j,W){
      cin >> c[j][i];
    }
  }
  rep(i,H){
    rep(j,W){
      if(c[j][i] == 'S')
        S = pii(j,i);
      if(c[j][i] == 'G')
        G = pii(j,i);
    }
  }
  cout << bs(1,T)<<endl;
  return 0;
}
