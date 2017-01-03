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
using T = pair<string,string>;
bool Comp(T s,T s2){
  if(s.fi.size() == s2.fi.size()){
    return s < s2;
  }
  else{
    return s.fi.size() < s2.fi.size();
  }
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  map<ll,ll> m;
  ll t;
  rep(i,10){
    cin >> t;
    m[t] = i;
  }
  ll n;
  string s,s2;
  cin >> n;
  vector<pair<string,string>> ans(n);
  rep(i,n){
    cin >> s;
    s2 = s;
    rep(j,s.size()){
      s2[j] = m[s[j] - '0'] + '0';
    }
    ans[i] = mp(s2,s);
  }
  sort(all(ans),Comp);
  rep(i,n){
    cout << ans[i].se << endl;
  }
  return 0;
}

