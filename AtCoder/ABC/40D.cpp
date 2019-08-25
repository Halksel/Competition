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

const int MAX_N =100001;
int N;
int par[MAX_N];
int ranks[MAX_N];
int cnt[MAX_N] ;

void init(int n){
  rep(i,n){
    par[i] = i;
    ranks[i] = 0;
    cnt[i] = 1;
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
    cnt[b] += cnt[a];
  }
  else{
    par[b] = a;
    cnt[a] += cnt[b];
    if(ranks[a] == ranks[b]) ranks[b]++;
  }
}

bool same(int a,int b){
  return find(a) == find(b);
}

struct data1{
  int a,b,y;
  bool operator<(const data1& d){
    return y < d.y;
  }
};
struct data2{
  int v,w,s;
  bool operator<(const data2& d){
    return w < d.w;
  }
};

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll m;
  cin >> N >> m;
  init(N+1);
  vector<data1> v(m);
  rep(i,m){
    cin >> v[i].a >> v[i].b >> v[i].y;
    v[i].a--;
    v[i].b--;
  }
  ll q;
  cin >> q;
  vector<data2> v2(q);
  rep(i,q){
    cin >> v2[i].v >> v2[i].w;
    v2[i].v--;
    v2[i].s = i;
  }
  sort(all(v));
  sort(all(v2));
  ll i = 0,j = 0;
  vector<ll> ans(q+4);
  while(i < m || j < q){
    if(v[i].y >= v2[j].w && j < q){
      cout << v2[j].v << endl;
      ans[v2[j].s] = cnt[v2[j].v];
      ++j;
    }
    else{
      Unite(v[i].a,v[i].b);
//       rep(k,N){
//         cout << cnt[k]<<endl;
//       }
//       cout << endl;
      ++i;
    }
  }
  rep(k,q){
    debug(v2[k].s);
    cout << ans[k] << endl;
  }
  return 0;
}
