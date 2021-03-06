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

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int num ;
  cin >> num ;
  auto func = [&]()->int{return num/1000;}() ;
  if(num < 100){
    cout << "00" << endl ;
  }
  else if(num <= 5000){
    if(num >= 1000){
      cout << num / 100 << endl ;
    }
    else{
      cout << "0" << num/100 << endl ;
    }
  }
  else if(num <= 30000){
    cout << func+50 << endl ;
  }
  else if(num <= 70000){
    cout << (func-30)/5+80 << endl ;
  }
  else{
    cout << 89 << endl ;
  }
  return 0;
}
