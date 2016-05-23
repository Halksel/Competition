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

#define rep(i,n) for(int i = 0; i < (int)(n);++i)
#define repc(i,a,b) for(int i = (a);i < (int)(b);++i)
#define repi(it,array) for(auto it = array.begin(),end = array.end(); it != end;++it)
#define repa(n,array) for(auto n :(array))


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
  int n,i = 0;
  string s;
  vector<int> v;
  vector<string> vs;
  while(1){
    cin >> n >> s;
    v.pb(n);
    vs.pb(s);
    if(s == "="){
      break;
    }
  }
  while(1){
    if(vs[i] == "="){
      break;
    }
    else if(vs[i] == "+"){
      v[i+1] += v[i];
    }
    else if(vs[i] == "-"){
      v[i+1] = v[i] - v[i+1];
    }
    else if(vs[i] == "*"){
      v[i+1] *= v[i] ;
    }
    else if(vs[i] == "/"){
      v[i+1] = floor(v[i] / v[i+1]);
    }
    ++i;
  }
  cout <<  v[v.size()-1] << endl;
  return 0;
}
