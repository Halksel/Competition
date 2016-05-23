#include <iostream>
#include <string>
#include <map>
#include <sstream>
#include <algorithm>
#include <cstdio>

using namespace std;

#define REP(i, s, e) for(int i = (int)(s); i < (int)(e); i++)
#define rep(i, n) REP(i,0, n)

#define all(r) (r).begin(), (r).end()
#define rall(r) (r).rbegin(), (r).rend()
int d[251][251][251];

int dice[6];
int dx[6] = {10000,10000,1,0,0,-1};
int dy[6] = {10000,10000,0,-1,1,0};
int df[6] = {1,6,3,2,5,4};
enum{
  top = 0,
  btm,
  frt,
  lft,
  rgt,
  bck,
};

void spinfront(){
  int tmp = dice[top];
  dice[top] = dice[bck];
  dice[bck] = dice[btm];
  dice[btm] = dice[frt];
  dice[frt] = tmp;
}
void spinleft(){
  int tmp = dice[top];
  dice[top] = dice[lft];
  dice[lft] = dice[btm];
  dice[btm] = dice[rgt];
  dice[rgt] = tmp;
}

void spinspin(){
  int tmp = dice[frt];
  dice[frt] = dice[lft];
  dice[lft] = dice[bck];
  dice[bck] = dice[rgt];
  dice[rgt] = tmp;

}

int main(){
  int n,z = 0,dz,a,b;
  while(cin >> n){
    if(n == 0){
      break;
    }
    dz = 0;
    z = 0;
    for(int i = 0; i <250; ++i) {
      for(int j = 0; j <250; ++j) {
        for(int k = 0;k <250; ++k) {
          d[i][j][k] = -1;
        }
      }
    }
    //while(n--){
    rep(_, n){
      //cin >> a >> b;
      scanf("%d %d", &a, &b);
      rep(i,6){
        dice[i] = df[i];
      }

      rep(i,4){
        if(dice[top] == a) break;
        spinfront();
      }
      rep(i,4){
        if (dice[top] == a) break;
        spinleft();
      }
      rep(i,4){
        if(dice[frt] == b) break;
        spinspin();
      }
      // rep(i, 6){
      // printf(" %d", dice[i]);
      // }
      // printf("\n");
      if(z > 0){
        //printf(" %d\n", _ );
        bool update = false;
        bool f = true;
        dz = z;
        int x = 125,y=125;
        while(f){
          f = false;
          for(int i = 6; i >= 4;--i){
            rep(j,6){
              if(dice[j] == i){
                if(j < 2){
                  break;
                }
                int nx = dx[j]+x,ny = dy[j]+y;
                if(d[dz-1][ny][nx] ==-1){
                  d[dz-1][ny][nx] = 7 - i;
                  f = true;
                  --dz;
                  x = nx;
                  y = ny;
                  update = true;
                  break;
                }
              }
            }
            if(f){
              break;
            }
          }
          //printf("  %d\n", dz);
          if(dz == 0){
            break;
          }
        }
        //printf("OK\n");
        if(!update){
          d[z][x][y] = dice[top];
          ++z;
        }
      }
      else{
        //cout<<"a"<<endl;
        d[z][125][125] = dice[top];
        //cout<<"b"<<endl;
        ++z;
      }
    }
    for(int i = 120; i <= 140; i++){
      for(int j = 120; j  <=140; j++){
        printf("%3d", d[0][i][j]);
      }
      printf("\n");
    }
    int ans[6] = {};
    rep(i,250){
      rep(j,250){
        for(int k = 249; k >= 0; --k){
          if(d[k][i][j] != -1){
            //printf(" (%d, %d, %d ) %d\n", k, i, j, d[k][i][j]);
            ans[d[k][i][j]-1]++;
            break;
          }
        }
      }
    }
    rep(i,6){
      if(i != 0) printf(" ");
      printf("%d", ans[i]);
    }
    printf("\n");
    printf("%d\n", d[1][125][125]);
  }
  return 0;
  }
