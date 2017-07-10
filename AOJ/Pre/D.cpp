#include<bits/stdc++.h>

using namespace std;

#define rep(i,n) for(int i = 0; i < (n); ++i)
#define all(v) v.begin(),v.end()
#define debug(x) cout<<#x<<": "<<x<<endl

using ll = long long;
const ll mod = 1e9 + 7;
ll N,M;
vector<ll> s;

bool check(ll x){
  /* debug(x); */
  ll m = 1,l = 1;
  while(s[N-1] >= l + x){
    /* debug(l); */
    auto p = equal_range(all(s),l);
    ll L = 1LL;
    for(auto it = max(s.begin(),p.first-1); it != max(s.end(),p.second + 1);++it){
      if(*it < l + x )
        L = max(L,x - abs(l - *it));
    }
    l += L;
    ++m;
    if(m >= M) break;
  }
  return m >= M;
}

int main(){
  while(cin >> N >>M, N+M){
    s.resize(N);
    rep(i,N){
      cin >> s[i];
    }
    bool f = check(1);
    /* debug(1); */
    if(!f){
      cout << -1 << endl;
    }
    else{
      ll lb = 0,ub = s[N-1] + 10;
      rep(i,100){
        ll m = (lb + ub)/2;
        if(check(m)){
          lb = m;
        }
        else{
          ub = m;
        }
      }
      cout << lb << endl;
    }
  }
}
