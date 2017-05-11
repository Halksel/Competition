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

constexpr ll inf = ((1<<30)-1)*2+1 ;

class Bucket{
  public:
  vector<ll> buc,v;
  ll N,sqn,K;
  Bucket(){};
  Bucket(ll n){
    N = n;
    sqn = sqrt(N);
    K = (n + sqn - 1) /sqn;
    buc.assign(K,inf);
    v.assign(K * sqn,inf);
  }
  void update(int x,int y){
    v[x] = y;
    ll m = inf;
    int k = x / sqn;
    for(int i = k * sqn; i < (k + 1) * sqn;++i){
      m = min(m,v[i]);
    }
    buc[k] = m;
  }
  ll query(int x,int y){
    ll res = inf;
    for (int k = 0; k < K; ++k) {
      int l = k * sqn, r = (k + 1) * sqn;
      if (r <= x || y <= l)
        continue;
      if (x <= l && r <= y) {
        res = min(res,buc[k]);
      } else {
        for (int i = max(x, l); i < min(y, r); ++i) {
          res = min(res,v[i]);
        }
      }
    }
    return res;
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
  ll n,q;
  cin >> n >> q;
  Bucket buc(n);
  ll c,x,y;
  rep(i,q){
    cin >> c >> x >> y;
    if(c){
      cout << buc.query(x,y+1) << endl;
    }
    else{
      buc.update(x,y);
    }
  }
  /* buc.Debug(); */
  return 0;
}
