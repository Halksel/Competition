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

inline bool value(int x,int y,int w,int h){
  return (x >= 0 && x < w && y >= 0 && y < h);
}

template<typename T>
void Unique(vector<T> &v){
  sort(all(v));
  v.erase(unique(all(v)),v.end());
}

template<typename T>
T ston(string& str, T n){
  istringstream sin(str) ;
  T num ;
  sin >> num ;
  return num ;
}

void Ans(bool f){
  if(f) cout << "YES"<<endl;
  else cout << "NO"<<endl;
}

constexpr double l2 = log(2);

double EPS = 1e-10;
double add(double a, double b){
  if(abs(a+b) < EPS* (abs(a) + abs(b))) return 0;
  return a+b;
}
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  double p;
  cin >> p;
  double a = -(1/1.5)*l2;
  double lb = 0,ub = p;
  rep(i,3000){
    double mid1 = (2 * lb+ub)/3,mid2 = (lb+ub * 2)/3;
    if(1 + p * pow(2,-mid1/1.5) * l2 * (-1/1.5) < 0){
      lb = mid1;
    }
    if(1 + p * pow(2,-mid2/1.5) * l2 * (-1/1.5) > 0){
      ub = mid2;
    }
//     if(mid1+p/pow(2,mid1/1.5) < mid2+p/pow(2,mid2/1.5)){
//       ub = mid2;
//     }
//     else{
//       lb = mid1;
//     }
  }
  fcout(10) << ub + p/pow(2,ub/1.5) << endl;
  return 0;
}
