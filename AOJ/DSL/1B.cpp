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

const int MAX_N = 1 << 17;

class Bucket{
  public:
  vector<ll> buc,v;
  ll N,sqn,K;
  Bucket(){};
  Bucket(ll n){
    N = n;
    sqn = sqrt(N);
    K = (n + sqn - 1) /sqn;
    buc.resize(K);
    v.resize(K * sqn);
  }
  void add(int x,int y){
    v[x] += y;
    ll sum = 0;
    int k = x / sqn;
    for(int i = k * sqn; i < (k + 1) * sqn;++i){
      sum += v[i];
    }
    buc[k] = sum;
  }
  ll query(int x,int y){
    ll res = 0;
    for (int k = 0; k < K; ++k) {
      int l = k * sqn, r = (k + 1) * sqn;
      if (r <= x || y <= l)
        continue;
      if (x <= l && r <= y) {
        res += buc[k];
      } else {
        for (int i = max(x, l); i < min(y, r); ++i) {
          res += v[i];
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
  Bucket buc(n+1);
  ll a,s,t,x;
  rep(i,q){
    cin >> s >> t >> x;
    if(s){
      cout << buc.query(t-1,x)<<endl;
    }
    else{
      buc.add(t-1,x);
    }
  }
  /* buc.Debug(); */
  return 0;
}
