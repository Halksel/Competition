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

#define rep(i,n) for(ll i = 0; i < (ll)(n);++i)
#define REP(i,a,b) for(ll i = (a);i < (ll)(b);++i)
#define repi(it,array) for(auto it = array.begin(),end = array.end(); it != end;++it)
#define repa(n,array) for(auto &n :(array))

using ll = long long;
using pii = pair<ll,ll> ;
using pll = pair<ll,ll> ;

class RMQ{//minimum
  public:
    ll n;
    vector<ll> dat;
    const ll def=-(1LL<<55LL);
    RMQ(){}
    RMQ(ll n_){init(n_);}
    RMQ(ll n_,ll* a){init(n_);construct(n_,a);}
    void init(ll n_){
      n = 1;
      while(n < n_){
        n *= 2;
      }
      dat.clear();
      dat.resize(2 * n -1 ,def);
    }
    void construct(ll n_, ll* a){
      for(ll i=0;i<n_;i++) dat[i+n-1]=a[i];
      for(ll i=n-2;i>=0;i--)
        dat[i]=max(dat[i*2+1],dat[i*2+2]);
    }
    void update(ll k, ll a){
      k += n-1;
      dat[k] = a;
      while(k>0){
        k = (k-1)/2;
        dat[k] = max(dat[k*2+1],dat[k*2+2]);
      }
    }
    //min = query(a,b,0,0,n)
    ll rec(ll a,ll b,ll k,ll l, ll r){
      ll vl,vr;
      if(r <= a || b <= l) return def;
      if(a <= l && r <= b) return dat[k];
      vl = rec(a,b,k*2+1,l,(l+r)/2);
      vr = rec(a,b,k*2+2,(l+r)/2,r);
      return max(vl,vr);
    }
    ll query(ll a,ll b){
      return rec(a,b,0,0,n);
    }
};
ll p,n;
ll x[210002],y[210002];
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin >> n >> p;
  ll ans = 0;
  REP(i,0,n){
    cin >> x[i];
  }
  REP(i,1,n){
    y[i] = y[i-1] + x[i];
  }
  RMQ q(n,y);
  rep(i,n){
    ll base = y[i] - x[i];
    if(q.query(i,n) < base + p) continue;
    ll l = i,r = n;
    while(l+1 < r){
      ll m = (l+r)/2;
      if(q.query(m,r) >= base +  p){
        l = m;
      }
      else
        r = m;
    }
    ans = max(ans,r-i);
  }
  std::cout << ans << std::endl;
  return 0;
}
