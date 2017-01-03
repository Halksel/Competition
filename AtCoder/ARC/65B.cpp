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
class Union_Find{
  public:
  Union_Find(){};
  static const ll MAX_N = 100000*2+1;
  int par[MAX_N];
  int ranks[MAX_N];
  void init(int n){
    rep(i,MAX_N){
      par[i] = i;
      ranks[i] = 0;
    }
  }
  int find(int x){
    if(par[x] == x){
      return x;
    }
    else{
      return par[x] = find(par[x]);
    }
  }

  void Unite(int a, int b){
    a = find(a);
    b = find(b);
    if(a == b) return ;
    if(ranks[a] < ranks[b]){
      par[a] = b;
    }
    else{
      par[b] = a;
      if(ranks[a] == ranks[b]) ranks[a]++;
    }
  }
  bool same(int a,int b){
    return find(a) == find(b);
  }
};
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  Union_Find u,u1;
  u.init(0);
  u1.init(0);
  ll n,k,l,a,b;
  cin >> n >> k >> l;
  rep(i,k){
    cin >> a >> b;
    u.Unite(a,b);
  }
  rep(i,l){
    cin >> a >> b;
    u1.Unite(a,b);
  }
  map<pll,ll> m;
  rep(i,n){
    m[make_pair(u.find(i+1),u1.find(i+1))]++;
  }
  rep(i,n){
    cout << m[make_pair(u.find(i+1),u1.find(i+1))] << endl;
  }
  return 0;
}

