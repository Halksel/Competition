#include<iostream>
#include<iomanip>
#include<sstream>
#include<string>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<map>
#include<vector>
#include<queue>
#include<set>
#include<numeric>

using namespace std ;

#define pb(n) push_back(n)
#define fi first
#define se second
#define np string::npos
#define all(r) (r).begin(),(r).end()
#define gsort(st,en) sort((st),(en),greater<int>())
#define vmax(ary) *max_element(all(ary))
#define vmin(ary) *min_element(all(ary))
#define debug(x) cout<<#x<<": "<<x<<endl

#define rep(i,n) for(int i = 0; i < (int)(n);++i)
#define repc(i,a,b) for(int i = (a);i < (int)(b);++i)
#define repi(it,array) for(auto it = array.begin(),end = array.end(); it != end;++it)
#define repa(n,array) for(auto n :(array))

typedef long long ll ;
typedef vector<int> vi ;
typedef vector<ll> vl ;
typedef map<string,int> dict;

constexpr int imax = ((1<<30)-1)*2+1 ;
constexpr int inf = 100000000;
double eps = 1e-10 ;

template <typename T>
void out(vector < T > v)
{
  for(size_t i = 0; i < v.size(); i++)
  {
    debug(v[i]);
  }
}

template<typename T>
string ntos( T i ) {
  ostringstream s ;
  s << i ;
  return s.str() ;
}

template<typename T>
T ston(string str, T n){
  istringstream sin(str) ;
  T num ;
  sin >> num ;
  return num ;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  double x,h;
  while(1){
    cin >> x >> h;
    if(x + h == 0){
      break ;
    }
    cout << fixed << setprecision(6) << x * x + 2 * x * sqrt((x/2)*(x/2) + h* h) << endl;
  }
  return 0;
}
