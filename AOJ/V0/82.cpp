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

#define rep(i,n) for(int i = 0; i < (int)(n);++i)
#define REP(i,a,b) for(int i = (a);i < (int)(b);++i)
#define repi(it,array) for(auto it = array.begin(),end = array.end(); it != end;++it)
#define repa(n,array) for(auto &n :(array))

using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using dict = map<string,int>;
using pii = pair<int,int> ;

constexpr int imax = ((1<<30)-1)*2+1 ;
constexpr int inf = 100000000;
constexpr double PI = acos(-1.0) ;
double eps = 1e-10 ;
const int dy[] = {-1,0,1,0};
const int dx[] = {0,-1,0,1};

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

const int horse[8] = {4,1,4,1,2,1,2,1};
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  vector<vector<int>> v(8);
  rep(i,8){
    rep(j,8){
      v[i].pb(horse[(i+j)%8]);
    }
  }
  vary(int,c,8,0);
  while(1){
    rep(i,8){
      if(cin >> c[i]){

      }
      else
        break;
    }
    if(cin.eof()) break;
    int ans=0;
    int min = inf;
    rep(i,8){
      int sum =0;
      rep(j,8){
        if(c[j] - v[i][j] > 0){
          sum += c[j] - v[i][j];
        }
      }
      if(sum < min){
        ans = i;
        min = sum;
      }
      else if(sum == min){
        rep(l,8){
          if(v[i][l] < v[ans][l]){
            ans = i;
            break;
          }
          else if(v[i][l] > v[ans][l]){
            break;
          }
        }
      }
    }
    rep(i,7){
      cout << v[ans][i]<< " ";
    }
    cout << v[ans][7] << endl;
  }
  return 0;
}
