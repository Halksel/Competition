#include<bits/stdc++.h>

using namespace std;

#define rep(i,n) for(int i = 0; i < (n); ++i)

using ll = long long;

ll n,m;
ll MAX[10010];
ll MIN[10010];

ll INF=1000000;

int main(){
  while(cin>>n>>m&&n+m){
    fill(MAX,MAX+10010,0);
    fill(MIN,MIN+10010,0);
  rep(i,m){
    ll s,k;
    cin>>s>>k;
    rep(j,k){
      ll num;
      cin>>num;num--;
      MAX[num]+=s;
      if(k==1)MIN[num]+=s;
    }
  }
  ll ans[10010];

  rep(i,n){
    ans[i]=0;
    rep(j,n){
      if(i!=j)ans[i]=max(ans[i],MAX[i]-MIN[j]+1);
    }
  }
  ll out=0;
  rep(i,n)out=max(out,ans[i]);
  cout<<out<<endl;
  }
}