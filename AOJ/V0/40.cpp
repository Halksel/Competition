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

int gcd(int a,int b){
  if(a < b) swap(a,b);
  if(b == 0) return a;
  return gcd(b,a%b);
}

int lcm(int a,int b){
  return a*b/ gcd(a,b);
}
string Encode(string s,int n,int m){
  string res = s;
  rep(i,s.size()){
    if(s[i] != ' '){
      s[i] = (n * (s[i]-'a')+m )%26+'a';
    }
  }
  return s;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  vector< pair<string,pair<int,int>>> list(0);
  REP(i,1,26){
    if(gcd(i,26) == 1){
      rep(j,26){
        list.pb(make_pair(Encode("this",i,j),make_pair(i,j)));
        list.pb(make_pair(Encode("that",i,j),make_pair(i,j)));
      }
    }
  }
  int n,a,b;
  string s;
  cin >> n;
  cin.ignore();
  rep(i,n){
    vary(string,vs,0,"");
    getline(cin,s);
    string tmp="";
    rep(i,s.size()){
      if(s[i] == ' '){
        vs.pb(tmp);
        tmp.clear();
      }
      else tmp+=s[i];
    }
    vs.pb(tmp);
    rep(i,list.size()){
      rep(j,vs.size()){
        if(list[i].fi == vs[j]){
          a = list[i].se.fi;
          b = list[i].se.se;
        }
      }
    }
    s.clear();
    map<char,char> m;
    rep(i,26){
      char c[1] = {char('a'+i)};
      string str = c;
      m[Encode(str,a,b)[0]] = char('a'+i);
    }
    rep(i,vs.size()){
      rep(j,vs[i].size()){
        vs[i][j] = m[vs[i][j]];
      }
      s += vs[i];
      s += " ";
    }
    s.resize(s.size()-1);
    cout << s << endl;
  }
  return 0;
}
