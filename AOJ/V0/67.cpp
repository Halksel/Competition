#include <bits/stdc++.h>
using namespace std ;

#define pb(n) push_back(n)
#define fi first
#define se second
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

double CalcDist(comd p1, comd p2){
  return sqrt(pow(p1.X - p2.X,2.0) + pow(p1.Y -p2.Y,2.0));
}

template <typename T>
void out(deque < T > d)
{
  for(size_t i = 0; i < d.size(); i++)
  {
    debug(d[i]);
  }
}

template<typename T>
T ston(string& str, T n){
  istringstream sin(str) ;
  T num ;
  sin >> num ;
  return num ;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  while(1){
    vary(string,s,12,"");
    rep(i,12){
      cin >> s[i];
      if(cin.eof()) goto LABEL;
    }
    int x = 0,y = 0,ans = 0;
    bool f = true;
    while(f){
      rep(i,12){
        rep(j,12){
          if(s[i][j] == '1'){
            x = i;
            y = j;
            i = 12;
            j = 12;
            break;
          }
        }
        if(i == 11){
          f = false;
        }
      }
      if(f){
        queue<pii> q;
        q.push(make_pair(x,y));
        while(!q.empty()){
          pii pos = q.front();q.pop();
          s[pos.fi][pos.se] = '.';
          rep(i,4){
            x = pos.fi+dx[i],y = pos.se+dy[i];
            if(value(x,y,12,12)){
              if(s[x][y] == '1'){
                s[x][y] = '.';
                q.push(make_pair(x,y));
              }
            }
          }
        }
        ++ans;
      }
    }
    cout << ans << endl;
  }
LABEL:
  return 0;
}
