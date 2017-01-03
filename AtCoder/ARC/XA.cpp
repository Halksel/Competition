#include <bits/stdc++.h>
using namespace std ;

#define pb(n) push_back(n)
#define fi first
#define se second
#define all(r) begin(r),end(r)
#define vmax(ary) *max_element(all(ary))
#define vmin(ary) *min_element(all(ary))
#define debug(x) cout<<#x<<": "<<x<<endl
#define fcout(n) cout<<fixed<<setprecision((n))
#define scout(n) cout<<setw(n)
#define vary(type,name,size,init) vector< type> name(size,init)
#define vvl(v,w,h,init) vector<vector<ll>> v(w,vector<ll>(h,init))
#define mp(a,b) make_pair(a,b)

#define rep(i,n) for(int i = 0; i < (int)(n);++i)
#define REP(i,a,b) for(int i = (a);i < (int)(b);++i)
#define repi(it,array) for(auto it = array.begin(),end = array.end(); it != end;++it)
#define repa(n,array) for(auto &n :(array))

using ll = long long;
using pii = pair<int,int> ;
using pll = pair<ll,ll> ;

template<typename T>
void O(T t){
  cout << t << endl;
}
int n;

bool check(vector<ll> &v){
  bool res = false;
  rep(i,n){

  }
  return false;
}

int main(){
  scanf("%d", &n);
  ll ans = 0;
  int t,sum = 0;
  bitset<50> b(n);
  rep(i,50){
    if(b[i]){
      printf("? %d %d\n",sum, sum + (1 << i));
      sum += (1 << i);
      fflush(stdout);
      scanf("%d",&t);
      ans += t;
    }
  }
  cout << "! " <<  ans << endl;
  return 0;
}

