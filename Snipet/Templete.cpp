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
using pii = pair<int,int> ;

constexpr int imax = ((1<<30)-1)*2+1 ;
constexpr int inf = 100000000;
constexpr double PI = acos(-1.0) ;
double eps = 1e-10 ;
const int dy[] = {-1,0,1,0,1,-1,1,-1};
const int dx[] = {0,-1,0,1,1,-1,-1,1};
//dijkstra
struct Edge{
  int to;
  long long cost;
};

struct NODE{
  int pos;
  long long cost;
};
bool operator < (const NODE &a,const NODE &b){
  return a.cost > b.cost;
}
vector<Edge> g[100000],rg[100000];

int N;
const ll INF = 1e15;
vector<ll> dijkstra(vector<Edge> g[100000], int s){
  priority_queue<NODE> Q;
  Q.push({s,0});
  vector<ll> res(N,INF);
  while(Q.size()){
    NODE q= Q.top();Q.pop();
    if(res[q.pos] == INF){
      res[q.pos] = q.cost;
    }
    else{
      continue;
    }
    for(auto n : g[q.pos]){
      Q.push({n.to,q.cost+n.cost});
    }
  }
  return res;
}
//Prim
const int MAX_V = 1000000;
//infで初期化
vector<vector<ll>> cost;
ll mincost[MAX_V];
bool used[MAX_V];
ll V;

ll Prim(){
  ll res = 0;
  for(ll i = 0; i < V; ++i){
    mincost[i] = inf;
    used[i] = false;
  }
  priority_queue<NODE> q;
  q.push({0,0});
  while(q.size()){
    auto v = q.top();q.pop();
    if(mincost[v.pos] == inf){
      mincost[v.pos] = v.cost;
      res += v.cost;
      for(auto n : g[v.pos]){
        q.push({n.to,n.cost});
      }
    }
  }
  rep(i,V){
    g[i].clear();
  }
  return res;
}

//幾何
double EPS = 1e-10;
double add(double a, double b){
  if(abs(a+b) < EPS* (abs(a) + abs(b))) return 0;
  return a+b;
}

struct P{
  double x,y;
  P(){}
  P(double _x,double _y):x(_x),y(_y){}
  P operator + (P p){
    return P(add(x,p.x) ,add(y,p.y));
  }
  P operator - (P p){
    return P(add(x,-p.x) ,add(y,-p.y));
  }
  P operator * (double d){
    return P(x * d,y * d);
  }
  bool operator==(const P p){
    return (x == p.x && y == p.y);
  }
  friend ostream& operator<<(ostream& os,const P& p){
    os << "("<<p.x <<","<<p.y<<")";
    return os;
  }
  double norm(){
    return sqrt(x*x + y*y);
  }
  double dot(P p){
    return add(x * p.x,y*p.y);
  }
  double det(P p){
    return add(x*p.y,-y*p.x);
  }
  double dist2(P p){
    return ((*this-p).x * (*this-p).x) + ((*this-p).y * (*this-p).y);
  }
  P GetCenter(P &p){
    return P((*this+p).x/2,(*this+p).y/2);
  }
  double GetSlope(P &p){
    P tmp = *this - p;
    return tmp.y/tmp.x;
  }
};
//線分上に点が存在するか
bool on_seg(P p1,P p2,P q){
  return (p1-q).det(p2-q) == 0 && (p1-q).dot(p2-q) <= 0;
}
//交点導出
P intersection(P p1, P p2, P q1,P q2){
  return p1 + (p2-p1) * ((q2 - q1).det(q1-p1) / (q2 - q1).det(p2-p1)) ;
}
//四捨五入
double ceilN(double a, int N){
  double ans,sign;
  sign = (a < 0)? -1 : 1;
  ans = a * pow(10.0,N);
  ans = (double)(int)(ans+ 0.5 * sign);
  return ans * pow(10.0,-N);
}
//Eratosthenes
const int PrimeMax = 100001;
int is_prime[PrimeMax];
void Eratosthenes(int N){
  for(int i = 0; i < N; i++){
    is_prime[i] = 1;
  }
  is_prime[0] = 0;
  is_prime[1] = 0;
  for(int i = 2; i*i < N ; i++){
    if(is_prime[i]){
      for(int j = 0; i * (j + 2) < N; j++){
        is_prime[i *(j + 2)] = 0;
      }
    }
  }
}

//RMQ
const int MAX_N = 1 << 17;
int n, dat[2*MAX_N - 1];

void init(int n_){
  n = 1;
  while(n < n_){
    n *= 2;
  }

  for(int i =0; i < 2*n-1;++i){
    dat[i] = INT_MAX;
  }
}

void update(int k, int a){
  k += n-1;
  dat[k] = a;
  while(k>0){
    k = (k-1)/2;
    dat[k] = min(dat[k*2+1],dat[k*2+2]);
  }
}

int query(int a,int b,int k,int l, int r){
  if(r <= a || b <= l){
    return INT_MAX;
  }
  if(a <= l && r <= b){
    return dat[k];
  }
  else{
    int vl = query(a,b,k*2+1,l,(l+r)/2);
    int vr = query(a,b,k*2+2,(l+r)/2,r);
  }
  return min(vl,vr);
}
//GCD & LCM
int gcd(int a,int b){
  if(a < b) swap(a,b);
  if(b == 0) return a;
  return gcd(b,a%b);
}

int lcm(int a,int b){
  return a*b/ gcd(a,b);
}
//Split
vector<string> Split(char c,string s){
  vector<string> res(0);
  string str = "";
  rep(i,s.size()){
    if(s[i] == c){
      res.push_back(str);
      str.clear();
    }
    else{
      str += s[i];
    }
  }
  res.push_back(str);
  return res;
}

// 数値を２進数文字列に変換
std::string to_binString(unsigned int val)
{
  if( !val )
    return std::string("0");
  std::string str;
  while( val != 0 ) {
    if( (val & 1) == 0 )
      str.insert(str.begin(), '0');
    else
      str.insert(str.begin(), '1');
    val >>= 1;
  }
  return str;
}

int numofbits5(long bits)
{
  bits = (bits & 0x55555555) + (bits >> 1 & 0x55555555);
  bits = (bits & 0x33333333) + (bits >> 2 & 0x33333333);
  bits = (bits & 0x0f0f0f0f) + (bits >> 4 & 0x0f0f0f0f);
  bits = (bits & 0x00ff00ff) + (bits >> 8 & 0x00ff00ff);
  return (bits & 0x0000ffff) + (bits >>16 & 0x0000ffff);
}
enum{
  t = 0,
  f ,
  r ,
  b ,
  l ,
  d,
};

array<int,6> dice = {1,3,5,4,2,6};

void Spin(array<int,6> &D,int dir){
  if(dir == l){//
    swap(D[t],D[r]);
    swap(D[r],D[d]);
    swap(D[d],D[l]);
  }
  else if(dir == r){
    swap(D[t],D[l]);
    swap(D[l],D[d]);
    swap(D[d],D[r]);
  }
  else if(dir == f){
    swap(D[t],D[b]);
    swap(D[b],D[d]);
    swap(D[d],D[f]);
  }
  else if(dir == b){
    swap(D[t],D[f]);
    swap(D[f],D[d]);
    swap(D[d],D[b]);
  }
  else if(dir == d){//leftspin
    swap(D[f],D[r]);
    swap(D[r],D[b]);
    swap(D[b],D[l]);
  }
  else if(dir == t){
    swap(D[f],D[l]);
    swap(D[l],D[b]);
    swap(D[b],D[r]);
  }
}

void ViewDice(array<int,6> D){
  rep(i,6){
    cout << D[i]<< " ";
  }
  cout << endl;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  return 0;
}
