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
typedef map<char,int> dict ;

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
  dict m;
  m['I'] = 1, m['V'] = 5, m['X'] = 10, m['L'] = 50, m['C'] = 100, m['D'] = 500, m['M'] = 1000 ;
  string str;
  bool flag = true;
  vi v(100,0),v2(100,0) ;
  int N,M,y;
  while(cin >> str){
    /*v = v2;
    repc(i,1,str.size()){
      if(m[str[i-1]] > m[str[i]]){
        flag = true ;
      }
      if(m[str[i-1]] < m[str[i]]){
        flag = false ;
      }
      if(flag){
        v[i-1] = m[str[i-1]] ;
      }
      else{
        v[i-1] = -m[str[i-1]] ;
      }
    }
    if(m[str[str.size()-2]] != m[str[str.size()-1]])
    {
      flag =!flag ;
    }
    if(flag){
      v[str.size()-1] = m[str[str.size()-1]] ;
    }
    else{
      v[str.size()-1] = -m[str[str.size()-1]] ;
    }
    cout << accumulate(all(v),0) << endl;*/
  m['I'] = 1, m['V'] = 5, m['X'] = 10, m['L'] = 50, m['C'] = 100, m['D'] = 500, m['M'] = 1000 ;
    y = 0, M = 1001;
    rep(i,str.size()){
      if(str[i] == 'I') N = 1;
      else if(str[i] == 'V') N = 5;
      else if(str[i] == 'X') N = 10;
      else if(str[i] == 'L') N = 50;
      else if(str[i] == 'C') N = 100;
      else if(str[i] == 'D') N = 500;
      else if(str[i] == 'M') N = 1000;
      if(N>M) y -= M*2;
      y += N ;
      M = N ;
    }
    cout << y << endl;
  }
  return 0;
}

