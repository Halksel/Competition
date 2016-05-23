#include<iostream>
#include<sstream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<map>
#include<numeric>

using namespace std ;

#define pb(n) push_back(n)
#define fi first
#define se second
#define all(r) (r).begin(),(r).end()
#define gsort(r) sort(all(r),greater<int>())
#define vmax(ary) *max_element(all(ary))
#define debug(x) cout<<#x<<": "<<x<<endl

#define rep(i,n) for(int i = 0; i < (int)(n);++i)
#define repc(i,a,b) for(int i = (a);i <(b);++i)
#define repa(n,array) for(auto n :(array))

typedef long long ll ;
typedef vector<int> vi ;
typedef vector<ll> vl ;
//template<class Value>
//using dict = std::map< string, Value >;
typedef map<string,int> dict ;

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
  int a,b,an,bn,time = 0,tl = 0,ans = 0, mit = 0;
  vi va,vb,vc;
  cin >> a >> b ;
  while(cin >> an>>bn){
    va.pb(an) ;
    vb.pb(bn) ;
    vc.pb(an-bn) ;
  }
  rep(i,va.size()){
    time += va[i] ;
    tl += vb[i] ;
  }
  if(time <= b){
    cout << 0 << endl ;
  }
  else if(tl > b){
    cout << -1 << endl ;
  }
  else{
    gsort(vc) ;
    rep(i,vc.size()){
      mit += vc[i] ;
      ++ans ;
      if(time - mit <= b){
        break ;
      }
    }
    cout << ans << endl ;
  }
  return 0;
}
