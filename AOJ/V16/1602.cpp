#include <bits/stdc++.h>
using namespace std ;

#define all(r) begin(r),end(r)
#define debug(x) cout<<#x<<": "<<x<<endl

#define rep(i,n) for(int i = 0; i < (int)(n);++i)
#define REP(i,a,b) for(int i = (a);i < (int)(b);++i)

using ll = long long;

ll n;
vector<string> v(10000);
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  while(cin >> n && n){
    ll ans = 0;
    rep(i,n){
      cin >> v[i];
    }
    if(n == 1){
      cout << v[0] << endl;
    }
    else{
      stack<char> s;
      s.push(v[0]);
      int suf = 0;
      while(s.size()){
        if(v[suf].back() == '+' || v[suf].back() == '*'){
          s.push(v[suf].back());
          ++suf;
        }
        else{
          bool f = s.top() == '*';
          ll tmp = f;
          ll S = v[suf].size()+1;
          ++suf;
          while(v[suf].size() == S){
            if(f){
              tmp *= v[suf].back() - '0';
            }
            else{
              tmp += v[suf].back() - '0';
            }
            ++suf;
          }
          ans += tmp;
          s.pop();
        }
      }
      cout << ans << endl;
    }
  }
  return 0;
}

