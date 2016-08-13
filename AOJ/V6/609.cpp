#include <bits/stdc++.h>
using namespace std ;

#define vary(type,name,size,init) vector< type> name(size,init)
#define rep(i,n) for(int i = 0; i < (int)(n);++i)
using ll = long long;

int main(){
  ll n,m,a;
  cin >> n >> m;
  vary(ll,t,m,0);
  vary(ll,s,n,0);
  rep(i,m) cin >> t[i];
  rep(i,m){
    rep(j,n){
      cin >> a;
      if(a == t[i])
        s[j]++;
      else
        s[t[i]-1]++;
    }
  }
  rep(i,n) cout << s[i] << endl;
  return 0;
}

