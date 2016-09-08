#include <bits/stdc++.h>
using namespace std ;
#define rep(i,n) for(int i = 0; i < (int)(n);++i)
using ll = long long;
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll n,m;
  cin >> n >> m;
  vector<ll> v(n);
  rep(i,n)
    cin >> v[i];
  rep(x,m){
    int k = x+1;
    rep(i,n-1){
      if(v[i] % k > v[i+1] % k)
        swap(v[i],v[i+1]);
    }
  }
  rep(i,n) cout << v[i] << endl;
  return 0;
}
