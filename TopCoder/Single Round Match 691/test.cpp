#include <cstdio>
#include <cmath>
#include <cstring>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <sstream>
#include <typeinfo>
#include <fstream>

using namespace std;


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
using pii = pair<int,int> ;
using pll = pair<ll,ll> ;
class Plusonegame {
    public:
    string getorder(string s) {
      ll cnt = 0;
      sort(all(s));
      string s1,s2;
      rep(i,s.size()){
        if(s[i] == '+'){
          s2 += s[i];
        }
        else{
          s1 += s[i];
        }
      }
      string ans;
      ll c = 0,d = 0;
      while(c < s2.size() || d<s1.size()){
        while(s1[d] - '0' != cnt && c < s2.size()){
          ans += s2[c];
          ++cnt;
          ++c;
        }
        while(s1[d] -'0' == cnt || c == s2.size()){
          if(d >= s1.size()) break;
          ans += s1[d];
          ++d;
        }
        debug(c);
        debug(d);
      }
      return ans;
    }
};

// CUT begin
int main(){
  Plusonegame p;
  string s;
  cin >> s;
  cout << p.getorder(s)<<endl;
}
