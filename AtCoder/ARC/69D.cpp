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

bool k[] = {0,1};

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  string s;
  cin >> s;
  for (int i = 0; i < 2; i++) {
    for(int j = 0; j < 2;++j){
      vector<bool> v(n+1);
      v[0] = k[j];
      v[1] = k[i];
      v[n] = k[j];
      rep(i,n-1){
        if(s[i] == 'o'){
          if(v[i+1] == 0){
            v[i+2] = v[i];
          }
          else{
            v[i+2] = !v[i];
          }
        }
        else{
          if(v[i+1] == 0){
            v[i+2] = !v[i];
          }
          else{
            v[i+2] = v[i];
          }
        }
      }
      bool f = true;
      f = v[0] == v[n];
      for (int i = 0; i < n-1; i++) {
        if(v[i+1]){//W
          if(s[i] == 'o'){
            if(v[i] == v[i+2]) f = false;
          }
          else if(s[i] == 'x'){
            if(v[i] != v[i+2]) f = false;
          }
        }
        else {
          if(s[i] == 'x' && v[i] == v[i+2]) f = false;
          if(s[i] == 'o' && v[i] != v[i+2]) f = false;
        }
      }
      if(v[n]){
        if(s[n-1] == 'o'){
          if(v[n-1] == v[1]) f = false;
        }
        else if(s[n-1] == 'x'){
          if(v[n-1] != v[1]) f = false;
        }
      }
      else{
        if(s[n-1] == 'x' && v[n-1] == v[1]) f = false;
        if(s[n-1] == 'o' && v[n-1] != v[1]) f = false;
      }
      if(f){
        for (int i = 0; i < n; i++) {
          if(v[i+1]){
            cout << 'W';
          }
          else{
            cout << 'S';
          }
        }
        cout << endl;
        return 0;
      }
    }
  }
  cout << -1 << endl;
  return 0;
}
