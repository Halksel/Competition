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
int N,K,R[101];
vector<int> f(101);
double rate = 0.0;
double solve(double r,int i,int k,vector<int> a){
  double ma = r;
  if(k < K){
    if(i+1<=N){
      if(r < R[i] && N-(i+1)+k+1>=K){
        a[i] = 1;
        ma = max(ma,solve((r+R[i])/2,i+1,k+1,a));
        //       if( ma != r){
        //         rep(i,N)cout << a[i] << " ";
        //         cout << endl;
        //       }
      }
      if(N-(i+1)+k>=K){
        a[i]= 0;
        ma = max(ma,solve(r,i+1,k,a));
        //       if( ma != r){
        //         rep(i,N)cout << a[i] << " ";
        //         cout << endl;
        //       }
      }
    }
  }
  return ma;
}
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin >> N >> K;
  rep(i,N) cin >> R[i];
  sort(R,R+N);
  double ans = 0.0;
  rep(i,K){
    rate = (rate+R[N - K +i])/2;
  }
  fcout(10) << rate << endl;
  return 0;
}
