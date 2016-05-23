#include<iostream>
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
//#include<chrono>

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
//#define timenow std::chrono::system_clock::now()
//#define timecal(start,end) std::chrono::duration_cast<std::chrono::milliseconds>((end)-(start)).count()

#define rep(i,n) for(int i = 0; i < (int)(n);++i)
#define repc(i,a,b) for(int i = (a);i < (int)(b);++i)
#define repi(it,array) for(auto it = array.begin(),end = array.end(); it != end;++it)
#define repa(n,array) for(auto n :(array))

typedef long long ll ;
typedef vector<int> vi ;
typedef vector<ll> vl ;
//template<class Value>
//using dict = std::map< string, Value >;
typedef map<string,int> dict;
//using timep = std::chrono::system_clock::time_point ;

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
  int N,M,a = 0,b = 0,c = 0;
  cin >> N >> M ;
  if(N * 3 == M){
    a = 0;
    b = N;
    c = 0;
  }
  else if(N * 3 < M){
    for(int i = N; i ; --i){
      if((i * 4 + (N - i) * 3) == M){
        a = 0;
        b = N-i;
        c = i ;
      }
    }
  }
  else{
    for(int i = N; i; --i)
    {
      if(i * 2 + (N-i) * 3 == M)
      {
        a = i;
        b = N-i;
        c = 0;
      }
    }
  }
  if(a + b + c == 0){
    cout << -1 << " " << -1 << " " << -1 << endl ;
  }
  else{
    cout << a << " " << b << " " << c << endl ;
  }
  return 0;
  }
