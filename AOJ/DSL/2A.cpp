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
class RMQ{
  public:
  int n, dat[2*MAX_N - 1];

  void init(int n_){
    n = 1;
    while(n < n_){
      n *= 2;
    }

    for(int i =0; i < 2*n-1;++i){
      dat[i] = INT_MAX;
    }
  }

  void update(int k, int a){
    k += n-1;
    dat[k] = a;
    while(k>0){
      k = (k-1)/2;
      dat[k] = min(dat[k*2+1],dat[k*2+2]);
    }
  }
  //min = query(a,b,0,0,n)
  int rec(int a,int b,int k,int l, int r){
    int vl,vr;
    if(r <= a || b <= l){
      return INT_MAX;
    }
    if(a <= l && r <= b){
      return dat[k];
    }
    else{
      vl = rec(a,b,k*2+1,l,(l+r)/2);
      vr = rec(a,b,k*2+2,(l+r)/2,r);
    }
    return min(vl,vr);
  }
  int query(int a,int b){
    return rec(a,b+1,0,0,n);
  }
};

const ll mod = 1e9+7;
constexpr ll inf = ((1<<30)-1)*2+1 ;
constexpr double PI = acos(-1.0) ;
double eps = 1e-10 ;
const int dy[] = {-1,0,1,0,1,-1,1,-1};
const int dx[] = {0,-1,0,1,1,-1,-1,1};

inline bool value(int x,int y,int w,int h){
  return (x >= 0 && x < w && y >= 0 && y < h);
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll n,q,c,x,y;
  RMQ rmq;
  cin >> n >> q;
  rmq.init(n);
  rep(i,q){
    cin >> c >> x >> y;
    if(c == 0){
      rmq.update(x,y);
    }
    else{
      cout << rmq.query(x,y) << endl;
    }
  }
  return 0;
}
