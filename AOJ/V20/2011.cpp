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
const int dy[] = {-1,0,1,0,1,-1,1,-1};
const int dx[] = {0,-1,0,1,1,-1,-1,1};

template<typename T> 
void merge_set(set<T> &a, set<T> &b) {
  // b のほうが a よりサイズが小さいようにして
  if (a.size() < b.size()) swap(a, b);
  // a に b の中身を全部入れるだけ
  a.insert(b.begin(), b.end());
  b = a;
  /* b->clear(); */
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll n,k;
  while(cin >> n && n){
    vector<vector<ll>> v(32);
    vector<set<ll>> vs(n+1);
    rep(i,n){
      cin >> k;
      ll u;
      vs[i].insert(i);
      rep(j,k){
        cin >> u;
        v[u].push_back(i);
      }
    }
    ll cnt = 0;
    ll ans = -1;
    REP(i,1,31){
      rep(j,v[i].size()){
        rep(k,v[i].size()){
          vs[v[i][j]].insert(v[i][k]); 
          merge_set(vs[v[i][j]],vs[v[i][k]]);
        }
      }
      rep(j,n){
        if(vs[j].size() == n){
          ans = i;
          break;
        }
      }
      if(ans != -1) break;
    }
    std::cout << ans << std::endl;
  }
  return 0;
}
