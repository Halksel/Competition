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
constexpr ll inf = -1 * (((1<<30)-1)*2+1) ;
constexpr double PI = acos(-1.0) ;
double eps = 1e-10 ;
const int dy[] = {-1,0,1,0,1,-1,1,-1};
const int dx[] = {0,-1,0,1,1,-1,-1,1};

class LazyBucket{
  public:
  vector<ll> buc,v;
  ll N,sqn,K;
  LazyBucket(){};
  LazyBucket(ll n){
    N = n;
    sqn = sqrt(N);
    K = (n + sqn - 1) /sqn;
    buc.assign(K,-inf);
    v.assign(K * sqn,-inf);
  }
  ll find(int x){
    lazyupdate(x/sqn);
    return v[x];
  }
  void lazyupdate(int k){
    if(k >= K) return ;
    if(buc[k] != -inf){
      for(int i = k * sqn; i < (k+1) * sqn;++i){
        v[i] = buc[k];
      }
    }
    buc[k] = -inf;
  }
  void update(int x,int y,int n){
    for (int k = 0; k < K; ++k) {
      int l = k * sqn, r = (k + 1) * sqn;
      if (r <= x || y <= l)
        continue;
      if (x <= l && r <= y) {
        buc[k] = n;
      } else {
        lazyupdate(k);
        for (int i = max(x, l); i < min(y, r); ++i) {
          v[i] = n;
        }
      }
    }
  }
  void Debug(){
    for(int i = 0; i < N;++i){
      cout << buc[i/sqn] << ' ';
    }
    cout << endl;
    for(int i = 0; i < N;++i){
      cout << v[i] << ' ';
    }
    cout << endl;
  }
};

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll n, q,s,t,x,a;
  cin >> n >> q;
  LazyBucket buc(n);
  rep(i,q){
    cin >> a;
    if(a){
      cin >> s;
      cout << buc.find(s) << endl;
    }
    else{
      cin >> s >> t >> x;
      buc.update(s,t+1,x);
    }
  }
  return 0;
}
