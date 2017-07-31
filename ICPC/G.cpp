#include<bits/stdc++.h>

using namespace std;

#define rep(i,n) for(int i = 0; i < n;++i)
#define all(v) v.begin(),v.end()
#define mp(a,b) make_pair(a,b)

using ll = long long;
using pii = pair<int,int>; 

ll n,m;

int dx[4] = {0,1,0,-1};
int dy[4] = {-1,0,1,0};

int tox[5] = {};
int toy[5] = {};
int inf = 100000;

vector<vector<char>> v(51,vector<char>(51)),c;
vector<vector<int>> f(51,vector<int>(51));

inline bool value(int x,int y){
  return 0 <= x && x < m && 0 <= y && y < n;
}
void print(){
  cout << endl;
  rep(i,n){
    rep(j,m){
      cout << f[i][j] << ' ';
    }
    cout << endl;
  }
}

void setboard(){
  rep(i,n){
    rep(j,m){
      if(v[i][j] == '#'){
        f[i][j] = -1;
      }
      else{
        int cnt = 0;
        rep(k,4){
          int y = i + dy[k],x = j + dx[k];
          if(value(x,y) && v[y][x] == '.'){
            ++cnt; 
          }
        }
        if(cnt <= 1){
          v[i][j] = '#';
          f[i][j] = -1;
        }
        else{
          f[i][j] = inf;
        }
      }
    }
  }
  f[0][0] = 0;
}

bool bfs(){
  rep(i,50 * 50)
    setboard();
  /* print(); */
  int t = 0;
  int x = 0,y = 0;
  int d = 0;
  rep(_,51 * 51){
    if(x == tox[t] && y == toy[t]){
      ++t;
      if(t == 4){
        return true;
      }
    }
    rep(j,4){
      int i = (t + j) % 4;
      int nx = x + dx[i],ny = y + dy[i];
      if(value(nx,ny) && f[ny][nx] == inf){
        ++d;
        f[ny][nx] = d ;
        x = nx,y = ny;
        break;
      }
      if(t == 3 && value(nx,ny) && (f[ny][nx] == inf || f[nx][ny] == 0)){
        ++d;
        f[ny][nx] = d ;
        x = nx,y = ny;
        break;
      }
    }
  }
  return false;
}

int main(){
  while(cin >> n >> m,n+m){
    rep(i,n){
      rep(j,m){
        cin >> v[i][j];
      }
    }
    tox[0] = m-1,toy[0] = 0;
    tox[1] = m-1,toy[1] = n-1;
    tox[2] = 0,toy[2] = n-1;
    tox[3] = 0,toy[3] = 0;
    if(bfs()){
      cout << "YES" << endl;
    }
    else{
      cout << "NO"<<endl;
    }
    /* print(); */
  }
  return 0;
}
