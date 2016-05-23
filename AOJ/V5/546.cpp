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

std::string to_binString(unsigned int val)
{
  if( !val )
    return std::string("0");
  std::string str;
  while( val != 0 ) {
    if( (val & 1) == 0 )
      str.insert(str.begin(), '0');
    else
      str.insert(str.begin(), '1');
    val >>= 1;
  }
  return str;
}

vector<ll> v;
set<ll> s;
set<ll> bits;
void dfs(ll bit, ll t){
  if(find(all(bits),bit) != bits.end() || t < 0){
    return;
  }
  bits.insert(bit);
  if(t == 0){
    vector<ll> lis;
    rep(i,v.size()){
      if(bit & (1 << i)){
        lis.push_back(v[i]);
      }
    }
    ll cnt = 0;
    do{
      ll num = 0;
      rep(i,lis.size()){
//         cout << lis[i] << " ";
        if(lis[i] < 10){
          num = num * 10 + lis[i];
        }
        else{
          num = num * 100 + lis[i];
        }
      }
      if(s.insert(num).se){
      }
      ++cnt;
    }while(next_permutation(all(lis)));
//     debug(cnt);
  }
  else{
    REP(i,0,v.size()){
      if(!(bit & (1 << i))){
        dfs(bit | (1 << i),t-1);
      }
    }
  }
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll n,k;
  while(cin >> n >> k && n && k){
    v.resize(n);
    s.clear();
    bits.clear();
    rep(i,n){
      cin >> v[i];
    }
    sort(all(v));
    rep(i,n){
      dfs((1 << i),k-1);
    }
    cout << s.size()<<endl;
  }
  return 0;
}
