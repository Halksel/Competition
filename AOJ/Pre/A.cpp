#include<bits/stdc++.h>

using namespace std;

#define rep(i,n) for(int i = 0; i < (n); ++i)

using ll = long long;

int main(){
  ll n,m;
  while(cin >> n >> m,n+m){
    vector<ll> v(m+1);
    ll u,d;
    rep(i,n){
      cin >> d >> u;
      v[d] = max(v[d],u);
    }
    ll s = 0;
    rep(i,m){
      s += v[i+1];
    }
    cout << s << endl;
  }
}
