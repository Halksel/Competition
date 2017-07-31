#include<bits/stdc++.h>
using namespace std;
 
#define int long long
 
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;
template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}
 
signed main(){
    int r,n;
    while(cin>>r>>n,r||n){
        int h[40]={0};
        while(n--){
            int xl,xr,hh;
            cin>>xl>>xr>>hh;
            xl+=20;xr+=20;
            for(int i=xl;i<xr;i++)chmax(h[i],hh);
        }
 
        double ans=1001001001;
        for(int i=0;i<40;i++){
            int x=abs(i-20)+(i-20>=0?0:-1);
            if(x>=r)continue;
            double tmp=r-sqrt(1.0*(r*r-x*x));
            chmin(ans,h[i]+tmp);
        }
        printf("%.20f\n",ans);
    }
    return 0;
}
