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
int N,W;
vector<vector<char>> square;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  while(cin >> N>>W&&N){
    int ans = -1;
    square = vector<vector<char>>(N,vector<char>(W));
    vector<vector<int>> imos(N+5,vector<int>(W+5));
    rep(i,N){
      rep(j,W){
        cin >> square[j][i];
        if(square[j][i] != '.'){
          imos[j+1][i+1] = 1;
        }
      }
    }
    rep(i,N+1){
      rep(j,W+1){
        imos[j+1][i] += imos[j][i];
      }
    }
    rep(j,W+1){
      rep(i,N+1){
        imos[j][i+1] += imos[j][i];
      }
    }
    REP(j,1,N+1){
      REP(i,1,W+1){
        if(imos[i][j] == 0){
          ans = max(0,ans);
        }
        int lb=0,ub = W+1;
        rep(k,15){
          int mid = (lb+ub)/2;
          if(mid == lb) break;
          if(mid+i >= W+1){
            mid = W - i;
          }
          if(imos[mid+i][j] - imos[i-1][j] == 0){
            lb = mid;
            ans = max(ans,mid);
            int lb2=0,ub2 = N+1;
            rep(k,15){
              int mid2 = (lb2+ub2)/2;
              if(mid2 == lb2) break;
              if(mid2+i >= N+1){
                mid2 = N - i;
              }
              if(imos[i+mid][mid2+j] + imos[i-1][j-1] - imos[i-1][j+mid2] == 0){
                lb2 = mid2;
                cout << i << " " << j << " " <<mid << " " << mid2<<endl;
                ans = max(ans,mid2*mid);
              }
              else{
                ub2 = mid2;
              }
            }
          }
          else{
            ub = mid;
          }
        }
      }
    }
    cout << ans<< endl;
  }
  return 0;
}

