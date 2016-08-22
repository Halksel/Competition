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
#define mp(a,b) make_pair(a,b)

#define rep(i,n) for(int i = 0; i < (int)(n);++i)
#define REP(i,a,b) for(int i = (a);i < (int)(b);++i)

using ll = long long;
using pll = pair<ll,ll> ;


int money[10000],b[10000];
map<pll,ll> work;
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll n,m;
  cin >> n >> m;
  ll s,t,e;
  while(cin >> s >> t >> e && s && t && e){
    --s;
    --t;
    work[mp(s,t)] = e;
  }
  ll l;
  cin >> l;
  rep(k,l){
    rep(i,m){
      cin >> b[i];
    }
    rep(i,n){
      money[i] = 0;
      rep(j,m){
        money[i] += work[mp(i,j)] * b[j];
      }
    }
    rep(i,n){
      if(i) cout << " " ;
      cout << money[i];
    }
    cout << endl;
  }
  return 0;
}
