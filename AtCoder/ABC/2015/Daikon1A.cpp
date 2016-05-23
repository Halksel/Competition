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
const int size = 30;
vector<vector<int>> sq(size,vector<int>(size));
data d{0,0,0};
int findmax(){
  int n = 0;
  d = data{0,0,0};
  rep(i,size){
    rep(j,size){
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
  int n = 0,k=0;
  while(findmax() != 0){//1~3のループ
    bool f = false;
    vector<vector<vector<int>>> sqn(4);
    vector<string> s(4);
    int ans[4] = {0,0,0,0};
    data d2 = d;
    rep(j,4){
      d = d2;
      s[j] = "";
      f = false;
      sqn[j] = sq;
      if(sq[d.i][d.j] > 0){//0よりも大きいならステップ2へ
        s[j] += to_string(d.i+1)+ " " +to_string(d.j+1) +"\n";
        sqn[j][d.i][d.j]--;
        ++ans[j];
        if(value(d.i+dx[j],d.j+dy[j],size,size)){
          if(sqn[j][d.i+dx[j]][d.j+dy[j]] == sqn[j][d.i][d.j] && sqn[j][d.i+dx[j]][d.j+dy[j]] != 0){
            d.i += dx[j];
            d.j += dy[j];
            f = true;
          }
        }
      }
      while(f){//2~3のループ
        f = false;
        if(sqn[j][d.i][d.j] > 0){//0よりも大きいならステップ2へ
          s[j] += to_string(d.i+1)+ " " +to_string(d.j+1) +"\n";
          sqn[j][d.i][d.j]--;
          ++ans[j];
          rep(i,4){
            if(value(d.i+dx[i],d.j+dy[i],size,size)){
              if(sqn[j][d.i+dx[i]][d.j+dy[i]] == sqn[j][d.i][d.j] && sqn[j][d.i+dx[i]][d.j+dy[i]] != 0){
                d.i += dx[i];
                d.j += dy[i];
                f = true;
                break;
              }
            }
          }
        }
      }
    }
    int a = 0,b=0;
    rep(i,4){
      if(a<ans[i]){
        a = ans[i];
        b = i;
      }
    }
    //     debug(b);
    ++n;
    k += ans[b];
//     if(n > 30) break;
//     if(ans[b] > 1) cout << "comb:" << ans[b] <<endl;
    cout << s[b] ;
    sq = sqn[b];
//       rep(i,size){
//         rep(j,size){
//           cout << sq[i][j] << " ";
//         }
//         cout << endl;
//       }
  }
//   cout << n << "= n, k = " << k << endl;
}
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  rep(i,size){
    rep(j,size){
      cin >> sq[i][j];
    }
  }
  Solve();

  return 0;
}
