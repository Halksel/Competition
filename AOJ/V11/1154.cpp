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
constexpr int inf = ((1<<30)-1)*2+1 ;
constexpr double PI = acos(-1.0) ;
double eps = 1e-10 ;
const int dy[] = {-1,0,1,0,1,-1,1,-1};
const int dx[] = {0,-1,0,1,1,-1,-1,1};
vector<int> v(300001,0),v2(300001,0);
ll s = 0;
void solve(ll n){
  cout << n << ":";
  REP(i,1,s){
    if(n % v2[i] == 0){
      cout << " " << v2[i];
    }
  }
  cout << endl;
}
template<typename T>
void Unique(vector<T> &v){
  sort(all(v));
  v.erase(unique(all(v)),v.end());
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll n;
  rep(i,300001){
    if(i % 7 == 1 || i % 7 == 6){
      v[i] = i;
    }
  }
  Unique(v);
  REP(i,1,v.size()){
    bool f = false;
    REP(j,2,i){
      if(v[j] * v[j] > v[i]) break;
      if(v[i] % v[j] == 0){
        f = true;
        break;
      }
    }
    if(!f){
      v2[s] = v[i];
      ++s;
    }
  }
  while(cin >> n){
    if(n == 1) break;
    solve(n);
  }
  return 0;
}

