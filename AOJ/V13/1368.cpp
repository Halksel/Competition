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

const ll mod = 1e9+7;
constexpr ll inf = ((1<<30)-1)*2+1 ;
constexpr double PI = acos(-1.0) ;
double eps = 1e-10 ;
const int dy[] = {-1,0,1,0,1,-1,1,-1};
const int dx[] = {0,-1,0,1,1,-1,-1,1};

inline bool value(int x,int y,int w,int h){
  return (x >= 0 && x < w && y >= 0 && y < h);
}

int c[10][10];

string make(string k){
  int a = 0;
  rep(i,4){
    int j = k[i] - '0';
    a = c[a][j];
  }
  k.resize(5);
  k[4] = a + '0';
  return k;
}

int check(string s){
  int a = 0;
  rep(i,5){
    int j = s[i] - '0';
    a = c[a][j];
  }
  return a;
}

bool safe(string t){
  string s = t;
  rep(k,4){
    swap(s[k],s[k+1]);
    if(!check(s) && s != t){
      return false;
    }
    swap(s[k],s[k+1]);
  }
  rep(i,5){
    rep(j,10){
      s = t;
      s[i] = char('0' + j);
      if(!check(s) && s != t){
        return false;
      }
    }
  }
  return true;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  rep(i,10){
    rep(j,10){
      cin >> c[i][j];
    }
  }
  string t = "2016";
  ll cnt = 0;
  rep(i,10)rep(j,10)rep(k,10)rep(l,10){
    t[0] = char('0' + i);
    t[1] = char('0' + j);
    t[2] = char('0' + k);
    t[3] = char('0' + l);
    if(!safe(make(t))) ++cnt;
  }
  cout << cnt << endl;
  return 0;
}
