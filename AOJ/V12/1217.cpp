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

struct Data{
  string s;
  int id;
  int par;
};

vector<Data> d(1001);
int tar;
bool dfs(int k){
  if(k == tar) return true;
  if(d[k].id == 0) return false;
  return dfs(d[k].par);
}
void Out(bool f){
  if(f) cout << "True" << endl;
  else cout << "False" << endl;
}
int main(){
  string s;
  int a,b;
  while(cin >> a >> b && a + b){
    cin.ignore();
    d = vector<Data>(1500);
    int tk = 1;
    int par[1500] = {};
    map<string,int> m;
    REP(i,0,a){
      getline(cin,s);
      auto k = FindErase(s,' ')+1;
      m[s] = i;
      d[i] = {s,i};
      if(tk == k){
        d[i].par = par[k-1];
        par[k] = i;
      }
      else if(tk < k){
        d[i].par = par[tk];
        par[k] = i;
      }
      else{
        d[i].par = par[k-1];
        par[k] = i;
      }
      tk = k;
    }
    d[0].par = 1001;
//     rep(i,a){
//       cout << d[i].s << "'s parent " << d[d[i].par].s<<endl;
//     }
    string s2,s3,tmp;
    rep(i,b){
      cin >> s >> tmp >> tmp >> s2 >> tmp >> s3;
      s3.resize(s3.size()-1);
      if(s2 == "child"){
        Out(d[m[s]].par == m[s3]);
      }
      else if(s2 == "parent"){
        Out(d[m[s3]].par == m[s]);
      }
      else if(s2 == "sibling"){
        Out(d[m[s]].par == d[m[s3]].par);
      }
      else if(s2 == "ancestor"){
        tar = m[s];
        Out(dfs(m[s3]));
      }
      else if(s2 == "descendant"){
        tar = m[s3];
        Out(dfs(m[s]));
      }
    }
    cout << endl;
  }
  return 0;
}
