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
  v.erase(unique(all(v)),v.end());
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

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  double m5,m10;
  while(cin>>m5>>m10){
    if(m5 < 35.50 && m10 < 71.0){
      cout << "AAA"<<endl;
    }
    else if(m5 < 37.50 && m10 < 77.0){
      cout << "AA"<<endl;
    }
    else if(m5 < 40.0 && m10 < 83.0){
      cout << "A"<<endl;
    }
    else if(m5 < 43.0 && m10 < 89.0){
      cout << "B" <<endl;
    }
    else if(m5 < 50.0 && m10 < 105.0){
      cout << "C"<<endl;
    }
    else if(m5 < 55.0 && m10 < 116.0){
      cout << "D"<<endl;
    }
    else if(m5 < 70.0 && m10 < 148.0){
      cout << "E"<<endl;
    }
    else cout << "NA"<<endl;
  }
  return 0;
}
