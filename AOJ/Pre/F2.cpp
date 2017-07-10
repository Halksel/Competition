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

const ll mod = 1e9+7;
constexpr ll inf = ((1<<30)-1)*2+1 ;
constexpr double PI = acos(-1.0) ;
double eps = 1e-10 ;
const int dy[] = {-1,0,1,0,1,-1,1,-1};
const int dx[] = {0,-1,0,1,1,-1,-1,1};

ll n;
struct Rect{
  // x,y,z
  vector<ll> s;
  ll v;
  bool contain(Rect &r){
    rep(i,3){
      if(s[i] >= r.s[i])
        return false;
    }
    return true;
  }
};
vector<Rect> v;

using P = pair<int,int> ;

struct edge{
  int to,cap,cost,rev;
};

int V;
const ll MAX_V = 201;
vector<edge> G[MAX_V];
int h[MAX_V];
int dist[MAX_V],prevv[MAX_V],preve[MAX_V];
int match[MAX_V];
bool used[MAX_V];

void add_edge(int from,int to,int cap,int cost){
  G[from].push_back({to,cap,cost,G[to].size()});
  G[to].push_back({from,0,-cost,G[from].size()-1});
}

int min_cost_flow(int s,int t,int f){
  int res = 0;
  fill(h,h+V,0);
  while(){
  
  }
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  while(cin >> n){
    v.resize(n);
    rep(i,n){
      cin >> v[i].s[0] >> v[i].s[1] >> v[i].s[2] ;
      sort(all(v[i].s));
    }
  }
  return 0;
}
