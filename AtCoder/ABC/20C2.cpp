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

  template <typename T>
void out(deque < T > d)
{
  for(size_t i = 0; i < d.size(); i++)
  {
    debug(d[i]);
  }
}

template<typename T>
T ston(string& str, T n){
  istringstream sin(str) ;
  T num ;
  sin >> num ;
  return num ;
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
char c[10][10];
ll d[10][10];
void dijkstra(pii s){
  priority_queue<data> Q;
  rep(i,H) rep(j,W) d[i][j] = inf;
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
      if(!value(q.fi.fi+dx[i],q.fi.se+dy[i],H,W)) continue;
      ll t_c = (c[q.fi.fi+dx[i]][q.fi.se+dy[i]] == '#' ? x:1LL) + q.se;
      Q.push(data{make_pair(q.fi.fi+dx[i],q.fi.se+dy[i]),t_c});
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
  while( abs( ub -lb )>1){
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
    cin >> c[i];
  }
  rep(i,H){
    rep(j,W){
      if(c[i][j] == 'S')
        S = pii(i,j);
      if(c[i][j] == 'G')
        G = pii(i,j);
    }
  }
  cout << bs(1,T)<<endl;
//   rep(i,H){
//     rep(j,W){
//     cout << d[i][j]<< " ";
//     }
//     cout << endl;
//   }
  return 0;
}
