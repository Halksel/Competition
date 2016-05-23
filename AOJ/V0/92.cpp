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
int N;
vector<vector<char>> square;
bool ok(int j,int i, int mid){
  REP(l,i,N){
    rep(k,mid){
      if(value(j+k,l,N,N)){
        if(square[j+k][l] == '*'){
          return false;
        }
      }
    }
  }
  return true;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  while(cin >> N){
    if(N == 0) break;
    int ans = -1;
    square = vector<vector<char>>(N,vector<char>(N));
    vector<vector<int>> imos(N+5,vector<int>(N+5));
    rep(i,N){
      rep(j,N){
        cin >> square[j][i];
        if(square[j][i] != '.'){
          imos[j+1][i+1] = 1;
        }
      }
    }
    rep(i,N+1){
      rep(j,N+1){
        imos[j+1][i] += imos[j][i];
      }
    }
    rep(j,N+1){
      rep(i,N+1){
        imos[j][i+1] += imos[j][i];
      }
    }
    REP(j,1,N+1){
      REP(i,1,N+1){
        if(imos[i][j] == 0){
          ans = max(0,ans);
        }
        int lb=0,ub = N+1;
        rep(k,15){
          int mid = (lb+ub)/2;
          if(mid == lb) break;
          if(mid+i >= N+1 || mid+j >= 1+N){
            mid = N - max(i,j);
          }
          if(imos[mid+i][mid+j] + imos[i-1][j-1] - imos[mid+i][j-1] -imos[i-1][mid+j] == 0){
            //               cout << mid << " " << i << " " << j << endl;
            lb = mid;
            ans = max(ans,mid);
          }
          else{
            ub = mid;
          }
        }
      }
    }
    cout << ans +1<< endl;
  }
  return 0;
}
