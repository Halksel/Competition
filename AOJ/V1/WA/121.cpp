#include <bits/stdc++.h>
using namespace std ;

#define pb(n) push_back(n)
#define fi first
#define se second
#define all(r) (r).begin(),(r).end()
#define vmax(ary) *max_element(all(ary))
#define vmin(ary) *min_element(all(ary))
#define debug(x) cout<<#x<<": "<<x<<endl
#define fcout(n) cout<<fixed<<setprecision((n))
#define scout(n) cout<<setw(n)
#define vary(type,name,size,init) vector< type> name(size,init)
#define vvl(v,w,h,init) vector<vector<ll>> v(w,vector<ll>(h,init))
#define mp(a,b) make_pair(a,b)

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
constexpr int inf = ((1<<30)-1)*2+1 ;
constexpr double PI = acos(-1.0) ;
double eps = 1e-10 ;
const int dx[] = {-1,1,-4,4,1,-1,-1,1};

inline bool value(int x,int w){
  return x >= 0 && x < w;
}

bool check(vector<int> v){
  rep(i,8){
    if(v[i] != i){
      return false;
    }
    if(i == 7){
      return true;
    }
  }
  return true;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  vector<int> v(8);
  while(cin >> v[0]){
    REP(i,1,8){
      cin >> v[i];
    }
    queue<vector<int>> q;
    queue<int> cnt;
    set<vector<int>> s;
    q.push(v);
    cnt.push(0);
    s.insert(v);
    while(1){
      bool f= false;
      f = false;
      auto Q = q.front();q.pop();
      int C = cnt.front();cnt.pop();
      if(check(Q)){
        cout << C << endl;
        f = true;
        break;
      }
      else{
        rep(i,8){
          cout << Q[i] ;
        }
        cout << endl;
      }
      int p = 0;
      rep(i,8){
        if(Q[i] == 0){
          p = i;
          break;
        }
      }
      auto tmp = Q;
      rep(i,4){
        Q = tmp;
        if(value(p+dx[i],8)){
          swap(Q[p],Q[p+dx[i]]);
          if(s.insert(Q).se){
            q.push(Q);
            cnt.push(C+1);
          }
        }
      }
      if(C > 31){
        break;
      }
      if(f){
        break;
      }
    }
  }
  return 0;
}
