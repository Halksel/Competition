#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<map>
#include<set>

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

ll r,c,n,x,y,w ,z;
bool judge(pll p){
  ll x = p.fi,y = p.se;
  return (x == 0 || x == r) || (y == 0 || y == c);
}

int f(pll a){
  if(a.fi == 0 ){
    return 4;
  }
  else if(a.fi == r){
    return 2;
  }
  else if(a.se == 0){
    return 1;
  }
  else if(a.se == c){
    return 3;
  }
  return 0;
}

bool circle(const pair<pll,int> &p,const pair<pll,int> &q){
  pll a = p.fi,b = q.fi;
  if(a.fi == 0 && b.fi == 0){
    return a.se > b.se;
  }
  else if(a.fi == r && b.fi == r){
    return a.se < b.se;
  }
  else if(a.se == 0 && b.se == 0){
    return a.fi < b.fi;
  }
  else if(a.se == c && b.se == c){
    return a.fi > b.fi;
  }
  else{
    return f(a) < f(b);
  }
}

int pos(int x,int y){
  pll a = mp(x,y);
  if(a.se == 0){
    return x;
  }
  else if(a.fi == r){
    return y + r;
  }
  else if(a.se == c){
    return c + r + (r - x);
  }
  else if(a.fi == 0 ){
    return c + r + r + (c - y);
  }
  return -1;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin >> r >> c >> n;
  vector<pair<int,int>> v;
  stack<int> s;
  rep(i,n){
    cin >> x >> y;
    cin >> w >> z;
    if(judge(mp(x,y)) && judge(mp(w,z))){
      v.push_back(mp(pos(x,y),i));
      v.push_back(mp(pos(w,z),i));
    }
  }
  sort(all(v));
  /* map<ll,int> m; */
  /* rep(i,2 * n){                                              */
  /*   if(judge(v[i].fi)){                                      */
  /*     m[v[i].se]++;                                          */
  /*   }                                                        */
  /* }                                                          */
  bool ex[100001] = {};
  rep(i,v.size()){
      int v2 = v[i].se;
      if(ex[v2] == false){
        s.push(v2);
        ex[v2] = true;
      }
      else{
        if(v2 != s.top()){
          std::cout << "NO" << std::endl;
          return 0;
        }
        s.pop();
        ex[v2] = false;
      }
  }
  cout << "YES" << endl;
  return 0;
}
