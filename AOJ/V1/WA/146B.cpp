//#1857601 Solution for 0146: Lupin The 4th by T1610

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

const int mod = 1000000007;
constexpr ll inf = 10000000000000 ;
string e = "";
pll dp[(2 << 16)+1][16],ans;
ll w[(2 << 15)];
array<int,16> d,m,num;
void init(){
  rep(i,(2<<16)+1){
    rep(j,16)
    dp[i][j] = make_pair(inf,-1);
  }
  fill(all(d),0);
  fill(all(m),0);
}
ll n;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  init();
  cin >> n;
  rep(i,n){
    cin >> num[i] >> d[i] >> m[i];
    m[i] *= 20;
  }

  rep(i,1 << n){
    int sum = 0;
    rep(j,n){
      dp[i][j] = make_pair(inf,-1);
      if((i & (1<<j))) sum += m[j];
    }
    w[i] = sum;
  }
  rep(i,n) dp[1 << i][i].fi = 0;
  rep(i,1 << n){
    rep(now,n){
      if( (i & (1 << now)) == 0) continue;
      rep(nxt,n){
        if((i & (1 << nxt)) != 0) continue;
        dp[ i | (1 << nxt)][nxt] = min(dp[i | (1 << nxt)][nxt],make_pair(dp[i][now].fi + abs((d[now] - d[nxt]) * (70+w[i])),(ll)now));
      }
    }
  }
  ll suf = 0,mi = inf,last = (1 << n) -1;
  rep(i,n){
    if(mi > dp[last][i].fi){
      suf = i;
      mi = dp[last][i].fi;
    }
  }
  int prev = last;
  vector<ll> ans;
  while(suf != -1){
    ans.pb(num[suf]);
    int tmp = dp[prev][suf].se;
    prev -= (1 << suf);

    suf = tmp;
  }
  reverse(all(ans));
  rep(i,n){
    if(i != 0) cout << " " ;
    cout << ans[i];
  }
  cout << endl;
  return 0;
}
