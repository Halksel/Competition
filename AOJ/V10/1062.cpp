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

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n,h,m,m2,l,d,mn;
  int lc,dc,mnc;
  char c;
  while(cin >> n){
    if(n == 0) break;
    l = d = mn = 0;
    lc = dc = mnc = 0;
    rep(_,n){
      cin >> h >> c >> m >> m2;
      if(11 <= h && h <= 14){
        ++lc;
        if(m2 - m >= 0 && m2-m <9){
          ++l;
        }
        else if(m2 - m < 0 && 60 - m + m2 <9){
          ++l;
        }
      }
      else if ( 18 <= h && h <= 20){
        ++dc;
        if(m2 - m >= 0 && m2-m <9){
          ++d;
        }
        else if(m2 - m < 0 && 60 - m + m2 <9){
          ++d;
        }
      }
      else if((21 <= h && h <= 23) ||(0 <= h && h <= 1)){
        ++mnc;
        if(m2 - m >= 0 && m2-m <9){
          ++mn;
        }
        else if(m2 - m < 0 && 60 - m + m2 <9){
          ++mn;
        }
      }
    }
    cout << "lunch ";
    if(lc != 0)
      cout<< (int)(1.0*l/lc*100 )<< endl;
    else
      cout << "no guest" <<endl;
    cout << "dinner ";
    if(dc != 0)
      cout << (int)(1.0*d/dc*100 )<< endl;
    else
      cout << "no guest" <<endl;
    cout << "midnight ";
    if(mnc != 0)
      cout << (int)(1.0*mn/mnc*100 )<< endl;
    else
      cout << "no guest" <<endl;
  }
  return 0;
}
