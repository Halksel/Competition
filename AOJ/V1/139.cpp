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

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n;
  string s;
  cin >> n;
  rep(i,n){
    cin >> s;
    if(s[0] != '>'|| s.size() < 6 || s.size()%2 == 1|| (s[1] != '\'' && s[1] != '^') ){
      cout << "NA"<<endl;
    }
    else if(s[1] == '\''){
      int cnt = 0;
      bool f = true;
      REP(i,2,s.size()-1){
        if(s[i] == '#' && f){
          cnt *= -1;
          f = false;
        }
        else if(s[i] == '='){
          ++cnt;
        }
        else{
          cnt = -1;
          break;
        }
      }
      if(cnt != 0 || s[s.size()-1] != '~'){
        cout << "NA"<<endl;
      }
      else{
        cout << "A"<<endl;
      }
    }
    else{
      bool f = false;
      for(int i = 2; i < s.size(); i+=2){
        if(!(s[i] == 'Q' && s[i+1] == '=')){
          if(s[i] == '~' && s[i+1] == '~' && i == s.size()-2){
            cout << "B"<<endl;
            f = true;
          }
          else{
            break;
          }
        }
      }
      if(!f) cout << "NA"<<endl;
    }
  }
  return 0;
}
