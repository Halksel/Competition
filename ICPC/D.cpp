#include<bits/stdc++.h>
#include<vector>
#include<string>

using namespace std;

#define rep(i,n) for(int i = 0; i < n;++i)
#define all(v) v.begin(),v.end()

using ll = long long;

int dp[2][1<<25];

int main(){
  int n, m;
  while (cin >> n >> m) {
    if (n == 0 && m == 0) {
      break;
    }
    vector<string> s(n);
    for (int i = 0; i < n; i++) {
      cin >> s[i];
    }
    vector< vector<int> > d(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        d[i][j] = s[i][j]-'0';
      }
    }
    vector<int> pp(m);
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        pp[i] += d[j][i];
      }
      pp[i] %= 2;
    }

    if (n <= 20) {
      long long int a = 1;
      a <<= n;
      int ans = 0;
      for (long long int i = 0; i < a; i++) {
        long long int p = 1;
        vector<int> sum(m, 0);
        int count = 0;
        for (int j = 0; j < n; j++) {
          if ((i & p) != 0) {
            count++;
            for (int k = 0; k < m; k++) {
              sum[k] += d[j][k];
              sum[k] %= 2;
            }
            p <<= 1;
          }

        }
        bool h = true;
        for (int j = 0; j < m; j++) {
          if (sum[j] != pp[j]) {
            h = false;
            break;
          }
        }
        if (h) {
          ans = max(ans, n-count);
        }
      }
      cout << ans << endl;
    } else {
      rep(i,2)fill(dp[i],dp[i]+(1<<25),-1);
      dp[0][0]=0;
      dp[1][0]=0;
      vector<ll> vi;
      rep(i,n){
        ll num=0;
        rep(j,m){
          num*=2;
          num+=d[i][j];
        }
        vi.push_back(num);
      }
      rep(i,n){
        rep(mask,1<<m){
          ll nn=mask^vi[i];
          if(dp[i%2][mask]!=-1)dp[(i+1)%2][nn]=max(dp[i%2][mask]+1,dp[(i+1)%2][nn]);
        }
        rep(j,1<<m){
          //cout<<dp[(i+1)%2][j]<<" ";
        }
        //cout<<endl;
      }
      rep(i,n){

      }
      cout<<max(dp[0][0],dp[1][0])<<endl;
    }
  }
  return 0;
}
