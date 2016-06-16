#define _GLIBCXX_DEBUG
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

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll h,w,q;
  cin >> h >> w >> q;
  vector<vector<ll>> j,o,I(h+2,vector<ll>(w+2,0));
  j = o = I;
  char c;
  REP(i,1,h+1){
    REP(k,1,w+1){
      cin >> c;
      if(c == 'J'){
        j[i][k] = 1;
      }
      else if(c == 'O'){
        o[i][k] = 1;
      }
      else{
        I[i][k] = 1;
      }
    }
  }
  REP(i,1,h+1){
    REP(k,1,w+1){
      j[i][k+1] += j[i][k];
      o[i][k+1] += o[i][k];
      I[i][k+1] += I[i][k];
    }
  }
  REP(k,1,w+1){
    REP(i,1,h+1){
      j[i+1][k] += j[i][k];
      o[i+1][k] += o[i][k];
      I[i+1][k] += I[i][k];
    }
  }
  ll a,b,e,d;
  rep(i,q){
    cin >> a >> b >> e >> d;
    cout << j[e][d]+j[a-1][b-1]-j[a-1][d]-j[e][b-1]<< ' '<<o[e][d] + o[a-1][b-1] -o[a-1][d]-o[e][b-1]<< ' '<<I[e][d] +I[a-1][b-1]-I[a-1][d]-I[e][b-1]<<endl;
  }
  return 0;
}
