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

const int mod = 1000000007;
constexpr ll inf = ((1<<30)-1)*2+1 ;
constexpr double PI = acos(-1.0) ;
double eps = 1e-10 ;
const int dy[] = {-1,0,1,0,1,-1,1,-1};
const int dx[] = {0,-1,0,1,1,-1,-1,1};
const int N = 1001;

vector<int> g[N+4];
ll v,d;
void add_edge(int from,int to){
  g[from].push_back(to);
  g[to].push_back(from);
}
vector<ll> f(N+4,0);

void dfs(int k,int c){
  if(f[k] == c) return ;
  f[k] = c;
  for(auto &&e : g[k]){
    dfs(e,c);
  }
}

int solve(){
  int res = 0;
  f = vector<ll>(N+4,0);
  REP(i,2,v+2){
    if(f[i] == 0){
      ++res;
      dfs(i,res);
    }
  }
  return res;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int fib[N+4];
  fib[0] = 1,fib[1] = 1;
  REP(i,2,N+4){
    fib[i] = (fib[i-1] + fib[i-2]) % N;
  }
  while(cin >> v >> d){
    rep(i,N+4){
      g[i].clear();
    }
    REP(i,2,v+2){
      REP(j,i+1,v+2){
        if(abs(fib[i] - fib[j]) < d){
          add_edge(i,j);
        }
      }
    }
    cout << solve()<< endl;
  }
  return 0;
}

