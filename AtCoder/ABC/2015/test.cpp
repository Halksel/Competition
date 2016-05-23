#include <bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<n;i++)
#define repb(i,a,b) for(int i=a;i>=b;i--)
#define all(a) a.begin(),a.end()
#define o(a) cout<<a<<endl
#define int long long
#define fi first
#define se second
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;

signed main(){
  int n, k;
  cin >> n >> k;
  vector<int> a(n, 0);
  rep(i, 0, n) cin >> a[i];
  int sum = 0;
  rep(i, 0, n) {
    int tmp = min(i + 1, n - i);
    if (tmp < k) {
      sum += a[i] * tmp;
    }
    else {
      sum += a[i] * (k);
    }
  }
  cout << sum << endl;
}
