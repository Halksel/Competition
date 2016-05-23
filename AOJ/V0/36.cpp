#include <bits/stdc++.h>
using namespace std ;

#define pb(n) push_back(n)
#define fi first
#define se second
#define all(r) (r).begin(),(r).end()
#define gsort(st,en) sort((st),(en),greater<int>())
#define vmax(ary) *max_element(all(ary))
#define vmin(ary) *min_element(all(ary))
#define debug(x) cout<<#x<<": "<<x<<endl
#define fcout(n) cout<<fixed<<setprecision((n))
#define scout(n) cout<<setw(n)
#define vary(type,name,size,init) vector< type> name(size,init)

#define rep(i,n) for(int i = 0; i < (int)(n);++i)
#define REP(i,a,b) for(int i = (a);i < (int)(b);++i)
#define repi(it,array) for(auto it = array.begin(),end = array.end(); it != end;++it)
#define repa(n,array) for(auto &n :(array))

using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using dict = map<string,int>;
using pii = pair<int,int> ;

constexpr int imax = ((1<<30)-1)*2+1 ;
constexpr int inf = 100000000;
constexpr double PI = acos(-1.0) ;
double eps = 1e-10 ;
const int dy[] = {-1,0,1,0};
const int dx[] = {0,-1,0,1};

inline bool value(int x,int y,int w,int h){
  return (x >= 0 && x < w && y >= 0 && y < h);
}

template<typename T>
void Unique(vector<T> &v){
  sort(all(v));
  v.erase(all(v),v.end());
}

template<typename T>
T ston(string& str, T n){
  istringstream sin(str) ;
  T num ;
  sin >> num ;
  return num ;
}

void Ans(bool f){
  if(f) cout << "YES"<<endl;
  else cout << "NO"<<endl;
}
void Solve(vector<vector<char>> vvc){
  int x = 0,y = 0;
  rep(i,8){
    rep(j,8){
      if(vvc[j][i] == '1'){
        x = j;
        y = i;
        j = 8;
        i = 8;
        break;
      }
    }
  }
  if(x + 1 < 8 && vvc[x+1][y] == '1'){//A,C,E,G
    if(x+2 < 8 && vvc[x+2][y] == '1'){
      cout << 'C'<<endl;
    }
    else if( x-1 >= 0 && y+1 < 8&& vvc[x-1][y+1] == '1'){
      cout << 'G'<<endl;
    }
    else if( y +1 < 8 && vvc[x][y+1] == '1'){
      cout << 'A'<<endl;
    }
    else{
      cout << 'E'<<endl;
    }
  }
  else{//B,D,F
    if(y+2 < 8 && vvc[x][y+2] == '1'){
      cout << 'B'<<endl;
    }
    else if( x+1 < 8 && y + 1 < 8&& vvc[x+1][y+1] == '1'){
      cout << 'F'<<endl;
    }
    else{
      cout << 'D'<<endl;
    }
  }
}
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  while(1){
    vector<vector<char>> v(8,vector<char>(8,0));
    rep(i,8){
      rep(j,8){
        cin>> v[j][i];
      }
    }
    if(cin.eof()){
      break;
    }
    Solve(v);
  }
  return 0;
}
