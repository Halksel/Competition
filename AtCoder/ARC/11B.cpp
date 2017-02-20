#include <bits/stdc++.h>
using namespace std ;

#define pb(n) push_back(n)
#define fi first
#define se second
#define all(r) begin(r),end(r)
#define vmax(ary) *max_element(all(ary))
#define vmin(ary) *min_element(all(ary))
#define debug(x) cout<<#x<<": "<<x<<endl
#define fcout(n) cout<<fixed<<setprecision((n))
#define scout(n) cout<<setw(n)
#define vary(type,name,size,init) vector< type> name(size,init)
#define vvl(v,w,h,init) vector<vector<ll>> v(w,vector<ll>(h,init))
#define mp(a,b) make_pair(a,b)

#define rep(i,n) for(int i = 0; i < (int)(n);++i)
#define REP(i,a,b) for(int i = (a);i < (int)(b);++i)
#define repi(it,array) for(auto it = array.begin(),end = array.end(); it != end;++it)
#define repa(n,array) for(auto &n :(array))

using ll = long long;
using pii = pair<int,int> ;
using pll = pair<ll,ll> ;

template<typename T>
void O(T t){
  cout << t << endl;
}

const int mod = 1000000007;
constexpr ll inf = ((1<<30)-1)*2+1 ;
constexpr double PI = acos(-1.0) ;
double eps = 1e-10 ;
const int dy[] = {-1,0,1,0,1,-1,1,-1};
const int dx[] = {0,-1,0,1,1,-1,-1,1};

inline bool value(int x,int y,int w,int h){
  return (x >= 0 && x < w && y >= 0 && y < h);
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  map<char,int> m;
  m['b'] = 1;
  m['c'] = 1;
  m['w'] = 2;
  m['d'] = 2;
  m['t'] = 3;
  m['j'] = 3;
  m['f'] = 4;
  m['q'] = 4;
  m['l'] = 5;
  m['v'] = 5;
  m['s'] = 6;
  m['x'] = 6;
  m['p'] = 7;
  m['m'] = 7;
  m['h'] = 8;
  m['k'] = 8;
  m['n'] = 9;
  m['g'] = 9;
  m['z'] = 0;
  m['r'] = 0;

  ll n;
  cin >> n;
  bool f = false,f2 = false;
  rep(i,n){
    string s;
    cin >> s;
    f = false;
    rep(j,s.size()){
      s[j] = tolower(s[j]);
      if(m.count(s[j])){
        if(!f && f2) cout << ' ';
        cout << m[s[j]];
        f = true;
        f2 = true;
      }
    }
  }
  cout << endl;
  return 0;
}
