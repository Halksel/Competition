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
#define ll long long

#define rep(i,n) for(int i = 0; i < (int)(n);++i)
#define REP(i,a,b) for(int i = (a);i < (int)(b);++i)
#define repi(it,array) for(auto it = array.begin(),end = array.end(); it != end;++it)
#define repa(n,array) for(auto &n :(array))

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll r,c,k,n,rr,cc;
  ll ans = 0;
  cin >> r >> c >> k >> n;
  vary(int,vr,r+2,0);
  vary(int,vc,c+2,0);
  vector<int> rn(n+2),cn(n+2);
  vector<pair<int,int>> vp(n);
  rep(i,n){
    cin >> rr >> cc;
    vr[rr]++;
    vc[cc]++;
    vp[i] = make_pair(rr,cc);
  }
  REP(i,1,max(r,c)+1){
    if(i < r+1){
      rn[vr[i]]++;
    }
    if(i < c+1){
      cn[vc[i]]++;
    }
  }
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
