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

struct team{
  int id,ac,sec;
  vector<ll> v;
  bool operator<(const team& a){
    if(ac == a.ac){
      if(sec == a.sec) return id < a.id;
      return sec > a.sec;
    }
    return ac < a.ac;
  }
  bool operator>(const team& a){
    if(ac == a.ac){
      return sec > a.sec;
    }
    return ac < a.ac;
  }
};

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll M,T,P,R;
  while(cin >> M >> T >> P >> R && M+T+P+R){
    vector<team> v(T);
    rep(i,T){
      v[i].id = i+1;
      v[i].v.resize(P);
    }
    ll m,t,p,j;
    rep(i,R){
      cin >> m >> t >> p >> j;
      if(j == 0){
        v[t-1].ac++;
        v[t-1].sec += m + 20 * v[t-1].v[p-1];
      }
      else{
        v[t-1].v[p-1]++;
      }
    }
    sort(all(v));
    reverse(all(v));
    cout << v[0].id;
    REP(i,1,T){
      if(v[i] > v[i-1]){
        cout << ',' << v[i].id ;
      }
      else{
        cout << '=' << v[i].id ;
      }
    }
    cout << endl;
  }
  return 0;
}

