#include <bits/stdc++.h>

using namespace std;

using ll = long long;
#define rep(i,n) for(int i = 0; i < n ;++i)
#define REP(i,a,b) for(int i = a; i < b ;++i)
#define all(v) v.begin(),v.end()

ll d,n,m;

struct Cell{
  Cell *lc,*rc;
  double lh,rh,w,v,lx,rx,a;
  Cell(){};
};

int main(){
  cin >> d;
  rep(_,d){
    cin >> n;
    vector<Cell> c(n+1);
    c[0].lc = nullptr;
    c[0].lx = 0;
    c[0].lh = 50;
    c[n].rc = nullptr;
    c[n].rh = 50;
    c[n].rx = 100;
    double b,h;
    REP(i,1,n){
      cin >> b >> h;
      c[i-1].rx = b;
      c[i-1].rh = h;
      c[i].lx = b;
      c[i].lh = h;
    }
    cin >> m;
    double f,a;
    rep(i,m){
      cin >> f >> a;
      rep(j,n)
    }
  }
  return 0;
}
