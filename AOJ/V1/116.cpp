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

const int mod = 1000000007;
constexpr ll inf = ((1<<30)-1)*2+1 ;
constexpr double PI = acos(-1.0) ;
double eps = 1e-10 ;
const int dy[] = {-1,0,1,0,1,-1,1,-1};
const int dx[] = {0,-1,0,1,1,-1,-1,1};

inline bool value(int x,int y,int w,int h){
  return (x >= 0 && x < w && y >= 0 && y < h);
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int h,w;
  char c;
  while(cin >> h >> w && h+w){
    vector<vector<ll>> v(h,vector<ll>(w));
    auto v2 = v;
    rep(j,h){
      rep(i,w){
        cin >> c;
        if(c == '.'){
          v[j][i] = 1;
        }
      }
    }
    ll ans = 0;
    {
      stack<pll> st;
      rep(i,w){
        v2[0][i] = v[0][i];
        if(st.empty()){
          st.push(mp(v2[0][i],i));
        }
        else if(st.top().fi < v2[0][i]){
          st.push(mp(v2[0][i],i));
        }
        else if(st.top().fi > v2[0][i]){
          ll pos = i;
          while(!st.empty()){
            if(st.top().fi >= v2[0][i]){
              auto t = st.top();st.pop();
              ans = max(ans,t.fi * (i - t.se));
              pos = t.se;
            }
            else break;
          }
          st.push(mp(v2[0][i],pos));
        }
      }
      ans = max(ans,st.top().fi * (w - st.top().se));
    }
    REP(j,1,h){
      stack<pll> st;
      rep(i,w){
        if(v[j][i]){
          v2[j][i] += v2[j-1][i] + 1;
        }
        if(st.empty()){
          st.push(mp(v2[j][i],i));
        }
        else if(st.top().fi < v2[j][i]){
          st.push(mp(v2[j][i],i));
        }
        else if(st.top().fi > v2[j][i]){
          ll pos = i;
          while(!st.empty()){
            if(st.top().fi >= v2[j][i]){
              auto t = st.top();st.pop();
              ans = max(ans,t.fi * (i - t.se));
              pos = t.se;
            }
            else break;
          }
          st.push(mp(v2[j][i],pos));
        }
      }
      while(!st.empty()){
        auto t = st.top();st.pop();
        ans = max(ans,t.fi * (w - t.se));
      }
    }
    cout << ans << endl;
  }
  return 0;
}
