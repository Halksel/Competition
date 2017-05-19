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

vector<datas> d ;
bool sortx(const datas& a,const datas& b){
  return a.x < b.x;
}
bool sorty(const datas& a,const datas& b){
  return a.y < b.y;
}

const int K = 2;
class kDTree{
  public:
    int depth;
    ll n;
    vector<datas> nodes,tree;
    kDTree(){};
    kDTree(const vector<datas> &v): n(v.size()),nodes(n),tree(n){
      rep(i,n){
        nodes[i] = v[i];
      }
      build(0,n,0);
    }
    void build(int l,int r,int _depth){
      if(l >= r) return ;
      int m = (l+r)/2;
      int axis = _depth % K;
      auto first = nodes.begin() + l, nth = nodes.begin() + m, last = nodes.begin() + r;
      if (axis == 0)
            nth_element(first, nth, last, sortx);
        else
            nth_element(first, nth, last, sorty);
      tree[m] = *nth;
      build(l,m,_depth+1);
      build(m+1,r,_depth+1);
    }
    bool range(const datas &p, int sx, int sy, int tx, int ty) {
        return sx <= p.x&&p.x <= tx&&sy <= p.y&&p.y <= ty;
    }
    void query(int sx, int sy, int tx, int ty, vector<int> &idxs) {
        query(0, n, 0, sx, sy, tx, ty, idxs);
    }
    void query(int l,int r,int depth,int sx,int sy,int tx,int ty, vector<int>& idxs){
      if(l >= r) return ;
      int m = (l+r)/2;
      datas node = tree[m];
      int axis = depth % K;
      if(axis == 0){
        if (tx < node.x) {
          query(l, m, depth+1, sx, sy, tx, ty, idxs);
        }
        else if (node.x < sx) {
          query(m + 1, r, depth+1, sx, sy, tx, ty, idxs);
        }
        else {
          if (range(node, sx, sy, tx, ty))idxs.emplace_back(node.i);
          query(l, m, depth+1, sx, sy, tx, ty, idxs);
          query(m + 1, r, depth+1, sx, sy, tx, ty, idxs);
        }
      }
      else{
        if (ty < node.y) {
          query(l, m, depth+1, sx, sy, tx, ty, idxs);
        }
        else if (node.y < sy) {
          query(m + 1, r, depth+1, sx, sy, tx, ty, idxs);
        }
        else {
          if (range(node, sx, sy, tx, ty))idxs.emplace_back(node.i);
          query(l, m, depth+1, sx, sy, tx, ty, idxs);
          query(m + 1, r, depth+1, sx, sy, tx, ty, idxs);
        }
      }
    }
    void show(){
      rep(i,n){
        cout << tree[i].x << ' ' << tree[i].y << ' ' << tree[i].i << endl;
      }
    }
};

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
ll n;
  cin >> n;
  d.resize(n);
  rep(i,n){
    cin >> d[i].x >> d[i].y;
    d[i].i = i;
  }
  kDTree tree(d);
  ll q;
  cin >> q;
  ll sx,tx,sy,ty;
  rep(i,q){
    cin >> sx >> tx >> sy >> ty;
    vector<int> res;
    tree.query(sx,sy,tx,ty,res);
    sort(all(res));
    for (auto&& k : res) {
      cout << k << endl;
    }
    cout << endl;
  }
  return 0;
}
