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
  int n;
  cin >> n;
  vector<int> v(n);
  using P = pair<pii,int>;
  vector<P> vp;
  bool f = false;
  int s = 0;
  rep(i,n){
    cin >> v[i];
  }
  P k;
  rep(i,n){
    if(!f && v[i] == 0){
      k.fi.fi = i+1;
        k.fi.se = i+1;
      if(i == n-1){
        vp.push_back(k);
      }
      f = true;
    }
    else if(f && v[i] == 0 && i == n-1){
      k.fi.se = i+1;
      vp.push_back(k);
    }
    if(f && v[i] != 0){
      k.fi.se = i;
      k.se = 0;
      vp.push_back(k);
      vp.push_back(mp(mp(i+1,i+1),v[i]));
      f= false;
    }
    else if(v[i]){
      vp.push_back(mp(mp(i+1,i+1),v[i]));
    }
  }
//   rep(i,vp.size()){
//     cout << vp[i].fi.fi << ' ' << vp[i].fi.se << endl;
//   }
  rep(i,vp.size()){
    if(vp[i].se == 0){
      if(i != vp.size() - 1){
        vp[i+1].fi.fi = vp[i].fi.fi;
        vp[i].se = -inf;
      }
      else{
        vp[i-1].fi.se = vp[i].fi.se;
        vp[i].se = -inf;
      }
    }
  }
  int c = 0;
  f = false;
  rep(i,vp.size()){
    if(vp[i].se != -inf){
      f = true;
      ++c;
    }
  }
  if(!f) O("NO");
  else{
    O("YES");
    O(c);
    rep(i,vp.size()){
      if(vp[i].se != -inf)
        cout << vp[i].fi.fi << ' ' << vp[i].fi.se << endl;
    }
  }
return 0;
}
