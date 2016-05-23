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
  int w,n;
  int cnt = 1;
  char c;
  while(cin >> w){
    if(w == 0) break;
    cin >> n;
    vary(int,vs,n,0);
    vary(int,ws,n,0);
    vector<vector<pii>> dp(n+1,vector<pii>(w+1,make_pair(0,0)));
    rep(i,n){
      cin >> vs[i] >> c >> ws[i];
    }
    REP(i,0,n){
      rep(j,w+1){
        if(j <ws[i]){
          dp[i+1][j] = dp[i][j];
        }
        else{
          pii tmp;
          if(dp[i][j].fi < dp[i][j-ws[i]].fi+vs[i]){
            int k = dp[i][j-ws[i]].fi+vs[i];
            tmp = make_pair(k,j);
          }
          else{
            tmp = dp[i][j];
          }
          dp[i+1][j] = tmp;
        }
      }
    }
    cout << "Case " + to_string(cnt) + ":"<<endl;
    cout << dp[n][w].fi <<endl;
      rep(i,w+1){
      if(dp[n][i].fi == dp[n][w].fi){
        cout << i << endl;
        break;
      }
    }
    ++cnt;
  }
  return 0;
}
