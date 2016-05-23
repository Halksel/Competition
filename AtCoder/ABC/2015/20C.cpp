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
typedef vector<int> vi ;
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

int H,W,T;
vector<vector<char>> s(12,vector<char>(12,'/'));
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin >> H >> W >> T;
  rep(i,H){
    rep(j,W){
      cin >> s[i+1][j+1];
    }
  }
  queue<pii> q,xy;
  queue<vector<vector<int>>> e;
  q.push(make_pair(0,0));
  xy.push(make_pair(1,1));
  e.push(vector<vi>(12,vi(12,1000)));
  pii mb(11,11),mw(11,11);
  int mindis =100;
  queue<int> dis;
  dis.push(0);
  while(!q.empty()){
    pii pos = xy.front();xy.pop();
    pii bw = q.front();q.pop();
    vector<vi> v = e.front();e.pop();
    v[pos.fi][pos.se] = dis.front();
    dis.pop();
    if(v[pos.fi][pos.se] <mindis){
      rep(i,4){
        int x = pos.fi + dx[i],y = pos.se+dy[i];
        if(value(x,y,H+1,W+1)){
          //         cout << x << "." << y << endl;
          if(v[x][y] > v[pos.fi][pos.se] ){
            if(s[x][y] == '#'){
              q.push(make_pair(bw.fi+1,bw.se));
              xy.push(make_pair(x,y));
              dis.push(1+v[pos.fi][pos.se]);
              e.push(v);
            }
            if(s[x][y] == '.'){
              q.push(make_pair(bw.fi,bw.se+1));
              xy.push(make_pair(x,y));
              dis.push(1+v[pos.fi][pos.se]);
              e.push(v);
            }
            if(s[x][y] == 'G'){
              mb = make_pair(bw.fi,bw.se+1);
              mw = make_pair(bw.fi,bw.se+1);
              mindis = min(mindis,1+v[pos.fi][pos.se]);
              break;
            }
          }
        }
      }
    }
  }
  ll ub = T-1,lb = 0;
  rep(_,100){
    ll med = (ub+lb)/2;
    if(lb - ub > 1){
      break;
    }
    ll a = mb.fi * med + mb.se,b = mw.fi*med + mw.se;
    if( a <= T || b <= T){
      lb = med;
    }
    else{
      ub = med;
    }
  }
  cout << ub-1 << endl;
  //   rep(i,H+1){
  //     rep(j,W+1){
  //       cout << s[i][j]<< " ";
  //     }
  //     cout << endl;
  //   }
  return 0;
}
