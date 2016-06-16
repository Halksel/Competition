#include <bits/stdc++.h>
using namespace std ;

#define pb(n) push_back(n)
#define fi first
#define se second
#define all(r) (r).begin(),(r).end()
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
using vi = vector<int>;
using vl = vector<ll>;
using dict = map<string,int>;
using pii = pair<int,int> ;
using pll = pair<ll,ll> ;

const int mod = 1000000007;
constexpr double inf = 100000000000 ;
string e = "";
pair<string,pair<double,int>> dp[(2<<16)+1],ans = make_pair(e,make_pair(inf,0));
array<int,16> d,m,num;
void init(){
  rep(i,(2<<16)+1){
    dp[i] = make_pair(e,make_pair(inf,0));
  }
  fill(all(d),0);
  fill(all(m),0);
}
ll n;
void bitdp(int k){
  if(k == (1 << n) -1){
    if(ans.se.fi > dp[k].se.fi){
      ans = dp[k];
    }
    return ;
  }
  rep(i,n){
    if(! (k & (1 << i))){
      string s = dp[k].fi ;
      ll dis;
      if(s.size()){
        dis = abs(d[s.back()] - d[i]);
      }
      else{
        dis = 0;
      }
      int w = (dp[k].se.se);
      double t = dp[k].se.fi + dis/(2000.0/(70+w*20));
      w += m[i];
      s += char(i);
      if(dp[k|(1 << i)].se.fi > t){
        dp[k|(1<<i)] = make_pair(s,make_pair(t,w));
        bitdp(k|(1<<i));
      }
    }
  }
}

std::string to_binString(unsigned int val)
{
  if( !val )
    return std::string("0");
  std::string str;
  while( val != 0 ) {
    if( (val & 1) == 0 )
      str.insert(str.begin(), '0');
    else
      str.insert(str.begin(), '1');
    val >>= 1;
  }
  return str;
}
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  init();
  cin >> n;
  rep(i,n){
    cin >> num[i] >> d[i] >> m[i];
  }
  dp[0] = make_pair(e,make_pair(0,0));
  bitdp(0);
  rep(i,n){
    if(i) cout << ' ';
    cout << num[ans.fi[i]] ;
  }
  cout << endl;
  return 0;
}
