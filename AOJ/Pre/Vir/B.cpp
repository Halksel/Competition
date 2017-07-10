#include <bits/stdc++.h>

using namespace std;

using ll = long long;
#define rep(i,n) for(int i = 0; i < n ;++i)
#define all(v) v.begin(),v.end()

int main() {
  int n;
  while(cin >> n) {
    if (n == 0) {
      break;
    }
  vector<string> w(n);
  vector<int> d(n);
  for (int i =0; i < n; i++) {
    cin >> w[i];
    d[i] = w[i].size();
  }
  for (int i = 0; i < n; i++) {
    bool h = true;
    int st[5] = {0};
    int lm[5] = {5, 7, 5, 7, 7};
    int a = 0;
    for (int j = i; j < n; j++) {
      for (int k = a; k < 5; k++) {
        if (st[k] < lm[k]) {
          st[k] += d[j];
          break;
        } else if (st[k] > lm[k]) {
          h = false;
          break;
        }
        a++;
      }
      if (!h) {
        break;
      } else if (a == 5) {
        break;
      }
    }
    if (h) {
      cout << i+1 << endl;
      break;
    }
  }
  }
  return 0;
}