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
  string t;
  cin >> t;
  ll si=t.size();
  t += "     ";
  ll ans = 0,c = 0;
  vector<string> s(2);
  rep(i,t.size()+2){
    s[0] += "25";
    s[1] += "52";
  }
  s[1][0] = '`';
  char a = '2',b = '5';
  int k = 0;
  rep(j,2){
    c = 0;
    if(j ) k = 1;
    rep(i,si/2){
      if((s[j][2 * i+ k] == t[2 * i+k] && s[j][2*i+1+k] == t[2*i+1+k])) ++c;
      else if(s[j][2 * i+k] == t[2 * i+k] && t[2*i+1+k] == '?')++c;
      else if(t[2 * i+k] == '?' && s[j][2*i+1+k] == t[2*i+1+k]){
        ++c;
      }
      else if(t[2 * i+k] == '?' && t[2 * i+1+k] == '?'){
        ++c;
      }
      else{
        c = 0;
      }
      ans = max(ans,c);
    }
  }
      ans = max(ans,c);
  cout << ans * 2 << endl;
  return 0;
}

