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
#define fcout(n) cout<<fixed<<setprecision((n))
#define scout(n) cout<<setw(n)

#define rep(i,n) for(int i = 0; i < (int)(n);++i)
#define repc(i,a,b) for(int i = (a);i < (int)(b);++i)
#define repi(it,array) for(auto it = array.begin(),end = array.end(); it != end;++it)
#define repa(n,array) for(auto n :(array))

typedef long long ll ;
typedef deque<int> di ;
typedef deque<ll> dl ;
typedef map<string,int> dict;

constexpr int imax = ((1<<30)-1)*2+1 ;
constexpr int inf = 100000000;
constexpr double PI = atan(1.0) * 4 ;
double eps = 1e-10 ;

template <typename T>
void out(deque < T > d)
{
  for(size_t i = 0; i < d.size(); i++)
  {
    debug(d[i]);
  }
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
  int num,el = 1,x,y;
  while(cin >>num){
    if(num == 0){
      break;
    }
    el = 1;
    deque<di> ddi(num,di(num,0));
    x = num/2+1,y = num/2;
    ddi[x][y] = el;
    while(el != num*num){
      ++x ;++y ;
      if(x >= num){
        x = 0;
      }
      if(y >= num){
        y = 0;
      }
      if(ddi[x][y] == 0){
        ++el ;
        ddi[x][y] = el ;
      }
      else{
        --y;
        ++x;
        if(y < 0 ){
          y = num-1;
        }
        if(x >= num){
          x = 0;
        }
        ++el ;
        ddi[x][y] = el ;
      }
    }
    rep(n,num){
      rep(n2,num){
        scout(4) << ddi[n][n2] ;
      }
      cout << endl ;
    }
  }
  return 0;
}
