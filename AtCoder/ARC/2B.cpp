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

vector<string> Split(const string& s,const string d){
  string item(s);
  vector<string> res(0);
  for(auto pos = item.find(d); pos != string::npos; pos = item.find(d,pos)){
    item.replace(pos,d.size()," ");
  }
  stringstream buf(item);
  while(buf >> item){
    res.push_back(item);
  }
  return res;
}

template<typename T>
T ston(string& str, T n){
  istringstream sin(str) ;
  T num ;
  sin >> num ;
  return num ;
}
bool is_leap(int y){
  if(y % 400 == 0){
    return true;
  }
  if(y % 100 == 0){
    return false;
  }
  if(y % 4 == 0){
    return true;
  }
  return false;
}
bool check(int y,int m,int d){
  return y % (m * d) == 0;
}
int month[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  string s;
  cin >> s;
  auto r = Split(s,"/");
  int y = ston(r[0],0),m = ston(r[1],0),d = ston(r[2],0);
  while(!check(y,m,d)){
    if(is_leap(y)) month[1] = 29;
    else month[1] = 28;
    ++d;
    if(month[(m-1) % 12] < d){
      if(m == 12) ++y;
      m %= 12;
      ++m;
      d = 1;
    }
  }
  cout << y << '/' << setfill('0') << setw(2) << m << '/' << setfill('0') << setw(2) << d << endl;
  return 0;
}
