#include<iostream>
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
#define gsort(st,en) sort((st),(en),greater<int>())
#define vmax(ary) *max_element(all(ary))
#define debug(x) cout<<#x<<": "<<x<<endl

#define rep(i,n) for(int i = 0; i < (n);++i)
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
T out(vector < T > v)
{
  for(size_t i = 0; i < v.size(); i++)
  {
    debug(v[i]);
  }
}

string Judgedir(double a){
  string dir ;
  if(3487.5 <= a || a < 112.5){
    dir = "N" ;
  }
  else if(112.5 <= a && a <= 337.5 ){
    dir = "NNE" ;
  }
  else if( a <= 562.5 ){
    dir = "NE" ;
  }
  else if( a <= 787.5){
    dir = "ENE" ;
  }
  else if(a <= 1012.5){
    dir = "E" ;
  }
  else if(a <= 1237.5){
    dir = "ESE" ;
  }
  else if(a <= 1462.5){
    dir = "SE" ;
  }
  else if(a <= 1687.5){
    dir = "SSE" ;
  }
  else if(a <= 1912.5){
    dir = "S" ;
  }
  else if(a <= 2137.5){
    dir = "SSW" ;
  }
  else if(a <= 2362.5){
    dir = "SW" ;
  }
  else if(a <= 2587.5){
    dir = "WSW" ;
  }
  else if(a <= 2812.5){
    dir = "W" ;
  }
  else if(a <= 3037.5){
    dir = "WNW" ;
  }
  else if(a <= 3262.5){
    dir = "NW" ;
  }
  else if(a <= 3487.5){
    dir = "NNW" ;
  }
  else{
    dir = "N" ;
  }
  return dir ;
}

int JudgeWP(int num){
  double wp = 1.0 * num / 60 ;
  wp = int(wp * 10 + 0.5) / 10.0 ;
  if(wp <= 0.2){
    wp = 0 ;
  }
  else if(wp <= 1.5){
    wp = 1 ;
  }
  else if(wp <= 3.3){
    wp = 2 ;
  }
  else if (wp <= 5.4){
    wp = 3 ;
    }
  else if(wp <= 7.9){
    wp = 4 ;
  }
  else if(wp <= 10.7){
    wp = 5 ;
  }
  else if(wp <= 13.8){
    wp = 6 ;
  }
  else if(wp <= 17.1){
    wp = 7 ;
  }
  else if(wp <= 20.7){
    wp = 8 ;
  }
  else if(wp <= 24.4){
    wp = 9 ;
  }
  else if(wp <= 28.4){
    wp = 10 ;
  }
  else if(wp <= 32.6){
    wp = 11 ;
  }
  else{
    wp = 12 ;
  }
  return (int)wp ;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  double a,b;
  int W ;
  string dir ;
  cin >> a >> b ;
  dir = Judgedir(a) ;
  if((W = JudgeWP(b)) == 0){
    cout << "C " ;
  }
  else{
    cout << dir << " ";
  }
  cout << W << endl ;
  return 0;
}
