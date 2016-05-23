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
const int dx[] = {0,1,0,-1};
const int dy[] = {-1,0,1,0};
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int d;
  cin >> d;
  rep(i,d){
    if(i != 0) cout << endl;
    int n;
    cin >> n;
    vector<vector<char>> v(n,vector<char>(n,' '));
    rep(i,n){
      v[0][i] = '#';
    }
    if(n % 2){
      int cnt = n-1,dir = 1,x = 0,y = 0;
      v[x][y] = '#';
      while(cnt > 0){
        rep(j,2){
          rep(k,cnt){
            x += dx[dir];
            y += dy[dir];
            if(value(x,y,n,n))
                v[x][y] ='#';
          }
          ++dir;
          dir %=4;
        }
        cnt -= 2;
      }
    }
    else{
      int cnt = n-1,dir = 1,x = 0,y = 0;
      while(cnt > 0){
        rep(j,2){
          rep(k,cnt){
            x += dx[dir];
            y += dy[dir];
            if(value(x,y,n,n))
                v[x][y] ='#';
          }
          ++dir;
          dir %= 4;
        }
        cnt -=2;
      }
      v[n/2][n/2] = ' ' ;
    }
    rep(i,n){
      rep(j,n){
        cout << v[j][i];
      }
      cout << endl;
    }
  }
  return 0;
}
