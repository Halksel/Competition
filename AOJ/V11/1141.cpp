#include <bits/stdc++.h>
using namespace std ;

#define pb(n) push_back(n)
#define fi first
#define se second
#define all(r) (r).begin(),(r).end()
#define gsort(st,en) sort((st),(en),greater<int>())
#define vmax(ary) *max_element(all(ary))
#define vmin(ary) *min_element(all(ary))
#define debug(x) cout<<#x<<": "<<x<<endl
#define fcout(n) cout<<fixed<<setprecision((n))
#define scout(n) cout<<setw(n)
#define vary(type,name,size,init) vector< type> name(size,init)

#define rep(i,n) for(int i = 0; i < (int)(n);++i)
#define REP(i,a,b) for(int i = (a);i < (int)(b);++i)
#define repi(it,array) for(auto it = array.begin(),end = array.end(); it != end;++it)
#define repa(n,array) for(auto &n :(array))

using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using dict = map<string,int>;
using pii = pair<int,int> ;
using pll = pair<ll,ll> ;

const int mod = 1000000007;
constexpr int imax = ((1<<30)-1)*2+1 ;
constexpr int inf = 100000000;
constexpr double PI = acos(-1.0) ;
double eps = 1e-10 ;
const int dy[] = {-1,0,1,0};
const int dx[] = {0,-1,0,1};
const int PrimeMax = 1000001;
int is_prime[PrimeMax];
void Eratosthenes(int N){
  for(int i = 0; i < N; i++){
    is_prime[i] = 1;
  }
  is_prime[1] = 0;
  for(int i = 2; i*i < N ; i++){
    if(is_prime[i]){
      for(int j = 0; i * (j + 2) < N; j++){
        is_prime[i *(j + 2)] = 0;
      }
    }
  }
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  Eratosthenes(PrimeMax);
  ll a, d, n;
  while(cin >> a >> d >> n && a && d && n){
    ll cnt = 0;
    while(n){
      if(is_prime[a + cnt * d]){
        --n;
        if(!n) cout << a+cnt * d<<endl;
      }
      ++cnt;
    }
  }
  return 0;
}
