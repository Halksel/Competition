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

int calc(int p){
  if(p % 50){
    p += 50 - p%50;
  }
  return p;
}
const int colum[7][7] = {{0,6,13,18,23,43,58},{300,0,7,12,17,37,52},{500,350,0,5,10,30,45},{600,450,250,0,5,25,40},{700,600,400,250,0,20,35},{1350,1150,1000,850,600,0,15},{1650,1500,1350,1300,1150,500,0}};

bool check(int h1,int m1){
  if((h1 == 17 && m1 >= 30 )||(17 < h1 && h1 < 19) || (h1 == 19 && m1 <= 30)){
    return true;
  }
  return false;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int dt,at,h1,m1,h2,m2;
  while(cin >> dt&&dt){
    cin >> h1 >> m1 >> at >> h2 >> m2;
    --dt,--at;
    if(at < dt){
      swap(at,dt);
    }
    int price = colum[at][dt];
    if((check(h1,m1) || check(h2,m2)) && colum[dt][at] <= 40){
      price /= 2;
      price = calc(price);
    }
    cout << price << endl;
  }
  return 0;
}
