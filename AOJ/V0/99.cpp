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
const int MAX_N = 1048576;

int n;
pii dat[2*MAX_N - 1];

void init(int n_){
  n = 1;
  while(n < n_){
    n *= 2;
  }
  int tmp = n;
  for(int i =0; i < tmp-1;++i){
    dat[i] = make_pair(0,0);
  }
}

void update(int k, int a){
  k += n-1;
  dat[k] = make_pair(a,k);
  while(k>0){
    k = (k-1)/2;
    if(dat[k*2+1].fi > dat[k*2+2].fi){
      dat[k] = dat[k*2+1];
    }
    else if(dat[k*2+1].fi == dat[k*2+2].fi){
      dat[k] = make_pair(dat[k*2+1].fi,min(dat[k*2+1].se,dat[k*2+2].se));
    }
    else{
      dat[k] = dat[k*2+2];
    }
  }
}

int query(int a,int b,int k,int l, int r){
  if(r <= a || b <= l){
    return 0;
  }
  if(a <= l && r <= b){
    return dat[k].fi;
  }
  else{
    int vl = query(a,b,k*2+1,l,(l+r)/2);
    int vr = query(a,b,k*2+2,(l+r)/2,r);
    return max(vl,vr);
  }
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int N,q,a,v;
  cin >> N >> q;
  init(N);
  rep(i,q){
    cin >> a >> v;
    --a;
    update(a,v+dat[a+n-1].fi);
    //ans
    cout << dat[0].se-n+2 << " " << dat[0].fi << endl;
  }
  return 0;
}
