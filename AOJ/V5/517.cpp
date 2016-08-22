#include <bits/stdc++.h>
#include<iostream>
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
using pll = pair<ll,ll> ;

const int mod = 1000000007;
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

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll n,k;
  while(cin >> n >> k && n && k){
    vary(ll,v,k,0);
    rep(i,k){
      cin >> v[i];
    }
    sort(all(v));
    vector<pair<int,int>> vp;
    int cnt = 1,M = 0,st = v[0];
    rep(i,k-1){
      if(v[i] == 0){
        ++i;
        st = v[i];
      }
      if(v[i] == v[i+1] - 1){
        ++cnt;
      }
      else{
        vp.push_back(make_pair(st,cnt));
        M = max(M,cnt);
        cnt = 1;
        st = v[i+1];
      }
    }
    vp.push_back(make_pair(st,cnt));
    M = max(M,cnt);
    cnt = 0;
    if(n == k){
      cout << k << endl;
    }
    else if(v[0] != 0){
      cout << M << endl;
    }
    else{
      M++;
      rep(i,vp.size()-1){
        if(vp[i].fi + vp[i].se + 1 == vp[i+1].fi){
          M = max(M,vp[i].se + vp[i+1].se + 1);
        }
      }
      cout << M << endl;
    }
  }
  return 0;
}
