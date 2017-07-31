#include<bits/stdc++.h>

using namespace std;

#define rep(i,n) for(int i = 0; i < n;++i)
#define all(v) v.begin(),v.end()

using ll = long long;

int main(){
  int d,w;
  int e[100][100];
  while(cin>>d>>w&&d+w){
    rep(i,d){
      rep(j,w){
        cin>>e[i][j];
      }
    }
    int ans=0;
    rep(py,d){
      rep(px,w){
        for(int qy=py+2;qy<d;qy++){
          for(int qx=px+2;qx<w;qx++){
            int MIN=100;
            for(int i=py;i<=qy;i++){
              for(int j=px;j<=qx;j++){
                if(i==py||i==qy||j==px||j==qx){
                  MIN=min(MIN,e[i][j]);
                }
              }
            }
            int k=0;
            bool f=1;
            for(int i=py;i<=qy;i++){
              for(int j=px;j<=qx;j++){
                if(i!=py&&i!=qy&&j!=px&&j!=qx){
                  //cout<<i<<" "<<j<<endl;
                  if(e[i][j]>=MIN)f=0;
                  else{
                    k+=(MIN-e[i][j]);
                  }
                }
              }
            }
            //cout<<endl;
            if(f){
              ans=max(ans,k);
            }
          }
        }
      }
    }
    cout<<ans<<endl;
  }  
  return 0;
}
