#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<functional>
#include<numeric>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<utility>
#include<sstream>
#include<complex>
#include<fstream>
#include<bitset>
#include <iostream>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;
ll h, w, c;
int dx[4] = { 0,1 ,0 ,-1};
int dy[4] = { 1,0 ,-1, 0};

#define rep(i,n) for(int i = 0;i < n;++i)

bool value(int x, int y, int w, int h) {
	return 0 <= x && x < w && 0 <= y && y < h;
}

int ccount(int x, int y, int c,vector<vector<int>> &v,vector<vector<bool>> &f) {
	if (!value(x,y,h,w) || f[x][y]) return 0;
	f[x][y] = true;
	int res = 1;
	rep(i, 4) {
		int nx = x + dx[i], ny = y + dy[i];
		if (value(nx, ny, h, w) && c == v.at(nx).at(ny)) {
			res += ccount(nx, ny, c,v,f);
		}
	}
	return res;
}

void change(int x, int y, int c, int nc,vector<vector<int>> &v,vector<vector<bool>> &f) {
	if (!value(x,y,h,w) || f[x][y]) return;
	f[x][y] = true;
  v[x][y] = nc;
	rep(i, 4) {
		int nx = x + dx[i], ny = y + dy[i];
		if (value(nx, ny, h, w) && c == v.at(nx).at(ny)) {
      change(nx, ny, c, nc,v,f);
		}
	}
}

int ans = 0;
void solve(int k, int c,vector<vector<int>> v,vector<vector<bool>> f) {
	if (k == 4) {
    vector<vector<bool>> f2(h,vector<bool>(w,false));
		change(0, 0, v[0][0], c,v,f2);
      /* cout << "F" << endl;    */
      /* rep(u,h){               */
      /* rep(j,w){               */
      /* cout << v[u][j] << ' '; */
      /* }                       */
      /* cout << endl;           */
      /* }                       */
    vector<vector<bool>> f3(h,vector<bool>(w,false));
		ans = max(ans, ccount(0, 0, c,v,f3));
	}
	else if(k < 5){
		int C = v[0][0];
    auto b = v;
    auto u = f;
		rep(i, 6) {
			if (i+1 == C) continue;
      rep(i,h){
        rep(j,w){
          f[i][j] = false;
        }
      }
			change(0, 0, C, i+1,v,f);
      /* cout << endl;           */
      /* rep(u,h){               */
      /* rep(j,w){               */
      /* cout << v[u][j] << ' '; */
      /* }                       */
      /* cout << endl;           */
      /* }                       */
			solve(k + 1, c,v,f);
      v = b;
      f = u;
		}
	}
};

int main() {
	while (cin >> h >> w >> c, h + w + c) {
    vector<vector<int> > v;
    vector<vector<bool>> f(h,vector<bool>(w,false));
		v.resize(h);
		ans = 0;
		rep(i, h) {
			v[i].resize(w);
			rep(j, w) {
				cin >> v[i][j];
				f[i][j] = false;
			}
		}
		solve(0, c,v,f);
		cout << ans << endl;
	}
	return 0;
}
