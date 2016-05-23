#include <bits/stdc++.h>
using namespace std ;

#define pb(n) push_back(n)
#define fi first
#define se second
#define X real()
#define Y imag()
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
const int MAX =1000001;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int tmp=0,k = 1,n;
  vector<int> suqnum(0),odd(0);
  while(tmp < MAX){
    tmp = k * (k + 1) * (k + 2) / 6;
    suqnum.pb(tmp);
    if(tmp%2==1){
      odd.pb(tmp);
    }
    ++k;
  }
//   reverse(all(suqnum));
//   reverse(all(odd));
  int *dp = new int[tmp+1];
  int *dp2 = new int[tmp+1];
  rep(i,suqnum.size()){
    dp[suqnum[i]] = 1;
  }
  rep(i,odd.size()){
    dp[odd[i]] = 1;
  }
  rep(j,suqnum.size()){
    rep(i,1000000){
      if(i - suqnum[j] >= 0){
        if(dp[i] != 0){
          dp[i] = min(dp[i],dp[i-suqnum[j]]+1);
        }
        else{
          dp[i] = dp[i-suqnum[j]]+1;
        }
      }
    }
  }
  rep(j,odd.size()){
    rep(i,1000000){
      if(i - odd[j] >= 0){
        if(dp2[i] != 0){
          dp2[i] = min(dp2[i],dp2[i-odd[j]]+1);
        }
        else{
          dp2[i] = dp2[i-odd[j]]+1;
        }
      }
    }
  }
  while(cin >> n){
    if(n == 0)break;
    cout << dp[n] << " " << dp2[n]<<endl;
  }
  return 0;
}
