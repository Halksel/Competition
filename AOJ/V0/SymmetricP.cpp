#include<iostream>
#include<iomanip>
#include<sstream>
#include<string>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<map>
#include<vector>
#include<queue>
#include<set>
#include<numeric>
#include<complex>

using namespace std ;

#define pb(n) push_back(n)
#define fi first
#define se second
#define np string::npos
#define X real()
#define Y imag()
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

constexpr int imax = ((1<<30)-1)*2+1 ;
constexpr int inf = 100000000;
const double PI = acos(-1.0) ;
double eps = 1e-10 ;

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
T ston(string str, T n){
  istringstream sin(str) ;
  T num ;
  sin >> num ;
  return num ;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  char c;
  double a,b,s,d,e,f,g,h,x,y,slp1,slp2;
  comd slp;
  comd p1,p2,q,r;
  // y = slp * x + g, y = -(slp.Y/slp.X) * x + h;
  while(cin >> a >> c >> b >> c >> s >> c >> d >> c >> e >> c >> f){
    p1 = comd(a,b),p2 = comd(s,d),q = comd(e,f);
    slp = comd( -(p2.Y-p1.Y),(p2.X-p1.X));
    if(slp.Y == 0){
      x = p1.X;
      y = q.Y ;
      x += x - q.X;
    }
    else if(slp.X == 0){
      x = q.X;
      y = p1.Y;
      y += y - q.Y;
    }
    else{
      slp1 = (slp.X/slp.Y) ;
      slp2 = -(slp.Y/slp.X) ;
      g = -slp1 * q.X + q.Y;
      h = -slp2 * p1.X + p1.Y;

      x = (g-h)/( slp2-slp1);
      y = slp1 * x + g ;
      x += x - q.X;
      y += y - q.Y;
    }
    fcout(6) << x << " " << y << endl;
  }
  return 0;
}
