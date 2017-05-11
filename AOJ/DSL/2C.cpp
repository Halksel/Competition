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

struct datas{
  ll x,y,i;
};

bool sortx(const datas& a,const datas& b){
  return a.x < b.x;
}
bool sorti(const datas& a,const datas& b){
  return a.i < b.i;
}
bool sorty(const datas& a,const datas& b){
  return a.y < b.y;
}

vector<datas> d ;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll n,cnt_x = 0,cnt_y = 0;
  cin >> n;
  d.resize(n);
  map<ll,ll> mx,my;
  rep(i,n){
    cin >> d[i].x >> d[i].y;
    d[i].i = i;
    mx[d[i].x] = 0;
    my[d[i].y] = 0;
  }
  rep(i,n){
    mx[d[i].x] = cnt_x++;
    my[d[i].y] = cnt_y++;
  }
  ll q;
  cin >> q;
  sort(all(d),sortx);
  auto dy = d;
  sort(all(dy),sorty);
  ll sx,tx,sy,ty;
  rep(i,q){
    cin >> sx >> tx >> sy >> ty;
    auto lb = lower_bound(all(d),sx,sortx);
    auto ub = upper_bound(all(d),tx,sortx);
    auto lby = lower_bound(all(dy),sy,sorty);
    auto uby = upper_bound(all(dy),ty,sorty);
    set<ll> ans;
    if(ub - lb < uby - lby){
      for(auto it = lb ; lb < ub;++it){
        if(it->y >= sy && it->y <= ty){
          ans.insert(it->i);
        }
      }
    }
    if(ub - lb >= uby - lby){
      for(auto it = lby ; lby < uby;++it){
        if(it->x >= sx && it->x <= tx){
          ans.insert(it->i);
        }
      }
    }
    for (auto&& n : ans) {
      cout << n << endl;
    }
    cout << endl;
  }
  return 0;
}
