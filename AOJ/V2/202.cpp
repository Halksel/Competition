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
#define vvl(v,w,h,init) vector<vector<ll>> v(w,vector<ll>(h,init));

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
const int dy[] = {-1,0,1,0,1,-1,1,-1};
const int dx[] = {0,-1,0,1,1,-1,-1,1};

ll n,x;
vector<ll> v;
set<ll> s;
void dfs(ll sum){
  if(sum <= x && s.insert(sum).se){
    rep(i,n){
      dfs(v[i]+sum);
    }
  }
  return;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  while(cin >> n >> x && n && x){
    s.clear();
    v.clear();
    v.resize(n);
    rep(i,n){
      cin >> v[i];
    }
    ll ans = 0;
    dfs(0);
    for(auto N:s){
      if(N % n){
        ans = max(ans,N);
      }
    }
    if(ans) cout << ans << endl;
    else cout << "NA"<<endl;
  }
  return 0;
}
