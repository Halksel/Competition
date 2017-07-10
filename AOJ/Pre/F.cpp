#include<bits/stdc++.h>

using namespace std;

#define rep(i,n) for(int i = 0; i < (n); ++i)
#define all(v) v.begin(),v.end()
#define debug(x) cout<<#x<<": "<<x<<endl

//const ll mod = 1e9 + 7;

using ll = long long;

bool isused[110];
struct edge{
  int x,y,z,v;
};
vector<edge> ve;

bool is(edge e1,edge e2){
  return e1.v>e2.v;
}

int n,x,y,z;

int main(){
  while(cin>>n&&n){
    fill(isused,isused+110,0);
    ve.clear();
    ll sum=0;
    rep(i,n){
      int x,y,z;
      cin>>x>>y>>z;
      if(x>y)swap(x,y);
      if(y>z)swap(y,z);
      ve.push_back({x,y,z,x*y*z});
      sum+=x*y*z;
    }
    sort(ve.begin(),ve.end(),is);
    rep(i,n){
    //cout<<ve[i].x<<ve[i].y<<ve[i].z<<ve[i].v<<endl;      
      for(int j=i+1;j<n;j++){
        edge e1=ve[i],e2=ve[j];
        if(!isused[j]){
          if(e1.x>e2.x&&e1.y>e2.y&&e1.z>e2.z){
     //       cout<<i<<" "<<j<<endl;
            isused[j]=1;
            sum-=e2.v;
            break;
          }
        }
      }
    }
    cout<<sum<<endl;
  }
}
