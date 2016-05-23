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

ll gcd(ll a,ll b){
  if(a < b) swap(a,b);
  if(b == 0) return a;
  return gcd(b,a%b);
}
ll lcm(ll a,ll b){
  return a*b/ gcd(a,b);
}
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int a1,m1,a2,m2,a3,m3;
  int x = 1, y = 1, z = 1;
  while(cin >>a1>>m1>>a2>>m2>>a3>>m3){
    if(a1+m1+a2+m2+a3+m3 == 0)break;
    ll cnt = 0;
    ll xc = -1,yc=-1,zc=-1;
    while(1){
      x = a1*x % m1;
      ++cnt;
      if(x == 1){
        xc = cnt;
        break;
      }
    }
    cnt = 0;
    while(1){
      y = a2*y % m2;
      cnt++;
      if(y == 1){
        yc = cnt;
        break;
      }
    }
    xc = lcm(xc,yc);
    cnt=0;
    while(1){
      z = a3*z % m3;
      ++cnt;
      if(z == 1 ){
        zc = cnt;
        break;
      }
    }
    cout << lcm(xc,zc)<<endl;
  }
  return 0;
}
