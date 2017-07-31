#include<bits/stdc++.h>

using namespace std;

#define rep(i,n) for(int i = 0;i < n;++i)

int main(){
  int n,o;
  while(cin >> n,n){
    int v[25][25] = {{}};
    int x,y;
    rep(i,n){
      cin >> x >> y;
      v[x][y] = 1;
    }
    int ans = 0;
    cin >> o;
    x = 10, y = 10;
    int d;
    string s;
    rep(i,o){
      cin >> s >> d;
      if(s == "W"){
        rep(j,d){
          --x;
          ans += v[x][y];
          v[x][y] = 0;
        }
      }
      if(s == "E"){
        rep(j,d){
          ++x;
          ans += v[x][y];
          v[x][y] = 0;
        }
      }
      if(s == "S"){
        rep(j,d){
          --y;
          ans += v[x][y];
          v[x][y] = 0;
        }
      }
      if(s == "N"){
        rep(j,d){
          ++y;
          ans += v[x][y];
          v[x][y] = 0;
        }
      }
      /* cout << ans << endl; */
    }
    if(ans == n){
      cout << "Yes" << endl;
    }
    else
      cout << "No" << endl;
  }
  return 0;
}
