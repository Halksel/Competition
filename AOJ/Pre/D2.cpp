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
  if(s[0] >= 1 + x) return false;
  ll m = 1,l = 1,i = 0;
  while(s[N-1] >= l + x){
    ++m;
    //ll L = 1LL;
    ll diff = abs(s[i]-l);
    while(i < N-1 && s[i+1] < l+x && abs(s[i+1]-l) <= diff) {
      ++i;
      diff =abs(s[i]-l);
    }
    l += max(1LL, x-diff);
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
    bool f = check(s[0]);
    /* debug(1); */
    if(!f){
      cout << -1 << endl;
    }
    else{
      ll lb = s[0],ub = s[N-1] + 10;
      rep(i,110){
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
