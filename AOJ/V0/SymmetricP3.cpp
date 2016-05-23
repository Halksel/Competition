#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <utility>
#include <stack>
#include <queue>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

#define rep(i,n) for(int i=0; i<(n); i++)
#define repc(i,s,e) for(int i=(s); i<(e); i++)
#define pb(n) push_back((n))
#define mp(n,m) make_pair((n),(m))
#define all(r) r.begin(),r.end()
#define fi first
#define se second

//typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vii;
//typedef vector<ll> vl;
//typedef vector<vl> vll;
typedef pair<int,int> pii;
//typedef pair<ll,ll> pll;




int main(){
  double x1,x2,xq,xr,y1,y2,yq,yr;
  char ch;
  while(cin>>x1>>ch>>y1>>ch>>x2>>ch>>y2>>ch>>xq>>ch>>yq){
    x2-=x1;
    y2-=y1;
    xq-=x1;
    yq-=y1;
    double a=x2,b=y2,c=xq,d=yq;
    xq=(a*c+b*d)/(a*a+b*b);
    yq=(a*d-b*c)/(a*a+b*b);
    xr=xq;
    cout << "xr,yr = "<<xr << "," << yr << endl;
    yr=yq*(-1.0);
    c=xr;
    d=yr;
    xr=a*c-b*d;
    yr=a*d+b*c;
    xr+=x1;
    yr+=y1;
    printf("%.15lf %.15lf\n",xr,yr);
  }
}
