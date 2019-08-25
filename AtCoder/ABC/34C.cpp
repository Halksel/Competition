#include <bits/stdc++.h>
using namespace std ;

#define pb(n) push_back(n)
#define fi first
#define se second
#define np string::npos
#define X real()
#define Y imag()
#define value(x,y,w,h) (x >= 0 && x < w && y >= 0 && y < h)
#define all(r) (r).begin(),(r).end()
#define gsort(st,en) sort((st),(en),greater<int>())
#define vmax(ary) *max_element(all(ary))
#define vmin(ary) *min_element(all(ary))
#define debug(x) cout<<#x<<": "<<x<<endl
#define fcout(n) cout<<fixed<<setprecision((n))
#define scout(n) cout<<setw(n)

#define rep(i,n) for(int i = 0; i < (int)(n);++i)
#define repc(i,a,b) for(int i = (a);i < (int)(b);++i)
#define repi(it,array) for(auto it = array.begin(),end = array.end(); it != end;++it)
#define repa(n,array) for(auto &n :(array))

typedef long long ll ;
typedef deque<int> di ;
typedef deque<ll> dl ;
typedef map<string,int> dict;
typedef complex<double> comd;
typedef pair<int,int> pii;

constexpr int imax = ((1<<30)-1)*2+1 ;
constexpr int inf = 100000000;
constexpr double PI = acos(-1.0) ;
double eps = 1e-10 ;
const int dy[] = {-1,0,1,0};
const int dx[] = {0,-1,0,1};

double CalcDist(comd p1, comd p2){
  return sqrt(pow(p1.X - p2.X,2.0) + pow(p1.Y -p2.Y,2.0));
}

template <typename T>
void out(deque < T > d)
{
  for(size_t i = 0; i < d.size(); i++)
  {
    debug(d[i]);
  }
}

template<typename T>
T ston(string& str, T n){
  istringstream sin(str) ;
  T num ;
  sin >> num ;
  return num ;
}

const ll M = 1000000007;
ll powmod(ll a, ll p){
  ll ans = 1;
  ll mul = a;
  for(; p > 0; p >>= 1, mul = (mul*mul) ){ //初期条件なし、pを2で割り続け、mulの値を更新
    if((p & 1) == 1) ans = ( ans * mul) ;//pが1なら ansの値を更新
  }
  /* powmod(2,4){　modのかけるときも成り立つあれ
     1loop
     mul = 2 * 2 %mod = 4;
     p 4 -> 2;
     2loop;
     mul = 4 * 4 % mod = 16;
     p 2 -> 1;
     ans = 16 ;
     }*/
  return ans;
}
ll fact[MAX_N];

void setFact(int N){
  fact[0] = 1;
  for(int i = 1; i < N; ++i){//階乗を計算し、配列に格納、互いに素なため割り算は成り立つ
    fact[i] = fact[i-1]*i;
    fact[i] %= mod;
  }
}
ll solve(int n,int a){
  ll ans = 1;
  for(int i = n+a; i > n;--i){
    ans = ans*i;
  }
  rep(i,a){
    ans = (ans * mypow((ll)(i+1) ,(M-2)))%M;
  }
  return ans;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int W,H;
  cin >> W >> H;
  ll num =solve(max(W,H)-1,min(H,W)-1);
  cout << num % 1000000007 << endl;
  return 0;
}
