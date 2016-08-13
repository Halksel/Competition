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

struct team{
  int i,u,a,p;
  bool operator<(const team& t){
    if(a == t.a && p == t.p) return i < t.i;
    if(a == t.a) return p < t.p;
    return a > t.a;
  }
};

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll n;
  while(cin >> n && n){
    vector<team> T(n);
    map<ll,ll> m;
    rep(i,n){
      cin >> T[i].i >> T[i].u >> T[i].a >> T[i].p;
      m[T[i].u] = 0;
    }
    sort(all(T));
    ll sum = 0;
    rep(i,n){
      if(sum < 10 && m[T[i].u] < 3){
        ++sum;
        cout << T[i].i << endl;
        m[T[i].u]++;
      }
      else if(sum < 20 && m[T[i].u] < 2){
        ++sum;
        cout << T[i].i << endl;
        m[T[i].u]++;
      }
      else if(sum < 26 && m[T[i].u] < 1){
        ++sum;
        cout << T[i].i << endl;
        m[T[i].u]++;
      }
      //     cout << T[i].i << ":" << T[i].u << ":" << T[i].a << ":" << T[i].p << endl;
    }
  }
  return 0;
}
