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
const int dy[] = {-1,0,1};
const int dx[] = {-1,0,1};
const int dz[] = {-1,0,1};

inline bool value(int x){
  return (x >= 0 && x < 5);
}
vector<int> a,b;
array<array<array<int,5>,5>,5> ca;
int check(int x,int y,int z,int f){
  int al = 0;
  rep(i,3){
    rep(j,3){
      rep(k,3){
        int cx = x + dx[k],cy = y + dy[j],cz = z+dz[i];
        if(value(cx) && value(cy) && value(cz)){
          al += ca[cx][cy][cz];
        }
      }
    }
  }
  al -= f;
  if(f == 0){
    rep(i,a.size()){
      if(al == a[i]){
        return 1;
      }
    }
    return 0;
  }
  else{
    rep(i,b.size()){
      if(al == b[i]){
        return 1;
      }
    }
    return 0;
  }
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll n,cnt = 1;
  while(cin >> n && n){
    if(cnt != 1){
      cout << endl;
    }
    char c;
    rep(z,5){
      rep(y,5){
        rep(x,5){
          cin >> c;
          ca[x][y][z] = c - '0';
        }
      }
    }
    ll m1,m2,k;
    cin >> m1;
    a.clear();
    rep(j,m1){
      cin >> k;
      a.push_back(k);
    }
    cin >> m2;
    b.clear();
    rep(j,m2){
      cin >> k;
      b.push_back(k);
    }
    rep(l,n){
      array<array<array<int,5>,5>,5> c2;
      rep(z,5){
        rep(y,5){
          rep(x,5){
            c2[x][y][z] = check(x,y,z,ca[x][y][z]);
          }
        }
      }
      ca = c2;
    }
    cout << "Case " << cnt << ":" << endl;
    rep(z,5){
      rep(y,5){
        rep(x,5){
          cout << ca[x][y][z];
        }
        cout << endl;
      }
      if(z != 4)
      cout << endl;
    }
    ++cnt;
  }
  return 0;
}
