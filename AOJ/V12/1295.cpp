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

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll w,d;
  while(cin >> w >> d ,w + d){
    vector<ll> h(w),a(d);
    vector<ll> h2(w),a2(d);
    rep(i,w){
      cin >> h[i];
    }
    rep(i,d){
      cin >> a[i];
    }
    vector<vector<ll>> ans(w,vector<ll>(d));
    int i = 0;
    while(i < d){
      int j = 0;
      while(j < w){
        if(h[j] == a[i] && !h2[j] && !a2[i]){
          ans[j][i] = h[j];
          h2[j] = h[j];
          a2[i] = a[i];
          break;
        }
        ++j;
      }
      ++i;
    }
    i = 0;
    while(i < d){
      int j = 0;
      if(!a2[i]){
        while(j < w){
          if(a[i] <= h2[j]){
            ans[j][i] = a[i];
            a2[i] = a[i];
            break;
          }
          ++j;
        }
      }
      ++i;
    }
    i = 0;
    while(i < w){
      int j = 0;
      if(!h2[i]){
        while(j < d){
          if(h[i] <= a2[j]){
            ans[i][j] = h[i];
            h2[i] = h[i];
            break;
          }
          ++j;
        }
      }
      ++i;
    }
    ll res = 0;
    rep(i,d){
      rep(j,w){
        res += ans[j][i];
      }
    }
    std::cout << res << std::endl;
  }
  return 0;
}
