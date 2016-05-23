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
  vector<vector<int>> v(4,vector<int>(2,0));
  while(1){
    pii pos ;
    rep(i,2){
      rep(j,4){
        cin >> v[j][i];
        if(v[j][i] == 0) pos = make_pair(j,i);
      }
    }
    if(cin.eof())break;
    int ans = 0;
    queue<pii> q;
    queue<vector<vector<int>>> qv;
    q.push(pos);
    qv.push(v);
    set<string> s;
    string str;
    while(!(q.empty() && qv.empty())){
      int size = q.size();
      rep(l,size){
        pii P = q.front();q.pop();
        auto v2 = qv.front();qv.pop();
        bool f = true;
        rep(i,2){
          rep(j,4){
            if(v2[j][i] != i*4+j){
              f = false;
            }
          }
        }
        if(f) break;
        str = "";
        rep(i,2){
          rep(j,4){
            str += to_string(v2[j][i]);
          }
        }
        if(s.find(str) == s.end()){
          auto tmp = v2;
          s.insert(str);
          rep(i,4){
            int x = P.fi+dx[i],y = P.se+dy[i];
            v2 = tmp;
            if(value(x,y,4,2)){
              swap(v2[x][y],v2[P.fi][P.se]);
              q.push(make_pair(x,y));
              qv.push(v2);
            }
          }
        }
      }
      ++ans;
    }
    cout << ans << endl;
  }
  return 0;
}
