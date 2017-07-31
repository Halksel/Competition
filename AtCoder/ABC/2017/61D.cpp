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

const int MAX_E = 2000;
const int MAX_V = 2000;
struct edge{
  ll from,to,cost;
};

edge es[MAX_E];
ll d[MAX_V];

class Bellman_Ford{
  public:
  int V,E;
  const ll INF = 1LL << 50;
  Bellman_Ford(){};
  Bellman_Ford(ll v,ll e):V(v),E(e){};
  void shorter_path(int s){
    rep(i,V) d[i] = INF;
    d[s] = 0;
    rep(i,V-1){
      rep(i,E){
        auto e = es[i];
        if(d[e.from] != INF && d[e.to] > d[e.from] + e.cost){
          d[e.to] = d[e.from] + e.cost;
        }
      }
    }
  }
  bool find_negative_loop(){
    memset(d,0,sizeof(d));
    rep(i,V){
      rep(j,E){
        auto e = es[j];
        if(d[e.to] > d[e.from] + e.cost){
          (d[e.to] = d[e.from] + e.cost);
          if(i == V - 1) return true;
        }
      }
    }
    return false;
  }
  bool check(){
    vector<bool> neg(V,false);
    rep(i,V){
      rep(j,E){
        auto e = es[j];
        if(d[e.from] == INF) continue;
        if(d[e.to] > d[e.from] + e.cost){
          (d[e.to] = d[e.from] + e.cost);
          neg[e.to] = true;
        }
        if(neg[e.from]){
          neg[e.to] = true;
        }
      }
    }
    return neg[V-1];
  }
};

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll v,e;
  cin >> v >> e;
  Bellman_Ford bl(v,e); 
  ll a,b,c;
  rep(i,e){
    cin >> a >> b >> c;
    --a,--b;
    c *= -1;
    es[i] = edge{a,b,c};
  }
  bl.shorter_path(0);
  ll ans = d[v-1];
  if(bl.check()){
    cout << "inf" << endl;
  }
  else
    cout << -ans << endl;
  return 0;
}
