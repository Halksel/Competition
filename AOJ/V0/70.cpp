#include <bits/stdc++.h>
using namespace std ;

#define debug(x) cout<<#x<<": "<<x<<endl

#define rep(i,n) for(int i = 0; i < (int)(n);++i)
#define REP(i,a,b) for(int i = (a);i < (int)(b);++i)
using ll = long long;
int n,s,ans;
int dp[1 << 11][10000];
void dfs(int state,int k,int sum){
  if(sum > s) return;
  if(dp[state][sum] != 0){
    dp[state][sum]++;
    return ;
  }
  dp[state][sum]++;
  if(k == n && sum == s){
    ++ans;
    return ;
  }
  if(k == n) return ;
  ++k;
  rep(i,10){
    if(!(state & (1 << i))){
      dfs(state|(1 << i),k,sum + i * k);
    }
  }
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  while(cin >> n >> s){
    ans = 0;
    rep(i,1 << 11){
      rep(j,10000){
        dp[i][j] = 0;
      }
    }
    dfs(0,0,0);
    cout << ans << endl;
  }
  return 0;
}
