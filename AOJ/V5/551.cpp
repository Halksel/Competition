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
using pll = pair<ll,ll> ;

const int mod = 1000000007;
constexpr int imax = ((1<<30)-1)*2+1 ;
constexpr int inf = 100000000;
constexpr double PI = acos(-1.0) ;
double eps = 1e-10 ;
const int dy[] = {-1,0,1,0};
const int dx[] = {0,-1,0,1};

ll L;
struct icicle{
  ll len,id,time;
  icicle *l,*r;
  int Grow(){
    if(len == 0) return false;
    if( ( l == nullptr || l->len < len) && ( r == nullptr || r->len < len)){
      time += max(l->time,r->time) + L - len;
      len = L;
      ll a = l->Grow();
      return true + a;
    }
    return false;
  }
  void Cut(){
    if(len == L){
      len = 0;
    }
  }
};

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll n;
  cin >> n >> L;
  vector<icicle> vi(n+2);
  vi[0] = icicle{-1,0,0,nullptr,&vi[1]};
  vi[n+1] = icicle{-1,n+1,0,&vi[n],nullptr};
  REP(i,1,n+1){
    cin >> vi[i].len;
    vi[i].id = i;
    vi[i].l = &vi[i-1];
    vi[i].r = &vi[i+1];
    vi[i].time = 0;
  }
  ll cnt = n,ans = 0;
  while(cnt){
    REP(i,0,n+2){
      cnt -= vi[i].Grow();
    }
    REP(i,0,n+2){
      vi[i].Cut();
    }
  }
  REP(i,0,n+2){
    ans = max(ans,vi[i].time);
  }
  cout << ans <<endl;
  return 0;
}

//       cout << i << "'s r =" << ((vi[i].r != nullptr)?vi[i].r->id:ice.id) << "and" << ((vi[i].l != nullptr) ?vi[i].l->id:ice.id) <<endl;
