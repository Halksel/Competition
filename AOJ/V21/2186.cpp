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

struct path{
  ll sx,sy,ex,ey;
  bool operator==(const path& p){
    return sx == p.sx && sy == p.sy && ex == p.ex && ey == p.ey;
  }
};

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll n,h,w,x,y,x1,y1;
  cin >>n;
  rep(i,n){
    cin >> w >> h;
    vector<vector<ll>> dp(w+3,vector<ll>(h+3,0));
    ll k;
    cin >> k;
    vector<path> p(k);
    rep(j,k){
      cin >> x >> y >> x1 >> y1;
      if(x > x1){
        swap(x,x1);
      }
      if(y > y1){
        swap(y,y1);
      }
      p[j] = path{x,y,x1,y1};
    }
    dp[0][0] = 1;
    rep(l,h+1){
      rep(j,w+1){
        if(find(all(p),path{j,l,j+1,l}) == p.end()){
          dp[j+1][l] += dp[j][l];
        }
        if(find(all(p),path{j,l,j,l+1}) == p.end()){
          dp[j][l+1] += dp[j][l];
        }
      }
    }
    if(dp[w][h]){
      cout << dp[w][h]<<endl;
    }
    else{
      cout << "Miserable Hokusai!"<<endl;
    }
//     rep(j,h-1){
//       rep(l,w-1){
//         cout << dp[l][j] << " ";
//       }
//       cout << endl;
//     }
  }

  return 0;
}
