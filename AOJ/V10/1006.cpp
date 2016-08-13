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
using pii = pair<int,int> ;
using pll = pair<ll,ll> ;

const int mod = 1000000007;
constexpr int inf = ((1<<30)-1)*2+1 ;
constexpr double PI = acos(-1.0) ;
double eps = 1e-10 ;
const int dy[] = {-1,0,1,0,1,-1,1,-1};
const int dx[] = {0,-1,0,1,1,-1,-1,1};

template<typename T>
T ston(string& str, T n){
  istringstream sin(str) ;
  T num ;
  sin >> num ;
  return num ;
}

int t2m(ll s){
  ll s1 = s / 100,s2 = s % 100;
  return s1 * 60 + s2;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll n;
  ll s1,s2;
  while(cin >> n >> s1 >> s2 && n){
    ll Ma = t2m(s2);
    ll a,s,e;
    vector<ll> ans(t2m(s2)+1,0);
    rep(i,n){
      cin >> a;
      ll bs = t2m(s1);
      rep(j,a){
        cin >> s >> e;
        s = t2m(s);
        e = t2m(e);
        REP(k,bs,s){
          ans[k] = 1;
        }
        bs = e;
      }
      REP(j,bs,Ma){
        ans[j] = 1;
      }
    }
    ll res = 0,tmp = 0;
    REP(i,t2m(s1),t2m(s2)){
      if(ans[i]){
        ++tmp;
        res = max(res,tmp);
      }
      else
        tmp = 0;
    }
    cout << res << endl;
  }
  return 0;
}

