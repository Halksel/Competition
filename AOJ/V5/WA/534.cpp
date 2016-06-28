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
constexpr int inf = 100000000;
constexpr double PI = acos(-1.0) ;
double eps = 1e-10 ;
const int dy[] = {-1,0,1,0};
const int dx[] = {0,-1,0,1};

inline bool value(int x,int y,int w,int h){
  return (x >= 0 && x < w && y >= 0 && y < h);
}

template<typename T>
void Unique(vector<T> &v){
  sort(all(v));
  v.erase(unique(all(v)),v.end());
}

template<typename T>
T ston(string& str, T n){
  istringstream sin(str) ;
  T num ;
  sin >> num ;
  return num ;
}

void Ans(bool f){
  if(f) cout << "YES"<<endl;
  else cout << "NO"<<endl;
}

void chain(vector<pll> &v){
  bool f = true;
  rep(i,v.size()){
    f = true;
    for(auto it = v.begin(); it != v.end();){
      if(it->fi == (it+1)->fi && it->se + (it+1)->se > 3){
        f = false;
        it = v.erase(it);
        it = v.erase(it);
      }
      else if(it->se > 3){
        f = false;
        it = v.erase(it);
      }
      else
        ++it;
    }
    if(f) break;
  }
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll n;
  while(cin >> n && n){
    vector<ll> v(n);
    vector<pair<ll,ll>> v2;
    ll a = inf,cnt = 0;
    rep(i,n){
      cin >> v[i];
      if(a == inf){
        a = v[i];
        ++cnt;
      }
      else{
        if(v[i] != a){
          v2.push_back(make_pair(a,cnt));
          a = v[i];
          cnt = 1;
        }
        else
          ++cnt;
      }
    }
    v2.push_back(make_pair(a,cnt));
    v2.push_back(make_pair(inf,0));
    auto v3 = v2;
    auto it = v2.begin();
    ll si = v2.size(),ans = inf,sum;
    rep(j,v2.size()){
      sum += v2[j].se;
    }
    debug(sum);
    REP(i,0,si){
      sum = 0;
      v2[i+1].se++;
      v2.erase(it + i);
      chain(v2);
      rep(j,v2.size()){
        sum += v2[j].se;
      }
      int X = v2.size();
      ans = min(ans,sum);
      v2 = v3;
      sum = 0;
      if(i>1){
        v2[i-1].se++;
        v2.erase(it + i);
        chain(v2);
        rep(j,v2.size()){
          sum += v2[j].se;
        }
        int X = v2.size();
        ans = min(ans,sum);
      }
      v2 = v3;
    }
    cout << ans << endl;
  }
  return 0;
}
