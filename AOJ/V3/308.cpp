#include <bits/stdc++.h>
using namespace std ;

#define pb(n) push_back(n)
#define fi first
#define se second
#define all(r) (r).begin(),(r).end()
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
using vi = vector<int>;
using vl = vector<ll>;
using dict = map<string,int>;
using pii = pair<int,int> ;
using pll = pair<ll,ll> ;

const int mod = 1000000007;
constexpr int inf = ((1<<30)-1)*2+1 ;
constexpr double PI = acos(-1.0) ;
double eps = 1e-10 ;
const int dy[] = {-1,0,1,0,1,-1,1,-1};
const int dx[] = {0,-1,0,1,1,-1,-1,1};

inline bool value(int x,int y,int w,int h){
  return (x >= 0 && x < w && y >= 0 && y < h);
}

template<typename T>
void Unique(vector<T> &v){
  sort(all(v));
  v.erase(unique(all(v)),v.end());
}
template<typename T,typename U>
ll FindErase(T &v,U tar){
  ll cnt = 0;
  for(auto it = v.begin(); it != v.end();){
    if(*it == tar){
      it = v.erase(it);
      ++cnt;
    }
    else{
      ++it;
    }
  }
  return cnt;
}

struct Edge{
  int to;
  long long cost;
};

struct NODE{
  int pos;
  long long cost;
};
bool operator < (const NODE &a,const NODE &b){
  return a.cost > b.cost;
}
vector<Edge> g[100000],rg[100000];

int N;
vector<int> memo(500,inf),tmp;
bool dfs(int p,int k){
  bool f = false;
  if(memo[p] == 0) return true;
  if(memo[p] != inf) return false;
  memo[p] = k;
  for(auto n: g[p]){
    f |= dfs(n.to,k+1);
  }
  return f;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  int u,d;
  string s;
  set<int> st;
  const int X = 200;
  rep(i,n){
    cin >> u >> s >> d;
    st.insert(u);
    st.insert(d+X);
    if(s == "lock"){
      g[d+X].push_back({u,1});
    }
    else{
      g[u].push_back({d+X,1});
    }
  }
  bool ans = false;
  tmp = memo;
  for(auto n: st){
    memo = tmp;
    ans |= dfs(n,0);
  }
  cout << ans << endl;
  return 0;
}
