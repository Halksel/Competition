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
map<char,string> m;
unsigned int binToUInt(const std::string &str)
{
  unsigned int val = 0;
  for(int i = 0; i < (int)str.size(); ++i) {
    switch (str[i]) {
      case '0':
        val *= 2;
        break;
      case '1':
        val = val * 2 + 1;
        break;
    }
  }
  return val;
}
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  m[' '] = "101";
  m['\''] = "000000";
  m[','] = "000011";
  m['-'] = "10010001";
  m['.'] = "010001";
  m['?'] = "000001";
  m['A'] = "100101";
  m['B'] = "10011010";
  m['C'] = "0101";
  m['D'] = "0001";
  m['E'] = "110";
  m['F'] = "01001";
  m['G'] = "10011011";
  m['H'] = "010000";
  m['I'] = "0111";
  m['J'] = "10011000";
  m['K'] ="0110";
  m['L'] = "00100";
  m['M'] = "10011001";
  m['N'] = "10011110";
  m['O'] = "00101";
  m['P'] = "111";
  m['Q'] = "10011111";
  m['R'] = "1000";
  m['S'] = "00110";
  m['T'] = "00111";
  m['U'] = "10011100";
  m['V'] = "10011101";
  m['W'] = "000010";
  m['X'] = "10010010";
  m['Y'] = "10010011";
  m['Z'] = "10010000";
  while(1){
    string s,encode = "",encode2="";
    vector<string> decode;
    getline(cin,s);
    if(cin.eof())break;
    rep(i,s.size()){
      encode += m[s[i]];
    }
    while(encode.size()%5){
      encode += "0";
    }
    rep(i,encode.size()){
      encode2 += encode[i];
      if((i+1)%5==0){
        decode.pb(encode2);
        encode2.clear();
      }
    }
    string decode2 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ .,-'?";
    rep(i,decode.size()){
      int k = binToUInt(decode[i]);
      decode[i] = decode2[k];
    }
    rep(i,decode.size()){
      cout << decode[i];
    }
    cout << endl;
  }
  return 0;
}
