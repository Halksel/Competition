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
  char c;
  int w,q,a,b,s = 0;
  map<int,pii> m;
  while(cin >> w >> q){
    if(w + q == 0)break;
    vector<int> vi(w+1,0);
    rep(_,q){
      cin >> c;
      if(c == 's'){
//         rep(i,vi.size()){
//           cout << vi[i];
//         }
//         cout << endl;
        cin >> a >> b;
        bool f = false;
        for(auto it = find(all(vi),0); it != vi.end(); ++it,it = find(it,vi.end(),0)){
          if(f) break;
          if(it + b < vi.end()){
            rep(i,b){
              if(*(it+i) != 0) break;
              if( i+1 == b ){
                fill(it,it+b,1);
                f =true;
                s = it - vi.begin();
                break;
              }
            }
          }
        }
        if(f){
          m[a] = make_pair(s,b);
          cout << s << endl;
        }
        else cout << "impossible"<<endl;
      }
      else{
        cin >> a;
        fill(vi.begin() + m[a].first,vi.begin() + m[a].first + m[a].second, 0) ;
//         rep(i,vi.size()){
//           cout << vi[i];
//         }
//         cout << endl;
      }
    }
    cout << "END"<< endl;
  }

  return 0;
}
