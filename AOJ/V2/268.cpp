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

constexpr ll inf = ((1<<30)-1)*2+1 ;
constexpr double PI = acos(-1.0) ;
double eps = 1e-10 ;
const int dy[] = {-1,0,1,0,1,-1,1,-1};
const int dx[] = {0,-1,0,1,1,-1,-1,1};

const ll mod = 1e9+7;
ll powmod(ll a, ll p){
  ll ans = 1;
  ll mul = a;
  for(; p > 0; p >>= 1, mul = (mul*mul) % mod){
    if((p & 1) == 1) ans = ( ans * mul) % mod;
  }
  return ans;
}

constexpr double s[7] = {0.5,0.25,0.125,0.625,0.03125,0.015625,0.0078125};
string solve(string &str){
  if(str[31] == '1'){
    cout << '-' ;
  }
  string tmp = str.substr(7,24);
  reverse(all(tmp));
  cout << bitset<24>(tmp).to_ullong() << '.';
  double Float = 0.0;
  REP(i,0,7){
    Float += s[i] * (str[6-i] == '1');
  }
  str.clear();
  if(Float != 0.0){
    stringstream ss;
    ss << Float;
    ss >> str;
    ss.clear();
    int cnt = 0;
    int S = str.size();
    rep(i,S){
      if(str[S-i-1] == '0') ++cnt;
      else break;
    }
    str.resize(S-cnt);
    str = str.substr(2);
  }
  if(str.size() == 0) str = "0";
  return str;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll q;
  cin >> q;
  rep(x,q){
    char c;
    string str;
    rep(i,8){
      cin >> c;
      if(c >= '0' && c <= '9') c -= '0';
      else{
        c -= 'a' ;
        c += 10;
      }
      str += bitset<4>(c).to_string();
    }
    reverse(all(str));
    solve(str);
    cout << str << endl;
  }
  return 0;
}

