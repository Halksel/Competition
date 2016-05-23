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

inline bool value(int x,int y,int w,int h){
  return (x >= 0 && x < w && y >= 0 && y < h);
}

struct city{
  ll zero;
  ll one;
};

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  string s;
  vector<city> C(6);
  C[0].zero = 1;
  C[0].one = 2;
  C[1].one = 3;
  C[1].zero = -1;
  C[2].zero = 1;
  C[2].one = -1;
  C[3].zero = 4;
  C[3].one = 5;
  C[4].zero = 5;
  C[4].one = 2;
  C[5].zero = 2;
  C[5].one = 1;
  while(cin >> s && s != "#"){
    ll pos = 0;
    rep(i,s.size()){
      if(s[i] == '0'){
        pos = C[pos].zero;
      }
      else{
        pos = C[pos].one;
      }
      if(pos == -1 || i == s.size()-1 && pos != 5){
        cout << "No"<<endl;
        break;
      }
      else if(i == s.size()-1 && pos == 5){
        cout << "Yes" << endl;
      }
    }
  }
  return 0;
}
