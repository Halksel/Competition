#include <bits/stdc++.h>
using namespace std ;

#define pb(n) push_back(n)
#define fi first
#define se second
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
#define vary(type,name,size,init) vector< type> name(size,init)

#define rep(i,n) for(int i = 0; i < (int)(n);++i)
#define REP(i,a,b) for(int i = (a);i < (int)(b);++i)
#define repi(it,array) for(auto it = array.begin(),end = array.end(); it != end;++it)
#define repa(n,array) for(auto &n :(array))

using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using dict = map<string,int>;
using comd = complex<double>;
using pii = pair<int,int> ;

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

int arr[100001];
void Eratosthenes(int N){
  for(int i = 0; i < N; i++){
    arr[i] = 1;
  }
  arr[1] = 0;
  for(int i = 2; i*i < N ; i++){
    if(arr[i]){
      for(int j = 0; i * (j + 2) < N; j++){
        arr[i *(j + 2)] = 0;
      }
    }
  }
}


int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int N = 50100;
  Eratosthenes(N);
  int n;
  while(cin >> n){
    for(int i = n-1; i > 1; --i){
      if(arr[i] == 1){
        cout << i ;
        break;
      }
    }
    for(int i = n+1; i < N; ++i){
      if(arr[i] == 1){
        cout << " " << i << endl;
        break;
      }
    }
  }
  return 0;
}
