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
class ParenthesesDiv2Medium {
  public:
  vector<int> correct(string s) {
    bool f = true;
    set<int> si;
    vector<int> vi1,vi2;
    //ペアを作る
    rep(i,s.size()){
      if(i % 2 == 0){
        if(s[i] == ')'){
          vi1.push_back(i);
        }
      }
      else{
        if(s[i] == '('){
          vi1.push_back(i);
        }
      }
    }
    //成立しているペアのくりぬき
    while(f){
      bool g = false,h = false;
      int k = 0;
      rep(i,s.size()-1){
        if(si.find(i) == si.end()){
          if(s[i] == '('){
            k = i;
            g = true;
          }
          else{
            if(g){
              si.insert(k);
              si.insert(i);
              g = 0; h = true;
            }
          }
        }
      }
      if(h == false){
        f = 0;
      }
    }
    //
    for(auto n: si){
      cout << n<<" ";
    }
    cout << endl;
    int k = 0;
    rep(i,s.size()){
      if(si.find(i) == si.end()){
        if(k % 2 == 0){
          if(s[i] == ')'){
            vi2.push_back(i);
          }
        }
        else{
          if(s[i] == '('){
            vi2.push_back(i);
          }
        }
        ++k;
      }
    }
    cout << "v1\n";
    for(auto n: vi1){
      cout << n << " ";
    }
    cout << endl;
    cout << "v2\n";
    for(auto n: vi2){
      cout << n <<" ";
    }
    cout << endl;
    if(vi1.size() < vi2.size()){
      return vi2;
    }
    return vi1;
  }
};

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  ParenthesesDiv2Medium pd2;
  string s;
  cin >> s;
  auto n =pd2.correct(s);
  return 0;
}
