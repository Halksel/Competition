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
#define vvl(v,w,h,init) vector<vector<ll>> v(w,vector<ll>(h,init));

#define rep(i,n) for(int i = 0; i < (int)(n);++i)
#define REP(i,a,b) for(int i = (a);i < (int)(b);++i)
#define repi(it,array) for(auto it = array.begin(),end = array.end(); it != end;++it)
#define repa(n,array) for(auto &n :(array))

using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using dict = map<string,int>;
using pii = pair<int,int> ;
using pll = pair<ll,ll> ;

const int mod = 1000000007;
constexpr int imax = ((1<<30)-1)*2+1 ;
constexpr int inf = 100000000;
constexpr double PI = acos(-1.0) ;
double eps = 1e-10 ;
const int dy[] = {-1,0,1,0,1,-1,1,-1};
const int dx[] = {0,-1,0,1,1,-1,-1,1};

inline bool value(int x,int y,int w,int h){
  return (x >= 0 && x < w && y >= 0 && y < h);
}

template<typename T>
void Unique(vector<T> &v){
  sort(all(v));
  v.erase(unique(all(v)),v.end());
}
struct data{
  ll id,s;
  bool operator<(const data& d){
    return id < d.id;
  }
  bool operator>(const data& d){
    return s > d.s;
  }
};

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll n,a,b,c,d;
  cin >> n;
  vector<data> v(n);
  rep(i,n){
    v[i].id = i+1;
  }
  rep(i,n * (n-1)/2){
    cin >> a >> b >> c >> d;
    --a,--b;
    if(c > d){
      v[a].s += 3;
    }
    else if(c == d){
      v[a].s++;
      v[b].s++;
    }
    else{
      v[b].s += 3;
    }
  }
  sort(all(v),[](const data& d,const data& d2){return d.s > d2.s;});
  ll k = inf;
  ll cnt = 1;
  rep(i,n){
    if(k != v[i].s){
      k = v[i].s;
      v[i].s = i+1;
      cnt = i+1;
    }
    else if(k == v[i].s){
      v[i].s = cnt;
    }
  }
  sort(all(v));
  rep(i,n){
    cout << v[i].s<<endl;
  }
  return 0;
}
