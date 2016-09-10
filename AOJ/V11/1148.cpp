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
using plll = pair<ll,pll> ;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll n,m,N,M,t,s;
  while(cin >> N >> M && N+M){
    vector<vector<plll>> v(N),v2(M);
    ll r,q;
    cin >> r;
    rep(i,r){
      cin >> t >> n >> m >> s;
      if(s){
        plll p = mp(n,mp(t,-1));
        v[n-1].push_back(p);
        v2[m-1].push_back(p);
      }
      else{
        v[n-1].back().se.se = t;
        for(int x = v2[m-1].size()-1; x >= 0; --x){
          if(v2[m-1][x].fi == n && v2[m-1][x].se.se == -1LL){
            v2[m-1][x].se.se = t;
            break;
          }
        }
      }
    }
    ll ts,te;
    cin >> q;
    ll inf = 1000000LL;
    rep(i,q){
      ll res = 0,ma = -1,mi = inf;
      cin >> ts >> te >> m;
      rep(j,v2[m-1].size()){
        auto u = v2[m-1][j].se;
        if(mi == inf){
          mi = max(ts,u.fi);
          ma = min(te,u.se);
        }
        else if(u.fi <= ma){
          mi = max(ts,min(mi,u.fi));
          ma = min(te,max(ma,u.se));
        }
        else{
          if(ma - mi > 0)
            res += ma - mi;
          mi = max(ts,u.fi);
          ma = min(te,u.se);
        }
//         if(v2[m-1][j].se.fi >= ts || v2[m-1][j].se.se <= te)
//           res += min(v2[m-1][j].se.se,te) - max(v2[m-1][j].se.fi,ts);
      }
      if(ma - mi > 0)
        res += ma - mi;
      cout << res << endl;
    }
  }
  return 0;
}
