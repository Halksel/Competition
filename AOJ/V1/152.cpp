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
  while(cin>>n&&n){
    int num;
    vector<vector<pii>> v(11,vector<pii>(n,make_pair(0,0)));
    vector<pair<int,string>> ps(n,make_pair(0,""));
    int frame = 0,s;
    string str;
    rep(i,n){
      cin >> str;
      ps[i].se = str;
      while(frame<9){
        rep(j,2){
          cin >> s;
          if(frame > 1){
            if(v[i][frame-2].se > 1){
              v[i][frame-2].fi += s;
              v[i][frame-2].se--;
            }
          }
          if(frame > 0){
            if(v[i][frame-1].se > 0){
              v[i][frame-1].fi += s;
              v[i][frame-1].se--;
            }
          }
          if(s == 10){
            v[i][frame].se = 2;
            v[i][frame].fi += s;
            break;
          }
          v[i][frame].fi += s;
          if(v[i][frame].fi == 10){
            v[i][frame].se = 1;
          }
        }
        ++frame;
      }
      rep(j,3){
        cin >> s;

        v[i][frame].fi += s;
        if(j == 1){
          if(v[i][frame].fi < 10) break;
          if(frame > 0){
            if(v[i][frame-1].se > 1){
              v[i][frame-1].fi += s;
              v[i][frame-1].se--;
            }
          }
        }
      }
      rep(j,10){
        scout(3)<<v[i][j].fi;
        ps[i].fi += v[i][j].fi;
      }
      cout << endl;
      cout << ps[i].fi<<endl;
    }
  }
  return 0;
}
