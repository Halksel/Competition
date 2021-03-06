#include <bits/stdc++.h>
using namespace std ;

#define pb(n) push_back(n)
#define fi first
#define se second
#define all(r) (r).begin(),(r).end()
#define gsort(st,en) sort((st),(en),greater<int>())
#define vmax(ary) *max_element(all(ary))
#define vmin(ary) *min_element(all(ary))
#define debug(x) cout<<#x<<": "<<x<<endl
#define fcout(n) cout<<fixed<<setprecision((n))
#define scout(n) cout<<setw(n)
#define vary(type,name,size,init) vector< type> name(size,init)
#define vvl(v,w,h,init) vector<vector<ll>> v(w,vector<ll>(h,init));

#define rep(i,n) for(int i = 0; i < (int)(n);++i)
#define REP(i,a,b) for(int i = (a);i < (int)(b);++i)
#define repi(it,array) for(auto it = array.begin(),end = array.end(); it != end;++it)
#define repa(n,array) for(auto &n :(array))

using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using dict = map<string,int>;
using pii = pair<int,int> ;
using pll = pair<ll,ll> ;

const int mod = 1000000007;
constexpr int imax = ((1<<30)-1)*2+1 ;
constexpr int inf = 100000000;
constexpr double PI = acos(-1.0) ;
double eps = 1e-10 ;
const int dy[] = {-1,0,1,0,1,-1,1,-1};
const int dx[] = {0,-1,0,1,1,-1,-1,1};

inline bool value(int x,int y,int w,int h){
  return (x >= 0 && x < w && y >= 0 && y < h);
}

template<typename T>
void Unique(vector<T> &v){
  sort(all(v));
  v.erase(unique(all(v)),v.end());
}

template<typename T>
T ston(string& str, T n){
  istringstream sin(str) ;
  T num ;
  sin >> num ;
  return num ;
}

void Ans(bool f){
  if(f) cout << "YES"<<endl;
  else cout << "NO"<<endl;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll w,h;
  while(cin >> w >> h && w && h){
    vector<vector<ll>> v(w * 2+1,vector<ll>(h*2+1,0));
    rep(j,h-1){
      rep(i,w-1){
        cin >> v[i*2+1][2*j];
      }
      rep(i,w){
        cin >> v[i*2][2*j+1];
      }
    }
    rep(i,w-1){
      cin >> v[i*2+1][(h-1)*2];
    }
    queue<pll> q;
    q.push({0,0});
    v[0][0] = 1;
    ll depth = 1;
    while(q.size()){
      ll s = q.size();
      rep(i,s){
        if(q.size()){
          auto p = q.front();q.pop();
          rep(i,4){
            int nx = p.fi + dx[i]*2,ny = p.se + dy[i]*2;
            if(value(nx,ny,w*2,h*2) && v[nx][ny] == 0){
              if(value(nx-dx[i],ny-dy[i],w*2+1,h*2-1) && v[nx-dx[i]][ny-dy[i]] == 0){
                q.push({nx,ny});
                v[nx][ny] = depth+1;
                if(nx == (w-1)*2 && ny == (h-1)*2){
                  q = queue<pll>();
                  i = s;
                  break;
                }
              }
            }
          }
        }
      }
      ++depth;
    }
//     rep(i,h*2){
//       rep(j,w*2+1){
//         cout << v[j][i]<< " ";
//       }
//       cout << endl;
//     }
    cout << v[(w-1)*2][(h-1)*2]<<endl;
  }
  return 0;
}
