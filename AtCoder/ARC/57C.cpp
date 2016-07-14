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

template<typename T>
T ston(string& str, T n){
  istringstream sin(str) ;
  T num ;
  sin >> num ;
  return num ;
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
size_t S;
string s;
double n;
ll N;
int itos(double num){
  string res = to_string(num);
  while(res.size() < 1005){
    res += "0";
  }
  FindErase(res,'.');
  res.resize(S);
  if(res == s){
    return 0;
  }
  else if(num < n){
    return -1;
  }
  return 1;
}

string setnum(string s,int i, ll &l, ll &r){
  s.insert(i,".");
  n = ston(s,1.0);
  N = n*n;
  l = N - 2 * n;
  r = N + 2 * n;
  if( l < 0) l = 0;
  return s;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin >> s;
  S = s.size();
  ll l,r;
  cin >> r ;
  REP(i,1,S){
    auto res = setnum(s,i,l,r);
    rep(x,100){
      ll mid = (l+r)/2;
      ll bra = itos(sqrt(mid));
      if(!bra){
        cout << mid<<endl;
        return 0;
      }
      else if(bra == -1){
        l = mid;
      }
      else{
        r = mid;
      }
    }
  }
  return 0;
}
