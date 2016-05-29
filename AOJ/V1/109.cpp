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
#define vvl(v,w,h,init) vector<vector<ll>> v(w,vector<ll>(h,init));

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

template<typename T>
T ston(string& str, T n){
  istringstream sin(str) ;
  T num ;
  sin >> num ;
  return num ;
}
const string op = "+-*/()=";
ll RPN(string str){
  string s,s2;
  double ans;
  stack<ll> n;
  s = str;
  ans = 0;
  s += " " ;
  rep(i,s.size()){
    if(s[i] != ' '){
      s2 += s[i];
    }
    else{
      double a,b;
      if(s2 == "+"){
        b = n.top(),n.pop();
        a = n.top(),n.pop();
        ans = a + b;
        n.push(ans);
      }
      else if(s2 == "-"){
        b = n.top(),n.pop();
        a = n.top(),n.pop();
        ans = a - b;
        n.push(ans);
      }
      else if(s2 == "*"){
        b = n.top(),n.pop();
        a = n.top(),n.pop();
        ans = a * b;
        n.push(ans);
      }
      else if(s2 == "/"){
        b = n.top(),n.pop();
        a = n.top(),n.pop();
        ans = a / b;
        n.push(ans);
      }
      else{
        n.push(ston(s2,1.0));
      }
      s2.clear();
    }
  }
  return n.top();
}

vector<string> Split(char c,string s){
  vector<string> res(0);
  string str = "";
  rep(i,s.size()){
    if(s[i] == c){
      if(str.size()){
        res.push_back(str);
      }
      str.clear();
    }
    else{
      str += s[i];
    }
  }
  res.push_back(str);
  return res;
}
bool check(string s1,string s2){
  if(((s1 == "+" || s1 == "-" ) && s2 != "(")|| s1 == s2) return true;
  if((s1 == "*" || s1 == "/")&& (s2 == "+" || s2 == "-")) return false;
  if(s2 == "(") return false;
}
string ConvertRPN(string s){
  const string notnumber = "+-*/() ";
  stack<string> fom;
  auto str = Split(' ',s);
  string res = "";
  rep(i,str.size()){
    if(notnumber.find(str[i]) == string::npos){
      res += str[i];
      res += " ";
    }
    else if(str[i] == ")"){
      while(fom.top() != "("){
        if(fom.top() != " "){
          res += fom.top();
          res += " ";
        }
        fom.pop();
      }
      fom.pop();
    }
    else if(str[i] == "(" || fom.empty()){
      fom.push(str[i]);
    }
    else if(check(str[i],fom.top())){
      while(!fom.empty() && check(str[i],fom.top())){
        if(fom.top() != " "){
          res += fom.top();
          res += " ";
        }
        fom.pop();
      }
      fom.push(str[i]);
    }
    else{
      fom.push(str[i]);
    }
  }
  while(fom.size()){
    if(fom.top() != " "){
      res += fom.top();
      res += " ";
    }
    fom.pop();
  }
  res.resize(res.size()-1);
  return res;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll n;
  cin >> n;
  rep(i,n){
    string s,res = "";
    cin >> s;
    rep(i,s.size()){
      if(find(all(op),s[i]) == op.end()){
        res += s[i];
      }
      else{
        if(res[res.size()-1] != ' ' )
        res += " ";
        res += s[i] ;
        res += " ";
      }
    }
    res.resize(res.size()-3);
    res = ConvertRPN(res);
    cout << RPN(res)<<endl;
  }
  return 0;
}
