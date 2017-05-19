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
  vector<ll> buc,v,s;
  ll N,sqn,K;
  LazyBucket(){};
  LazyBucket(ll n){
    N = n;
    sqn = sqrt(N);
    K = (n + sqn - 1) /sqn;
    buc.assign(K,0);
    s.assign(K,0);
    v.assign(K * sqn,0);
  }
  ll getSum(int x,int y){
    ll res = 0;
    for (int k = 0; k < K; ++k) {
      int l = k * sqn, r = (k + 1) * sqn;
      if (r <= x || y <= l)
        continue;
      if (x <= l && r <= y) {
        res += s[k] + buc[k] * sqn;
      } else {
        lazyupdate(k);
        for (int i = max(x, l); i < min(y, r); ++i) {
          res += v[i] + buc[k];
        }
      }
    }
    return res;
  }
  void lazyupdate(int k){
    if(k >= K) return ;
    if(buc[k] != 0){
      for(int i = k * sqn; i < (k+1) * sqn;++i){
        v[i] += buc[k];
        s[k] += buc[k];
      }
    }
    buc[k] = 0;
  }
  void add(ll x,ll y,ll n){
    for (ll k = 0; k < K; ++k) {
      ll l = k * sqn, r = (k + 1) * sqn;
      if (r <= x || y <= l)
        continue;
      if (x <= l && r <= y) {
        buc[k] += n;
      }
      else {
        lazyupdate(k);
        for (int i = max(x, l); i < min(y, r); ++i) {
          v[i] += n;
          s[k] += n;
        }
      }
    }
  }
  void Debug(){
    cout << "sqn " << sqn << endl;
    for(int i = 0; i < N;++i){
      cout << buc[i/sqn] << ' ';
    }
    cout << endl;
    for(int i = 0; i < N;++i){
      cout << s[i/sqn] << ' ';
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
  LazyBucket buc(n+1);
  rep(i,q){
    /* buc.Debug(); */
    cin >> a;
    if(a){
      cin >> s >> t;
      cout << buc.getSum(s-1,t) << endl;
    }
    else{
      cin >> s >> t >> x;
      buc.add(s-1,t,x);
    }
  }
  return 0;
}
