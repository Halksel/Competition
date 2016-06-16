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

template<typename T>
T ston(string& str, T n){
  istringstream sin(str) ;
  T num ;
  sin >> num ;
  return num ;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll q;
  string s = "000";
  cin >> q;
  rep(i,q){
    bool f = true;
    ll n = 0;
    cin >> s;
    set<ll> st;
    while(s.size() != 1){
      ll ans = -1;
      REP(k,1,s.size()){
        string l = s,r = s;
        l.resize(k);
        r = r.substr(k);
        ll n2 = ston(l,1) * ston(r,1);
        ans = max(ans,n2);
      }
      if(!st.insert(ans).se ){
        cout << -1 << endl;
        f = false;
        break;
      }
      else{
        s = to_string(ans);
      }
      ++n;
    }
    if(f)
    cout << n << endl;
  }
  return 0;
}
