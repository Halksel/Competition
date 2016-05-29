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
#define vvl(v,w,h,init) vector<vector<ll>> v(w,vector<ll>(h,init));

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
constexpr int imax = ((1<<30)-1)*2+1 ;
constexpr int inf = 100000000;
constexpr double PI = acos(-1.0) ;
double eps = 1e-10 ;
const int dy[] = {-1,0,1,0,1,-1,1,-1};
const int dx[] = {0,-1,0,1,1,-1,-1,1};

inline bool value(int x,int y,int w,int h){
  return (x >= 0 && x < w && y >= 0 && y < h);
}

template<typename T>
void Unique(vector<T> &v){
  sort(all(v));
  v.erase(unique(all(v)),v.end());
}

struct data{
  ll h,w,sqr;
  bool operator<(const data& d){
    if(sqr == d.sqr) return h < d.h;
    return sqr < d.sqr;
  }
  bool operator==(const data& d){
    return w == d.w && h == d.h && sqr == d.sqr;
  }
};
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  vector<data> d;
  ll h,w,sqr2;
  REP(j,1,151){
    REP(i,j+1,151){
      sqr2 = i*i+j*j;
      d.push_back({j,i,sqr2});
    }
  }
  sort(all(d));
  while(cin >> h >> w && h && w){
    ll sqr = h*h+w*w;
    data ans = data{h,w,sqr};
    rep(i,d.size()){
      if(d[i] == ans){
        ans = d[i+1];
        break;
      }
    }
    cout << ans.h << " " << ans.w << endl;
  }
  return 0;
}
