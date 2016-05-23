#include <bits/stdc++.h>
using namespace std ;

#define pb(n) push_back(n)
#define fi first
#define se second
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
const int dy[] = {-1,0,1,0};
const int dx[] = {0,-1,0,1};

struct People{
  ll id;
  vector<ll> former;
  bool operator<(const People &p){
    for(auto &&n : former){
      if(p.id == n){
        return true;
      }
    }
    return false;
  }
};

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n,m;
  int x,y;
  cin >> m >> n;
  vector<People> di(m);
  REP(i,0,m){
    di[i].id = i+1;
    di[i].former.pb(2);
  }
  rep(i,n){
    cin >> x >> y;
    --x;
    di[x].former.pb(y);
  }
  REP(i,0,m){
    rep(k,di[i].former.size()){
      REP(j,i+1,m){
        if(di[j].id == di[i].former[k]){
          swap(di[i],di[j]);
          j = 0;
          i = 0;
        }
      }
    }
  }
  reverse(di.begin(),di.end());
  REP(i,0,m){
    cout << di[i].id<<endl;
  }
  return 0;
}
