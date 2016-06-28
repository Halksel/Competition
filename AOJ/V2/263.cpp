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
constexpr int inf = ((1<<30)-1)*2+1 ;
constexpr double PI = acos(-1.0) ;
double eps = 1e-10 ;
const int dy[] = {-1,0,1,0,1,-1,1,-1};
const int dx[] = {0,-1,0,1,1,-1,-1,1};

inline bool value(int x,int y,int w,int h){
  return (x >= 0 && x < w && y >= 0 && y < h);
}

template<typename T>
void Unique(vector<T> &v){
  sort(all(v));
  v.erase(unique(all(v)),v.end());
}
template<typename T,typename U>
ll FindErase(T &v,U tar){
  ll cnt = 0;
  for(auto it = v.begin(); it != v.end();){
    if(*it == tar){
      it = v.erase(it);
      ++cnt;
    }
    else{
      ++it;
    }
  }
  return cnt;
}

template<typename T>
bool SuffixErase(T &v,size_t suf){
  if(suf > v.size()) return false;
  for(auto it = v.begin(); it != v.end();){
    if(distance(v.begin(),it) == suf){
      v.erase(it);
      return true;
    }
    else{
      ++it;
    }
  }
  return false;
}

template<typename T>
T ston(string& str, T n){
  istringstream sin(str) ;
  T num ;
  sin >> num ;
  return num ;
}
ll n,c;
vector<vector<int>> dp(1 << 17,vector<int>(16,0));
void init(){
  rep(i,2 << 16){
    rep(j,16){
      dp[i][j] = 0;
    }
  }
}
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  while(cin >> n >> c && n && c){
    init();
    vector<bitset<16>> a(n+1),b(n+1);
    string s,s2;
    rep(i,n){
      s = "";
      rep(i,16){
        cin >> s2;
        s+= s2;
      }
      a[i] = bitset<16>(s);
    }
    rep(i,c){
      s = "";
      rep(i,16){
        cin >> s2;
        s+= s2;
      }
      b[i] = bitset<16>(s);
    }
    int ans = 0;
    vector<bitset<16>> st;
    st.push_back(a[0]);
    rep(i,n){
      ll cnt = 0;
      vector<bitset<16>> s2;
      auto buf = dp;
      for(auto prev : st){
        rep(j,c){
          dp[(prev|b[j]).to_ulong()][i+1] = max(dp[(prev|b[j]).to_ulong()][i+1],int((prev & b[j]).count() + dp[prev.to_ulong()][i]));
//           debug(prev);
//           debug(b[j]);
          bitset<16> tmp = (prev ^ b[j]) & prev;
          debug(dp[prev.to_ulong()][i]);
//           debug(tmp);
//           debug((prev&b[j]).count());
          s2.push_back(tmp);
          buf[(tmp|a[i+1]).to_ulong()][i+1] = max(buf[(tmp|a[i+1]).to_ulong()][i+1],dp[prev.to_ulong()][i]);
          ++cnt;
        }
      }
      dp = buf;
      st.clear();
      debug(cnt);
    }
    rep(i,1<<16){
      ans = max(ans,dp[i][n]);
    }
    cout << ans << endl;
  }
  return 0;
}
