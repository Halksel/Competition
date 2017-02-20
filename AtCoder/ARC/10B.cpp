#include <bits/stdc++.h>
using namespace std ;

#define pb(n) push_back(n)
#define fi first
#define se second
#define all(r) begin(r),end(r)
#define vmax(ary) *max_element(all(ary))
#define vmin(ary) *min_element(all(ary))
#define debug(x) cout<<#x<<": "<<x<<endl
#define fcout(n) cout<<fixed<<setprecision((n))
#define scout(n) cout<<setw(n)
#define vary(type,name,size,init) vector< type> name(size,init)
#define vvl(v,w,h,init) vector<vector<ll>> v(w,vector<ll>(h,init))
#define mp(a,b) make_pair(a,b)

#define rep(i,n) for(int i = 0; i < (int)(n);++i)
#define REP(i,a,b) for(int i = (a);i < (int)(b);++i)
#define repi(it,array) for(auto it = array.begin(),end = array.end(); it != end;++it)
#define repa(n,array) for(auto &n :(array))

using ll = long long;
using pii = pair<int,int> ;
using pll = pair<ll,ll> ;

template<typename T>
void O(T t){
  cout << t << endl;
}

const int mod = 1000000007;
constexpr ll inf = ((1<<30)-1)*2+1 ;
constexpr double PI = acos(-1.0) ;
double eps = 1e-10 ;
const int dy[] = {-1,0,1,0,1,-1,1,-1};
const int dx[] = {0,-1,0,1,1,-1,-1,1};

const int day[12] = {31,29,31,30,31,30,31,31,30,31,30,31};
int days[12] ;
int s(int m,int d){
  return days[m - 1] + d - 1;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n,m,d;
  cin >> n;
  char c;
  vector<int> v(380);
  rep(i,11){
    days[i+1] = day[i] + days[i];
  }
  rep(i,380){
    if(i % 7 == 0) v[i] = 1;
    if(i % 7 == 6) v[i] = 1;
  }
  rep(i,n){
    cin >> m >> c >> d;
    v[s(m,d)]++;
  }
  rep(i,380){
    if(v[i] > 1){
      int k = i;
      while(v[i] != 1 && k < 380){
        if(v[k] == 0){
          v[k]++;
          v[i]--;
        }
        ++k;
      }
    }
  }
  int ans = 0,res = 0;
  rep(i,366){
    if(v[i]){
      ++res;
    }
    else{
      ans = max(ans,res);
      res = 0;
    }
  }
      ans = max(ans,res);
  O(ans);
  return 0;
}

