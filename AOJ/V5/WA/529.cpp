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
constexpr int inf = 1000000000;
constexpr double PI = acos(-1.0) ;
double eps = 1e-10 ;
const int dy[] = {-1,0,1,0};
const int dx[] = {0,-1,0,1};

inline bool value(int x,int y,int w,int h){
  return (x >= 0 && x < w && y >= 0 && y < h);
}

ll n,m;
multimap<ll,ll> mm;
vary(ll,s,1001,0);
ll dfs(ll cnt, ll sum){
  auto r = mm.equal_range(sum);
  for(auto it = r.fi; it != r.se; ++ it){
    if(it->se <= cnt){
      return sum;
    }
  }
  if(cnt == 4) return sum;
  mm.insert(make_pair(sum,cnt));
  ll res = sum;
  rep(i,n){
    if(sum + s[i] <= m){
      res = max(res,dfs(cnt+1,sum + s[i]));
    }
  }
  return res;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  while(cin >> n >> m && n && m){
    rep(i,n){
      cin >> s[i];
    }
    sort(s.begin(),s.begin()+n);
    mm.clear();
    cout << dfs(0,0) << endl;
  }
  return 0;
}
