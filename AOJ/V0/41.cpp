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

template<typename T>
T ston(string& str, T n){
  istringstream sin(str) ;
  T num ;
  sin >> num ;
  return num ;
}

const string op[4] = {"+","-","*","/"};
const string pare[] = {"(.!.)!.!.",".!.!(.!.)",".!(.!.)!.","(.!.)!(.!.)","(.!.!.)!.",".!(.!.!.)","(.!(.!.))!.","((.!.)!.)!.",".!((.!.)!.)",".!(.!(.!.))",".!.!.!."};

double RPN(string str){
  string s,s2;
  double ans;
  stack<double> n;
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
  bool f = true;
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
  vary(ll,v,4,0);
  while(cin >> v[0] >> v[1] >> v[2] >> v[3] && v[0] && v[1] && v[2] && v[3]){
    sort(all(v));
    bool f = false;
    do{
      rep(i,4){
        rep(j,4){
          rep(k,4){
            string formula = op[i]+op[j] + op[k];
            rep(m,10){
              ll c = 0,d = 0;
              string res ="";
              rep(l,pare[m].size()){
                if(pare[m][l] == '.'){
                  res += to_string(v[c])+ " ";
                  ++c;
                }
                else if(pare[m][l] == '!'){
                  res += formula[d];
                  res += " ";
                  ++d;
                }
                else{
                  res += pare[m][l];
                  res += " ";
                }
              }
              res.resize(res.size()-1);
              string tmp = res;
              res = ConvertRPN(res);
              if(RPN(res) == 10){
                cout << tmp<<endl;
                f = true;
                i = j = k = 4;
                v.clear();
                break;
              }
            }
          }
        }
      }
    }while(next_permutation(all(v)));
    if(!f){
      cout << 0 << endl;
    }
    v.resize(4);
  }
  return 0;
}
