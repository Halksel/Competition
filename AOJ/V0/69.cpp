#include <bits/stdc++.h>
using namespace std ;

#define pb(n) push_back(n)
#define fi first
#define se second
#define all(r) (r).begin(),(r).end()
#define vmax(ary) *max_element(all(ary))
#define vmin(ary) *min_element(all(ary))
#define debug(x) cout<<#x<<": "<<x<<endl

#define rep(i,n) for(int i = 0; i < (int)(n);++i)
#define REP(i,a,b) for(int i = (a);i < (int)(b);++i)

using ll = long long;
using pii = pair<int,int> ;
using pll = pair<ll,ll> ;

ll n,m,k,d;
bool Solve(vector<vector<char>> v){
  int pos = m,h = 0;
  while(h < d){
    if(v[h][pos] == 1){
      ++pos;
      ++h;
    }
    else{
      if(pos > 0 && v[h][pos-1] == 1){
        --pos;
      }
      ++h;
    }
  }
  if(pos == k) return true;
  return false;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  while(cin >> n && n){
    cin >> m >> k >> d;
    --m,--k;
    vector<vector<char>> v(d,vector<char>(n,0));
    rep(i,d){
      rep(j,n-1){
        cin >> v[i][j];
        v[i][j] -= '0';
      }
    }
    auto copy = v;
    if(Solve(v)){
      cout << 0 << endl;
    }
    else{
      bool flag = false;
      rep(i,d){
        rep(j,n-1){
          if(v[i][j] == 0){
            v = copy;
            if(j == 0){
              if(v[i][1] == 0){
                v[i][j] = 1;
              }
            }
            else if(j == n-2){
              if(v[i][j-1] == 0){
                v[i][j] = 1;
              }
            }
            else if(v[i][j-1] == 0 && v[i][j+1] == 0){
              v[i][j] = 1;
            }
            if(Solve(v)){
              flag = true;
              cout << i+1 << ' ' << j+1 << endl;
              break;
            }
          }
        }
        if(flag){
          break;
        }
      }
      if(!flag){
        cout << 1 << endl;
      }
    }
  }
  return 0;
}

