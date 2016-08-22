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
constexpr int inf = ((1<<30)-1)*2+1 ;
constexpr double PI = acos(-1.0) ;
double eps = 1e-10 ;
const int dy[] = {-1,0,1,0,1,-1,1,-1};
const int dx[] = {0,-1,0,1,1,-1,-1,1};

inline bool value(int x,int y,int w,int h){
  return (x >= 0 && x < w && y >= 0 && y < h);
}

struct train{
  string s,t;
};

struct Comp{
  bool operator()(pair<string,string> a,pair<string,string> b)const{
    return a.fi < b.fi;
  }
};

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  string s,t;
  ll n;
  while(cin >> n && n){
    vector<train> ans;
    vector<pair<string,string>> v(n);
    rep(i,n){
      cin >> v[i].fi >> v[i].se;
    }
    sort(all(v),Comp());
    ans.push_back({v[0].fi,v[0].se});
    REP(i,1,n){
      bool f = false;
      rep(j,ans.size()){
        if(ans[j].t <= v[i].fi){
          ans[j] = {v[i].fi,v[i].se};
          f = true;
          break;
        }
      }
      if(!f) ans.push_back({v[i].fi,v[i].se});
    }
    cout << ans.size() << endl;
  }
  return 0;
}

