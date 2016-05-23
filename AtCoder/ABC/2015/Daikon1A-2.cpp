#include <bits/stdc++.h>
using namespace std ;

#define pb(n) push_back(n)
#define fi first
#define se second
#define np string::npos
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
#define repc(i,a,b) for(int i = (a);i < (int)(b);++i)
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
struct data{
  int i,j,max;
};
vector<vector<int>> sq(30,vector<int>(30));
data d{0,0,0};
int findmax(){
  int n = 0;
  d = data{0,0,0};
  rep(i,30){
    rep(j,30){
      n+=sq[i][j];
      if(d.max <sq[i][j]){
        d.max = sq[i][j];
        d.i = i;
        d.j = j;
      }
    }
  }
  return n;
}
void Solve(){
  int n = 0;
  while(findmax() != 0){
    bool f = false;
    do{
      f = false;
      if(sq[d.i][d.j] > 0){
        cout << d.i+1 << " " << d.j+1 << endl;
        sq[d.i][d.j]--;
        vector<vector<vector<int>>> sqn(4);
        vector<string> s(4);
        int ans[4] = {},j = 0;
        bool f2 = false;
        rep(i,4){
          if(!f2){
            f2 = true;
            j = i;
            sqn[j] = sq;
          }
          if(d.i+dx[i] >= 0 && d.i+dx[i] < 30 && d.j + dy[i]>=0 && d.j + dy[i]<30){
            if(sqn[j][d.i+dx[i]][d.j+dy[i]] == sqn[j][d.i][d.j]){
              if(sqn[j][d.i+dx[i]][d.j+dy[i]] != 0){
                --sqn[j][d.i+dx[i]][d.j+dy[i]];
                d.i += dx[i];
                d.j += dy[i];
                s[j] += to_string(d.i+1)+ " " + to_string(d.j+1)+"\n";
                ++ans[j];
                f = true;
              }
              break;
            }
          }
        }
        int a = 10000000,b=0;
        rep(i,4){
          if(a>ans[i]){
            a = ans[i];
            b = i;
          }
        }
        n += ans[b];
        cout << s[b] ;
      }
      else break;
    }while(f);
  }
  cout << n << endl;
}
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  rep(i,30){
    rep(j,30){
      cin >> sq[i][j];
    }
  }
  Solve();
  //   rep(i,30){
  //     rep(j,30){
  //       cout << sq[i][j] << " ";
  //     }
  //     cout << endl;
  //   }

  return 0;
}
