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
using comd = complex<double>;
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
  v.erase(all(v),v.end());
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
int dx2[] = {1,1,1,-1,-1,-1,0,0};
int dy2[] = {1,0,-1,-1,0,1,1,-1};
int m[10][10];
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  char c;
  int x,y,s,a1 = 100,a2 = 0;
  while(cin>>x>>c>>y>>c>>s){
    if(s == 1){
      if(m[x][y] == 0)
        --a1;
      m[x][y]++;
      rep(i,4){
        int X = x+dx[i],Y=y+dy[i];
        if(value(x+dx[i],y+dy[i],10,10)){
          if(m[X][Y] == 0)
            --a1;
          m[x+dx[i]][y+dy[i]]++;
          if(m[X][Y] > a2){
            a2 = m[X][Y];
          }
        }
      }
    }
    else if(s == 2){
      if(m[x][y] == 0)
        --a1;
      m[x][y]++;
      rep(i,8){
        int X = x+dx2[i],Y=y+dy2[i];
        if(value(x+dx2[i],y+dy2[i],10,10)){
          if(m[X][Y] == 0)
            --a1;
          m[x+dx2[i]][y+dy2[i]]++;
          if(m[X][Y] > a2){
            a2 = m[X][Y];
          }
        }
      }
    }
    else{
      if(m[x][y] == 0)
        --a1;
      m[x][y]++;
      rep(i,8){
        int X = x+dx2[i],Y=y+dy2[i];
        if(value(X,Y,10,10)){
          if(m[X][Y] == 0)
            --a1;
          m[X][Y]++;
          if(m[X][Y] > a2){
            a2 = m[X][Y];
          }
        }
      }
      rep(i,4){
        int X = x+dx[i]*2,Y=y+dy[i]*2;
        if(value(X,Y,10,10)){
          if(m[x+dx[i]*2][y+dy[i]*2] == 0)
            --a1;
          m[x+dx[i]*2][y+dy[i]*2]++;
          if(m[X][Y] > a2){
            a2 = m[X][Y];
          }
        }
      }
    }
  }
  cout << a1 << endl;
  cout << a2 <<endl;
  return 0;
}
