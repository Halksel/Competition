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
#include<bitset>
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
  string s ;
  int d;
  vi v = {1,0,0} ;
  while(cin >> s ){
    if(s[0] == 'A'){
      d = v[0] ;
      if(s[2] == 'B'){
        v[0] = v[1] ;
        v[1] = d ;
      }
      if(s[2] == 'C'){
        v[0] = v[2] ;
        v[2] = d ;
      }
    }
    else if(s[0] == 'B'){
      d = v[1] ;
      if(s[2] == 'C'){
        v[1] = v[2] ;
        v[2] = d ;
      }
      if(s[2] == 'A'){
        v[1] = v[0] ;
        v[0] = d ;
      }
    }
    else{
      d = v[2] ;
      if(s[2] == 'A'){
        v[2] = v[0] ;
        v[0] = d ;
      }
      if(s[2] == 'B'){
        v[2] = v[1] ;
        v[1] = d ;
      }
    }
  }
  if(v[0] == 1){
    cout << 'A' << endl ;
  }
  if(v[1] == 1){
    cout << 'B' << endl ;
  }
  if(v[2] == 1){
    cout << 'C' << endl ;
  }
  return 0;
}
