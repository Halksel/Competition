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

inline bool value(int x,int y,int w,int h){
  return (x >= 0 && x < w && y >= 0 && y < h);
}
const ll PrimeMax = 10000001;
int is_prime[PrimeMax];
void Eratosthenes(){
  for(int i = 0; i < PrimeMax; i++){
    is_prime[i] = 1;
  }
  is_prime[0] = 0;
  is_prime[1] = 0;
  for(int i = 2; i < PrimeMax ; i++){
    if(is_prime[i]){
      for(int j = 0; i * (j + 2) < PrimeMax; j++){
        is_prime[i *(j + 2)] = 0;
      }
    }
  }
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll n,N;
  cin >> n;
  N = n;
  vector<ll> v;
  REP(i,1,sqrt(N)+1){
    if(n % i == 0){
      v.push_back(i);
      if(i != n/i)
        v.push_back(n/i);
    }
  }
  ll sum = 0;
  for (auto&& k : v) {
    sum += k;
  }
  sum /= 2;
  if(sum == N){
    cout << "Perfect" << endl;
  }
  else if(sum < N){
    cout << "Deficient" << endl;
  }
  else
    cout << "Abundant" << endl;
  return 0;
}
