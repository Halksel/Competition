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

void bomb(const int y,const int x, vector<string> &vs){
  vs[y][x] = '0' ;
  int x2 = x, y2 = y;
  rep(i,4){//up
    if(y2>= 0){
      if(vs[y2][x2] == '1'){
        vs[y2][x2] = '0';
        bomb(y2,x2,vs);
      }
    }
    else{
      break;
    }
    --y2 ;
  }
  x2 = x, y2 = y;
  rep(i,4){//down
    if(y2<=7){
      if(vs[y2][x2] == '1'){
        vs[y2][x2] = '0' ;
        bomb(y2,x2,vs);
      }
    }
    else{
      break;
    }
    ++y2;
  }
  x2 = x, y2 = y;
  rep(i,4){//left
    if(x2>= 0){
      if(vs[y2][x2] == '1'){
        vs[y2][x2] = '0';
        bomb(y2,x2,vs);
      }
    }
    else{
      break;
    }
    --x2 ;
  }
  x2 = x, y2 = y;
  rep(i,4){//right
    if(x2<=7){
      if(vs[y2][x2] == '1'){
        vs[y2][x2] = '0' ;
        bomb(y2,x2,vs);
      }
    }
    else{
      break;
    }
    ++x2 ;
  }
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n ,x,y;
  vector<string> vs;
  cin >> n;
  rep(i,n){
    vs.resize(8,"");
    rep(j,8){
      cin >> vs[j];
    }
    cin >> x>> y;
    bomb(y-1,x-1,vs) ;
    cout << "Data " << i+1 << ":" << endl;
    repa(n1,vs){
      cout << n1 << endl;
    }
  }
  return 0;
}
