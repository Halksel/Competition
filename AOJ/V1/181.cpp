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

int m, n;
bool check(vector<int> v,int mid){
  int h = 1;
  int w = 0;
  rep(i,n){
    if(v[i] > mid){
      return false;
    }
    if(w + v[i] <= mid){
      w += v[i];
    }
    else{
      w = v[i];
      ++h;
    }
  }
  if(h > m){
    return false;
  }
  return true;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  while(cin >> m >> n&&m&&n){
    vary(int,v,n,0);
    rep(i,n){
      cin >> v[i];
    }
    int lb = 0,ub = 1500000;
    while(1){
      int mid = (lb+ub)/2;
      if(mid == ub) break;
      if(check(v,mid)){
        ub = mid;
      }
      else{
        lb = mid+1;
      }
    }
    cout << ub << endl;
  }
  return 0;
}
