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

bool solve(char c1,char c2, char c3){
  if(c1 == c2 && c2 == c3 && c1 != '+'){
    cout << c1 << endl;
    return true;
  }
  return false;
}
int a[] = {0,3,6};
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  string s,s2;
  while(1){
    bool f = false,f2 = false;
    s.clear();
    rep(i,3){
      cin >> s2;
      if(s2 == "0"){
        f2 = true;
        break;
      }
      s += s2;
    }
    if(f2) break;
    rep(i,3){
      if(solve(s[a[i]],s[a[i]+1],s[a[i]+2])){
        f = true;
        break;
      }
    }
    if(!f){
      rep(i,3){
        if(solve(s[i],s[i+3],s[i + 6])){
          f = true;
          break;
        }
      }
    }
    if(!f){
      if(!solve(s[0],s[4],s[8])){
        if(solve(s[2],s[4],s[6])){
          f = true;
        }
      }
      else f = true;
    }
    if(!f){
      cout << "NA"<<endl;
    }
  }
  return 0;
}

