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

ll da[300001],db[300001],v[300001];

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll N;
  cin >> N;
  rep(i,3*N){
    cin >> v[i];
  }
  priority_queue<ll,vector<ll>,greater<ll>> a;
  ll A = 0,B = 0;
  rep(i, N * 2){
    A += v[i];
    a.push(v[i]);
    if(i >= N){
      ll k = a.top(); a.pop();
      A -= k;
    }
    if(i >= N -1){
      da[i] = A;
    }
  }
  priority_queue<ll> b;
  for(int i = 3*N - 1; i >= N; i--){
    B += v[i];
    b.push(v[i]);
    if(i < 2 * N){
      ll k = b.top(); b.pop();
      B -= k;
    }
    if(i <= 2 * N){
      db[i] = B;
    }
  }
  ll ans = -10e17;
  for(int i = N - 1; i < 2 * N; i++){
    /* cout << da[i] << ' ' << db[i+1] << endl; */
    ans = max(ans,da[i]-db[i+1]) ;
  }
  cout << ans << endl;

  return 0;
}
