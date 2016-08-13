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

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n;
  char x;
  while(cin>>n && n){
    vector<vector<int>> vc(n,vector<int>(n,0));
    rep(i,n){
      rep(j,n){
        cin >> x;
        vc[j][i] = x;
        vc[j][i] -= '0';
      }
    }
    auto tmp = vc;
    int ma = 0;
    rep(i,n){
      rep(j,n){
        if( j > 0 && tmp[j][i]){
          tmp[j][i] += tmp[j-1][i];
        }
        ma = max(ma,tmp[j][i]);
      }
    }
    tmp = vc;
    rep(j,n){
      rep(i,n){
        if( i > 0 && tmp[j][i]){
          tmp[j][i] += tmp[j][i-1];
        }
        ma = max(ma,tmp[j][i]);
      }
    }
    //右上->左下
    tmp = vc;
    rep(i,n){
      rep(j,n){
        if( j < n-1 && i > 0&& tmp[j][i]){
          tmp[j][i] += tmp[j+1][i-1];
        }
        ma = max(ma,tmp[j][i]);
      }
    }
    //左上->右下
    tmp = vc;
    rep(i,n){
      rep(j,n){
        if( j > 0 && i > 0 && tmp[j][i]){
          tmp[j][i] += tmp[j-1][i-1];
        }
        ma = max(ma,tmp[j][i]);
      }
    }
    cout << ma << endl;
  }
  return 0;
}
