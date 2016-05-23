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

#define rep(i,n) for(int i = 0; i < (int)(n);++i)
#define REP(i,a,b) for(int i = (a);i < (int)(b);++i)
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
int ans;
int dp[1<<20];
int nums[101] ;
int N;
ll res;

bool solve(int state, int rem){
  if(state >= 1<<20 || dp[state] == 1 ) return false;
  dp[state] = 1;
  int num = nums[0];
  REP(i,1,N-1-rem){
    if((state & (1 << (i-1))) == 1){
      num -= nums[i];
    }
    else{
      num += nums[i];
    }
  }
  if(rem > 0){
    REP(i,N-1 - rem,N-2){
      solve(state | (1 << i),rem-1);
    }
  }
//   string s ="";
  num = nums[0];
//   s += to_string(nums[0]);
  REP(i,1,N-1){
    if((state & (1 << (i-1))) != 0){
//       s += "-" + to_string(nums[i]);
      num -= nums[i];
    }
    else{
//       s += "+" + to_string(nums[i]);
      num += nums[i];
    }
    if(num < 0 || num > 20){
      return false;
    }
  }
  if(num == ans){
//     cout << s << endl;
//     cout << static_cast<std::bitset<10>>(state) << " " << num << endl;
    ++res;
    return true;
  }
  return false;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin >> N;
  rep(i,N-1){
    cin >> nums[i];
  }
  cin >> ans;
  solve(0,N-1);
  cout << res << endl;
//   string s ="";
//   s += to_string(nums[0]);
//   int num = nums[0],state = 246;
//   REP(i,1,N-1){
//     if((state& (1 << (i-1))) != 0){
//       s += "-" + to_string(nums[i]);
//       num -= nums[i];
//     }
//     else{
//       s += "+" + to_string(nums[i]);
//       num += nums[i];
//     }
//     if(num < 0 || num > 20){
//       return false;
//     }
//   }
//   if(num == ans){
//     cout << s << endl;
//     cout << static_cast<std::bitset<10>>(state) << " " << num << endl;
//     ++res;
//   }
  return 0;
}
