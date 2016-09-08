#include <bits/stdc++.h>
using namespace std ;

#define pb(n) push_back(n)
#define fi first
#define se second
#define all(r) begin(r),end(r)
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

struct data{
  string name;
  ll n,p;
  bool f;
  vector<string> v;
};

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll n;
  while(cin >> n && n){
    string s;
    ll p;
    map<string,ll> m;
    map<string,bool> m2;
    rep(i,n){
      cin >> s >> p;
      m[s] = p;
      m2[s] = true;
    }
    ll t;
    cin >> t;
    vector<data> v(t);
    rep(i,t){
      cin >> v[i].name;
      v[i].f = false;
      m2[v[i].name] = false;
      cin >> v[i].n;
      rep(j,v[i].n){
        cin >> s;
        v[i].v.push_back(s);
      }
    }

    while(1){
      bool f = true;
      rep(i,t){
        if(!v[i].f){
          v[i].p = 0;
          rep(j,v[i].n){
            if(!m2[v[i].v[j]]){
              f = false;
              break;
            }
            v[i].p += m[v[i].v[j]];
            if(v[i].n - 1 == j){
              v[i].f = true;
              m2[v[i].name] = true;
              m[v[i].name] = min(m[v[i].name],v[i].p);
            }
          }
        }
      }
      if(f) break;
    }
    cin >> s;
    cout << m[s] << endl;
  }

  return 0;
}

