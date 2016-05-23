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

const int mod = 1000000007;
constexpr int imax = ((1<<30)-1)*2+1 ;
constexpr int inf = 100000000;
constexpr double PI = acos(-1.0) ;
double eps = 1e-10 ;
const int dy[] = {-1,0,1,0};
const int dx[] = {0,-1,0,1};

inline bool value(int x,int y,int w,int h){
  return (x >= 0 && x < w && y >= 0 && y < h);
}

template<typename T>
void Unique(vector<T> &v){
  sort(all(v));
  v.erase(unique(all(v)),v.end());
}
struct data{
  ll id,saraly;
  vector<data*> ds;
  void SetSaraly(){
    if(ds.size() != 0){
      sort(all(ds));
      rep(i,ds.size()){
        ds[i]->SetSaraly();
      }
      saraly = ds[0]->saraly + ds[ds.size()-1]->saraly +1;
    }
    else{
      saraly = 1;
    }
  }
  void children(){
    cout << id << "'s chilren" <<endl;
    rep(i,ds.size()){
      cout << ds[i]->id<< " ";
    }
    cout << endl;
  }
  bool operator<(const data& d){
    return saraly < d.saraly ;
  }
};

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll N,n;
  cin >> N;
  vector<data> v(N);
  v[0] = data{1,1,vector<data*> (0)};
  REP(i,1,N){
    cin >> n;
    --n;
    v[i].id = i+1;
    v[i].saraly = 1;
    v[i].ds.clear();
    v[n].ds.push_back(&v[i]);
  }
  v[0].SetSaraly();
//   rep(k,100){
//     REP(i,0,N){
//       v[i].SetSaraly();
//       rep(j,v[i].ds.size()){
// //         cout << v[i].ds[j]->id<<endl;
//         v[i].ds[j]->SetSaraly();
//       }
//       v[i].SetSaraly();
//     }
//   }
//   rep(i,N){
//     v[i].children();
//   }
  cout << v[0].saraly<<endl;
  return 0;
}
