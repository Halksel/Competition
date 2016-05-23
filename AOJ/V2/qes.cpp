#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
#include <functional>
#include <numeric>
#define fi first
#define se second
using namespace std;
bool value(int y,int x,int R,int C){return 0<=y&&y<R&&0<=x&&x<C;}
typedef pair<int,int> pii;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long > vll;
typedef vector< vi > vvi;
double pie=acos(-1);
int INF=10000009;
int dx[4] = { 0,-1,0,1 };
int dy[4] = { -1,0,1,0 };
int c[20][20];
long long int dp[20][20];
int main() {
  int X,Y;
  while(true){
    long long int ans=0;
    cin>>X>>Y;
    if(X+Y==0) break;
    for(int i=1;i<=Y;i++){
      for(int j=1;j<=X;j++){
        cin>>c[i][j];
      }
    }
    for(int i=1;i<=X;i++){
      if(c[1][i]==1){
        dp[1][i]=0;
      }
      if(c[1][i]==0){
        dp[1][i]=1;
      }
      if(c[1][i]==2){
        dp[1][i]=1;
        dp[3][i]=1;
      }
    }
    for(int i=2;i<=Y;i++){
      for(int j=1;j<=X;j++){
        if(c[i][j]==1) dp[i][j]=0;
        else if(c[i][j]==0){
          for(int k=0;k<3;k++){
            if(c[i-1][j-1+k]!=2){
              dp[i][j]+=dp[i-1][j-1+k];
            }
          }
        }
        else{
          if(c[i-1][j]!=2){
            dp[i][j]+=dp[i-1][j];
          }
          dp[i+2][j]+=dp[i][j];
        }
      }
    }
    for(int i=Y+1;i<=Y+2;i++){
      for(int j=1;j<=X;j++){
        ans+=dp[i][j];
      }
    }
    for(int i=1;i<=Y+2;i++){
      for(int j=1;j<=X;j++){
        dp[i][j]=0;
      }
    }
    cout<<ans<<endl;
  }
}
