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
vector<string> vs;
int quack(string s) {
  int ans = 0;
  const string q = "quack";
  bool f = true;
  vs.clear();
  while(s.size() != 0 && f){
    f = false;
//     string s2 = "";
    int k = 0;
    for(int i = 0;i < s.size();++i){
      if(s[i] == q[k]){
        ++k;
        if(k == 5){
          k = 0;
          f = true;
        }
//         s2 += s[i];
        s[i] = ' ';
      }
//       else{
//         s2 += '_';
//       }
    }
    if(k != 0){
      f = false;
    }
//     vs.pb(s2);
    if(f){
      ++ans ;
      for(size_t c = s.find_first_of(" "); c != string::npos; c = s.find_first_of(" ")){
        s.erase(c,1);
      }
    }
    else break;
  }
//   for(auto n : vs){
//     cout << n << endl;
//   }
  if(!f) return -1;
  return ans;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  string s ="quackqauckquack";
  cout << quack(s) << endl;
  s = "quqacukqauackck";
  cout << quack(s) << endl;
  s = "kcauq";
  cout << quack(s) << endl;
  s = "quackquackquackquackquackquackquackquackquackquack";
  cout << quack(s) << endl;
  s =  "qqqqqqqqqquuuuuuuuuuaaaaaaaaaacccccccccckkkkkkkkkk" ;
  cout << quack(s) << endl;
  s = "quqaquuacakcqckkuaquckqauckack" ;
  cout << quack(s) << endl;
  s = "quackqauckquack" ;
  cout << quack(s) << endl;
  return 0;
}
