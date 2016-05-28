#include <bits/stdc++.h>
using namespace std ;

#define pb(n) push_back(n)
#define fi first
#define se second
#define np string::npos
#define X real()
#define Y imag()
#define value(x,y,w,h) (x >= 0 && x < w && y >= 0 && y < h)
#define all(r) (r).begin(),(r).end()
#define gsort(st,en) sort((st),(en),greater<int>())
#define vmax(ary) *max_element(all(ary))
#define vmin(ary) *min_element(all(ary))
#define debug(x) cout<<#x<<": "<<x<<endl
#define fcout(n) cout<<fixed<<setprecision((n))
#define scout(n) cout<<setw(n)

#define rep(i,n) for(int i = 0; i < (int)(n);++i)
#define repc(i,a,b) for(int i = (a);i < (int)(b);++i)
#define repi(it,array) for(auto it = array.begin(),end = array.end(); it != end;++it)
#define repa(n,array) for(auto &n :(array))

typedef long long ll ;
typedef deque<int> di ;
typedef deque<ll> dl ;
typedef map<string,int> dict;
typedef complex<double> comd;
typedef pair<int,int> pii;

constexpr int imax = ((1<<30)-1)*2+1 ;
constexpr int inf = 100000000;
constexpr double PI = acos(-1.0) ;
double eps = 1e-10 ;
const int dy[] = {-1,0,1,0};
const int dx[] = {0,-1,0,1};

template<typename T>
T ston(string& str, T n){
  istringstream sin(str) ;
  T num ;
  sin >> num ;
  return num ;
}

string op = "+-/*";

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  string s,s2;
  double ans;
  stack<double> n;
  while(1){
    getline(cin,s);
    if(cin.eof()) break;
    ans = 0;
    s += ' ' ;
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
    fcout(6) << n.top() << endl;
  }
  return 0;
}
