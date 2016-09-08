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
#define mp(a,b) make_pair(a,b)

#define rep(i,n) for(int i = 0; i < (int)(n);++i)
#define REP(i,a,b) for(int i = (a);i < (int)(b);++i)
#define repi(it,array) for(auto it = array.begin(),end = array.end(); it != end;++it)
#define repa(n,array) for(auto &n :(array))

using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using dict = map<string,int>;
using pdl = pair<double,ll> ;

const int mod = 1000000007;
constexpr int imax = ((1<<30)-1)*2+1 ;
constexpr ll inf = 100000000;
constexpr double PI = acos(-1.0) ;
double eps = 1e-10 ;
const int dy[] = {-1,0,1,0};
const int dx[] = {0,-1,0,1};

inline bool value(int x,int y,int w,int h){
  return (x >= 0 && x < w && y >= 0 && y < h);
}

ll numofbits5(long bits)
{
  bits = (bits & 0x55555555) + (bits >> 1 & 0x55555555);
  bits = (bits & 0x33333333) + (bits >> 2 & 0x33333333);
  bits = (bits & 0x0f0f0f0f) + (bits >> 4 & 0x0f0f0f0f);
  bits = (bits & 0x00ff00ff) + (bits >> 8 & 0x00ff00ff);
  return (bits & 0x0000ffff) + (bits >>16 & 0x0000ffff);
}
vector<string> f;
vector<ll> w,s;
int n;
ll sumW;
double g = inf;
vector<int> ans;
void rdp(int st,int k,vector<vector<pdl>> &dp,vector<int> v){
  int bfr = st & ~(1 <<k);
  ll W = dp[st][k].se ;
  W -= w[k];
  v.push_back(k);
  if(bfr == 0){
    ans = v;
    return ;
  }
  ll G = dp[st][k].fi ;
  REP(i,0,n){
    if(bfr & (1 << i) && G - numofbits5(st) * w[k] == dp[bfr][i].fi){
      rdp(bfr,i,dp,v);
    }
  }
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  while(cin>>n&&n){
    f.clear(); f.resize(n); w.clear(); w.resize(n); s.clear(); s.resize(n);
    sumW =0;
    rep(i,n){
      cin >> f[i] >> w[i] >> s[i];
      sumW += w[i];
    }
    vector<vector<pdl>> dp(1 << n,vector<pdl>(n,mp(inf,1)));
    rep(i,n){
      if(sumW - w[i] <= s[i]){
        dp[1 << i][i] = mp(w[i],w[i]);
      }
    }
    rep(i,1 << n){
      rep(j,n){
        if((i & (1 << j)) == 0 || dp[i][j].fi == inf) continue;
        rep(k,n){
          if(i & (1 << k)) continue;
          int nxt = i | (1 << k);
          double G = dp[i][j].fi + (numofbits5(nxt)) * w[k];
          ll W = dp[i][j].se + w[k];
          if(1.0 * G / W < 1.0 * dp[nxt][k].fi / dp[nxt][k].se && sumW - W <= s[k]){
            dp[nxt][k] = mp(G,W);
          }
        }
      }
    }
    int st = (1 << n) -1;
    double ansg = inf;
    int suf = -1;
    REP(i,0,n){
      if(1.0 * dp[st][i].fi / dp[st][i].se < ansg){
        ansg = 1.0 * dp[st][i].fi / dp[st][i].se ;
        suf = i;
      }
    }
    vector<int> v(0);
    rdp(st,suf,dp,v);
    reverse(all(ans));
    rep(i,ans.size()){
      cout << f[ans[i]] << endl;
    }
  }
  return 0;
}
