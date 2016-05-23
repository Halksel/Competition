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

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int r,c,k,n,rr,cc;
  int ans = 0;
  cin >> r >> c >> k >> n;
  vary(int,vr,r+5,0);
  vary(int,vc,c+5,0);
  vector<vector<int>> v (r+5,vector<int>(c+5,0));
  vector<pair<int,int>> vp(n);
  rep(i,n){
    cin >> rr >> cc;
    v[rr][cc] = 1;
    vr[rr]++;
    vc[cc]++;
    vp[i] = make_pair(rr,cc);
  }
  vector<int> rn(n+5),cn(n+5);
  REP(i,1,r+1){
    rn[vr[i]]++;
  }
  REP(i,1,c+1){
    cn[vc[i]]++;
  }
//   for(auto it = rn.begin(); it != rn.end();++it){
//     cout << *it<<endl;
//   }
//   debug("c");
//   for(auto it = cn.begin(); it != cn.end();++it){
//     cout << *it<<endl;
//   }
  int a = 0,b = 0;
  rep(i,n){
    if(i < k+1){
      ans += rn[i]*cn[k-i];
    }
    if(vr[vp[i].fi] + vc[vp[i].se] == k+1){
      ans++;
    }
    else if(vr[vp[i].fi] + vc[vp[i].se] == k){
      ans--;
    }
  }
  cout << ans << endl;
  return 0;
}
