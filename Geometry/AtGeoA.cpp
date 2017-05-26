//http://geocon2013.contest.atcoder.jp/tasks/geocon2013_a
//http://geocon2013.contest.atcoder.jp/submissions/1306231
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

using ll = long long;
using pii = pair<int,int> ;
using pll = pair<ll,ll> ;

  typedef complex<double> P;//複素数を平面における点と解釈
  namespace std {
    bool operator < (const P& a, const P& b) {//x軸を優先
      return real(a) != real(b) ? real(a) < real(b) : imag(a) < imag(b);
    }
  }
  struct L : public vector<P> {//直線
    L(){};
    L(const P &a, const P &b) {
      push_back(a); push_back(b);
    }
  };

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll n = 300;
  vector<pair<P,int>> ps(n);
  double x,y;
  rep(i,300){
    cin >> x >> y;
    ps[i] = mp(P(x,y),i+1);
  }
  sort(all(ps));
  set<int> p;
  vector<pair<pll,ll>> ans;
  rep(i,n-2){
    if(p.find(ps[i].se) == p.end()){
      p.insert(ps[i].se);
      p.insert(ps[i+1].se);
      p.insert(ps[i+2].se);
      ans.push_back(mp(mp(ps[i+1].se,ps[i+2].se),ps[i].se));
    }
  }
  cout << p.size() / 3 << endl;
  rep(i,p.size()/3){
    cout << ans[i].fi.fi << ' ' << ans[i].fi.se << ' ' << ans[i].se << endl;
  }

  return 0;
}
