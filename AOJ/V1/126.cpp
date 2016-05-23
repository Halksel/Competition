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

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n;
  cin>>n;
  rep(i,n){
    vector<vector<int>> v(9,vector<int>(9,0));
    vector<vector<char>> v2(9,vector<char>(9,' '));
    if( i != 0) cout << endl;
    rep(i,9){
      rep(j,9){
        cin>>v[j][i];
      }
    }
    rep(i,9){
      int num[10] = {};
      rep(j,9){
        num[v[j][i]]++;
      }
      rep(j,9){
        if(num[v[j][i]] > 1){
          v2[j][i] = '*';
        }
      }
    }
    rep(j,9){
      int num[10] = {};
      rep(i,9){
        num[v[j][i]]++;
      }
      rep(i,9){
        if(num[v[j][i]] > 1){
          v2[j][i] = '*';
        }
      }
    }
    for(int i = 0; i < 9 ; i+= 3){
      for(int j = 0; j < 9; j += 3){
        int num[10]={};
        rep(k,3){
          rep(l,3){
            num[v[j+l][i+k]]++;
          }
        }
        rep(k,3){
          rep(l,3){
            if(num[v[j+l][i+k]] > 1){
              v2[j+l][i+k] = '*';
            }
          }
        }
      }
    }
    rep(i,9){
      rep(j,9){
        cout << v2[j][i]<<v[j][i];
      }
      cout << endl;
    }
  }
  return 0;
}
