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

unsigned long long int ulli;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int N;
  string s1,s2,ans(105,' ');
  cin >> N;
  rep(i,N){
    cin >> s1 >> s2;
    ans = string(105,' ') ;
    if(s1.size()> 80 || s2.size() > 80){
      cout << "overflow" << endl;
      continue;
    }
    int a,b,c = 0;
    bool f = s1.size() >= s2.size();
    for(int i = 0;i <min(s1.size(),s2.size());++i){
      if(f){
        a = s1[s1.size()-1-i] - '0' ;
        b = s2[s2.size()-1-i] - '0' ;
      }
      else{
        a = s1[s1.size()-1-i] - '0' ;
        b = s2[s2.size()-1-i] - '0' ;
      }
//       debug((a+b+c)%10+'0');
      ans[ans.size()-1-i] = (a+b+c)%10+'0';
      c = (a+b+c)/10;
//       cout << ans.size()-1-i << " :" << a << " :" << b << " :" << c <<endl;
    }
    for(int i = min(s1.size(),s2.size()); i < max(s1.size(),s2.size());++i){
      if(f){
        ans[ans.size()-1-i] = (s1[s1.size()-1-i] - '0' + c)%10+'0';
        c = (s1[s1.size()-1-i] - '0' + c )/10;
      }
      else{
        ans[ans.size()-1-i] = (s2[s2.size()-1-i] + c - '0')%10+'0';
        c = (s2[s2.size()-1-i] + c - '0')/10;
      }
    }
    if(c > 0){
//       cout << ans << "c :"<<  c << endl;
      ans[0] = c +'0' ;
    }
    if(ans.size()-count(all(ans),' ') > 80){
      cout << "overflow" << endl;
      continue;
    }
    for(size_t c = ans.find_first_of(" "); c != string::npos; c = ans.find_first_of(" ")){
      ans.erase(c,1);
    }
    cout << ans << endl;
  }
  return 0;
}
