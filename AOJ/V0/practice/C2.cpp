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
#include<chrono>

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
  int n,n2 = 0,n3,tmp;
  vector<string> s = {"10","50","100","500"};
  vi v(4,0),v2(4,0),v3(4,0);
  while(1){
    cin >> n ;
    n3 = n ;
    v2 = v3;
    if(n == 0){
      break ;
    }
    rep(i,4){
      cin >> v[i] ;
    }
    if(v[0] >= (n % 50)/10){
      tmp = (n % 50)/10;
      v[0] -= tmp;
      v2[0] += tmp;
      n -= n % 50 ;
      n2 += tmp * 10 ;
    }
    while(v[0] >= 10){
      if(n >= 100){
        v[0] -= 10;
        v2[0] += 10;
        n -= 100;
        n2 += 100;
      }
      else{
        break;
      }
    }
    while(v[0] >= 5){
      if(n >= 50){
        v[0] -= 5;
        v2[0] += 5;
        n -= 50;
        n2 += 50;
      }
      else{
        break;
      }
    }
    while(v[1] >= 10){
      if(n >= 500){
        v[1] -= 10;
        v2[1] += 10;
        n -= 500 ;
        n2 += 500;
      }
      else{
        break;
      }
    }
    while(v[1] >= 2){
      if(n >= 100){
        v[1] -= 2;
        v2[1] += 2;
        n -= 100 ;
        n2 += 100;
      }
      else{
        break;
      }
    }
    while(v[1] > 0 && n >= 50){
      n -= 50;
      n2 += 50;
      --v[1] ;
      ++v2[1];
    }
    while(v[2] >= 5){
      if(n >= 500){
        v[2] -= 5;
        v2[2] += 5;
        n -= 500 ;
        n2 += 500 ;
      }
      else{
        break;
      }
    }
    while(v[2] > 0 && n >= 100){
      n -= 100;
      n2 += 100 ;
      --v[2];
      ++v2[2];
    }
    while(n >= 500){
      n -= 500;
      n2 += 500 ;
      --v[3];
      ++v[3];
    }
    if(n2 < n3){

    }
    rep(i,4){
      if(v2[i] != 0){
        cout << s[i]+" " << v2[i] << "\n" ;
      }
    }
    cout << "\n" ;
  }
  return 0;
}
