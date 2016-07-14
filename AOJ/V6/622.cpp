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
template<typename T,typename U>
ll FindErase(T &v,U tar){
  ll cnt = 0;
  for(auto it = v.begin(); it != v.end();){
    if(*it == tar){
      it = v.erase(it);
      ++cnt;
    }
    else{
      ++it;
    }
  }
  return cnt;
}

template<typename T>
bool SuffixErase(T &v,size_t suf){
  if(suf > v.size()) return false;
  for(auto it = v.begin(); it != v.end();){
    if(distance(v.begin(),it) == suf){
      v.erase(it);
      return true;
    }
    else{
      ++it;
    }
  }
  return false;
}

template<typename T>
T ston(string& str, T n){
  istringstream sin(str) ;
  T num ;
  sin >> num ;
  return num ;
}

ll n,t,q;
struct person{
  int id,dir;
  ll pos;
  person *b,*n;
  void move(){
    if(dir == 1){
      if(n == nullptr){
        pos += t;
        dir = 3;
      }
      else if(n->dir == 2){
        if(abs((pos + n->pos)/2 - pos) <= t){
          pos = n->pos = (pos+n->pos)/2;
        }
        else{
          pos += t;
          n->pos -= t;
        }
        dir = 3,n->dir = 3;
      }
      else if(n->dir == 3){
        if(abs(n->pos - pos) <= t){
          pos = n->pos;
        }
        else{
          pos += t;
        }
        dir = 3,n->dir = 3;
      }
    }
    else if(dir == 2){
      if(b == nullptr){
        pos -= t;
        dir = 3;
      }
      else if(b->dir == 3){
        if(abs(pos - b->pos) <= t){
          pos = b->pos;
        }
        else{
          pos -= t;
        }
        dir = 3,b->dir = 3;
      }
    }
  }
};

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin >> n >> t >> q;
  vector<person> p(n);
  vector<ll> obs(q);
  rep(i,n){
    p[i].id = i;
    cin >> p[i].pos >> p[i].dir;
  }
  REP(i,1,n-1){
    p[i].b = &p[i-1];
    p[i].n = &p[i+1];
  }
  rep(i,q){
    cin >> obs[i];
    obs[i]--;
  }
  if(n == 1){
    if(p[0].dir == 1){
      cout << p[0].pos + t << endl;
    }
    else{
      cout << p[0].pos - t << endl;
    }
    return 0;
  }
  if(n > 1){
    p[0].b = nullptr;
    p[0].n = &p[1];
    p[n-1].b = &p[n-2];
    p[n-1].n = nullptr;
    while(1){
      ll cnt = 0;
      rep(i,n){
        p[i].move();
        if(p[i].dir == 3){
          ++cnt;
        }
      }
      if(cnt == n){
        break;
      }
    }
    rep(i,q){
      cout << p[obs[i]].pos << endl;
    }
  }
  return 0;
}
