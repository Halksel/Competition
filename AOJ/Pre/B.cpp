#include<bits/stdc++.h>

using namespace std;

#define rep(i,n) for(int i = 0; i < (n); ++i)

using ll = long long;

int main(){
  ll t, d, l;
  while (cin >> t >> d >> l) {
    if (t==0 && d==0 && l==0) {
      break;
    }
    vector<ll> a(t);
    vector<ll> p(t+1, 0);
    for (ll i = 0; i < t; i++) {
      cin >> a[i];
      if (a[i] >= l && i != t-1) {
        p[i]++;
        if (i+d<t) {
          p[i+d]--;
        } else {
          p[t-1]--;
        }
      }
    }
    for (ll i = 1; i <= t; i++) {
      p[i] += p[i-1];
    }
    ll ans = 0;
    ll ff, ee;
    ff = ee = -1;
    ll cc = 0;
    for (ll i = 0; i < t; i++) {
      //cout << p[i] << ' ';
      cc = p[i];
      if (cc > 0 && ff == -1) {
        ff = i;
      } else if (cc == 0 && ff != -1) {
        ans += i-ff;
        ff = -1;
      }
    }
    cout << ans << endl;
  }
}