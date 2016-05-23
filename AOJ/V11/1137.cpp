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

void Ans(bool f){
  if(f) cout << "YES"<<endl;
  else cout << "NO"<<endl;
}

vector<string> Split(char c,string s){
  vector<string> res(0);
  string str = "";
  rep(i,s.size()){
    if(s[i] == c){
      res.push_back(str);
      str.clear();
    }
    else{
      str += s[i];
    }
  }
  res.push_back(str);
  return res;
}
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll n;
  cin >> n;
  string s;
    cin.ignore();
  rep(l,n){
    getline(cin,s);
    auto vs = Split(' ',s);
    ll tmp = 1,num = 0;
    rep(i,2){
      rep(j,vs[i].size()){
        if(vs[i][j] - '0' > 1 && vs[i][j] - '0' < 10){
          tmp = vs[i][j] -'0';
        }
        else{
          if(vs[i][j] == 'm'){
            num += 1000 * tmp;
          }
          else if(vs[i][j] == 'c'){
            num += 100 * tmp;
          }
          else if(vs[i][j] == 'x'){
            num += 10 * tmp;
          }
          else{
            num += tmp;
          }
          tmp = 1;
        }
      }
    }
//     cout << num <<endl;
    string ans = "";
    if(num/1000){
      if(num/1000 != 1){
        ans += to_string(num/1000);
      }
      ans += "m";
    }
    num %= 1000;
    if(num/100){
      if(num/100 != 1){
        ans += to_string(num/100);
      }
      ans += "c";
    }
    num %= 100;
    if(num/10){
      if(num/10 != 1){
        ans += to_string(num/10);
      }
      ans += "x";
    }
    if(num % 10){
      if(num % 10 != 1){
        ans += to_string(num % 10);
      }
      ans += "i";
    }
    cout << ans << endl;
  }
  return 0;
}
