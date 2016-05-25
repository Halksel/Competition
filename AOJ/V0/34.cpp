#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<map>
#include<numeric>

using namespace std ;

#define pb(n) push_back(n)
#define fi first
#define se second
#define all(r) (r).begin(),(r).end()
#define gsort(st,en) sort((st),(en),greater<int>())
#define vmax(ary) *max_element(all(ary))
#define debug(x) cout<<#x<<": "<<x<<endl

#define rep(i,n) for(int i = 0; i < (n);++i)
#define repc(i,a,b) for(int i = (a);i <(b);++i)
#define repa(n,array) for(auto n :(array))

typedef long long ll ;
typedef vector<int> vi ;
typedef vector<ll> vl ;

constexpr int IMAX = ((1<<30)-1)*2+1 ;
constexpr int INF = 100000000;
double EPS = 1e-10 ;

template <typename T>
T out(vector < T > v)
{
  for(size_t i = 0; i < v.size(); i++)
  {
    debug(v[i]);
  }
  return 0 ;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  double v1,v2,l1 = 0,l2,ans;
  char c;
  vi v(10,0) ;
  while(cin >> v[0] >> c){
    l1 = 0;
    repc(i,1,10){
      cin >> v[i] >> c;
    }
    cin >> v1 >> c>>v2;
    l2 = accumulate(all(v),0) * 1000 ;
    v1 = v1/3600 * 1000;
    v2 = v2/3600 * 1000;
    while(l1<=l2){
      l1 += v1 ;
      l2 -= v2 ;
    }
    //debug(l1) ;
    //debug(l2) ;
    ans = 0 ;
    rep(i,10){
      ans += v[i] * 1000;
      //debug(ans) ;
      if((int)l1 == (int)ans){
        //debug(ans) ;
        ans = i + 1;
        break ;
      }
      else if(l1 < ans){
        //debug(ans) ;
        ans = i + 1 ;
        break;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
