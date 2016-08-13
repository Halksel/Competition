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
const int dx[] = {-1,1,-4,4,1,-1,-1,1};

inline bool value(int x,int w){
  return x >= 0 && x < w;
}
const string ans = "01234567";
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  string v = ans;
  queue<pair<string,pair<int,int>>> q;
  map<string,int> m;
  q.push(mp(ans,mp(0,0)));
  m[ans] = 0;
  while(q.size()){
    auto Q = q.front();q.pop();
    auto tmp = Q.fi;
    int P = Q.se.fi;
    int C = Q.se.se;
    rep(i,4){
      tmp = Q.fi;
      if(value(P+dx[i],8)){
        if((P != 3 && P != 4) || (P == 3 && dx[i] != 1) || ( P == 4 && dx[i] != -1)){
          swap(tmp[P],tmp[P+dx[i]]);
          if(m.count(tmp) == 0){
            m[tmp] = C+1;
            q.push(mp(tmp,mp(P+dx[i],C+1)));
          }
        }
      }
    }
  }
  char c;
  while(cin >> c){
    v[0] = c;
    rep(i,7){
      cin >> c;
      v[i+1] = c;
    }
    cout << m[v] << endl;
  }
  return 0;
}
