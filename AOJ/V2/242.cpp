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
vector<string> Split(char c,string s){
  vector<string> res(0);
  string str = "";
  rep(i,s.size()){
    if(s[i] == c){
      res.push_back(str);
      str.clear();
    }
    else{
      str += s[i];
    }
  }
  res.push_back(str);
  return res;
}
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll n;
  while(cin >> n&&n){
    string str;
    char k;
    map<string,ll> m;
    vector<pair<ll,string>> vps;
    cin.ignore();
    rep(i,n){
      getline(cin,str);
      auto vs = Split(' ',str);
      rep(j,vs.size()){
        m[vs[j]]--;
      }
    }
    cin >> k;
    for(auto n : m){
      vps.push_back(make_pair(n.se,n.fi));
    }
    sort(all(vps));
    string ans ="";
    ll cnt = 0;
    rep(i,vps.size()){
      if(cnt > 4) break;
      if(vps[i].se[0] == k){
        ++cnt;
        if(ans.size()){
          ans += " ";
        }
        ans += vps[i].se;
      }
    }
    if(ans.size())
      cout << ans << endl;
    else
      cout << "NA"<<endl;
  }
  return 0;
}
