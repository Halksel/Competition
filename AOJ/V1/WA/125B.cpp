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

const int mod = 1000000007;
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

  ll y,y2,d,d2,m,m2;
  while(cin >> y >> m >> d >> y2 >> m2 >> d2){
    if(y < 0 || m <= 0 || d <= 0 || y2 < 0|| m2 <= 0|| d2 <= 0) break;
    if(m < 3){
      --y,m+=12;
    }
    ll c = floor(y/100);
    ll g = 5 * c+floor(c/4);
    ll h1 = (d + floor(26*(m+1)/10) + (ll)y % 100 + floor(y/4) + g);
//     ll h1 = (d + y + floor(y/4) + c - 2*c + floor(13 * (m+1) / 5));
//     ll h1 = y + y/4 - y/100 + y/400+(13*m+8)/5 + d;
    ll c2 = floor(y2/100);
    ll g2 = 5 * c2+floor(c2/4);
    ll h2 = (d2 + floor(26*(m2+1)/10) + (ll)y2 % 100 + floor(y2/4) + g2);
//     ll h2 = (d2 + y2 + floor(y2/4) + c2 - 2*c2 + floor(13 * (m2+1) / 5));
//     ll h2 = y2 + y2/4 - y2/100 + y2/400 + (13*m+8)/5+d2;
//     debug(h2);
//     debug(h1);
    cout << h2 - h1 << endl;
  }
  return 0;
}
