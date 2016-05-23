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
unsigned int hexToUInt(const std::string &str)
{
  unsigned int val = 0;
  unsigned int v;
  for(size_t ix = 0; ix != str.size(); ++ix) {
    char ch = str[ix];
    if( ch >= '0' && ch <= '9' )
      v = ch - '0';
    else if( ch >= 'A' && ch <= 'F' )
      v = ch - 'A' + 10;
    else if( ch >= 'a' && ch <= 'f' )
      v = ch - 'a' + 10;
    else
      continue;    // 16進数文字ではない場合
    val = val * 16 + v;
  }
  return val;
}
void Ans(bool f){
  if(f) cout << "YES"<<endl;
  else cout << "NO"<<endl;
}

const string li[8] = {"#000000","#0000ff","#00ff00","#00ffff","#ff0000","#ff00ff","#ffff00","#ffffff"};
const string name[8] = {"black","blue","lime","aqua","red","fuchsia","yellow","white"};
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  string s;
  int cola[3],colb[8][3];
  rep(k,8){
    string str = "";
    REP(i,1,li[k].size()){
      if(i % 2){
        str += li[k][i];
      }
      else{
        str += li[k][i];
        colb[k][i/2-1] = hexToUInt(str);
        str.clear();
      }
    }
  }
  while(cin >> s && s != "0"){
    string str="";
    REP(i,1,s.size()){
      if(i % 2){
        str += s[i];
      }
      else{
        str += s[i];
        cola[i/2-1] = hexToUInt(str) ;
        str.clear();
      }
    }
    int mi = inf;
    int suf = 0;
    rep(i,8){
      int d = pow((cola[0] - colb[i][0]),2) + pow((cola[1] - colb[i][1]),2)+pow((cola[2] - colb[i][2]),2);
      if(mi > d){
        suf = i;
        mi = d;
      }
    }
    cout << name[suf]<<endl;
  }
  return 0;
}
