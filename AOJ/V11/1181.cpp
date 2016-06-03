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
const int dy[] = {-1,0,1, 0,1,-1,1,-1};
const int dx[] = { 0,1,0,-1,1,-1,-1,1};

inline bool value(int x,int y,int w,int h){
  return (x >= 0 && x < w && y >= 0 && y < h);
}

enum{
  t = 0,
  f ,
  r ,
  b ,
  l ,
  d,
};

array<int,6> dice = {1,3,5,4,2,6};

void Spin(array<int,6> &D,int dir){
  if(dir == l){//
    swap(D[t],D[r]);
    swap(D[r],D[d]);
    swap(D[d],D[l]);
  }
  else if(dir == r){
    swap(D[t],D[l]);
    swap(D[l],D[d]);
    swap(D[d],D[r]);
  }
  else if(dir == f){
    swap(D[t],D[b]);
    swap(D[b],D[d]);
    swap(D[d],D[f]);
  }
  else if(dir == b){
    swap(D[t],D[f]);
    swap(D[f],D[d]);
    swap(D[d],D[b]);
  }
  else if(dir == d){//leftspin
    swap(D[f],D[r]);
    swap(D[r],D[b]);
    swap(D[b],D[l]);
  }
  else if(dir == t){
    swap(D[f],D[l]);
    swap(D[l],D[b]);
    swap(D[b],D[r]);
  }
}

void ViewDice(array<int,6> D){
  rep(i,6){
    cout << D[i]<< " ";
  }
  cout << endl;
}

array<array<pll,100>,100> field;
void Fall(ll x,ll y, array<int,6> D){
  auto tmp = field[x][y];
  field[x][y] = {D[t],tmp.se+1};
  if(field[x][y].se >= 2){
    for(int k = 6; k >= 4; --k){
      if(find(D.begin()+1,D.begin()+5,k) != D.begin()+5){
        ll dir =find(D.begin()+1,D.begin()+5,k)-D.begin();
        rep(i,4){
          ll nx = x+dx[i],ny = y + dy[i];
          if(dir == i+1 && field[nx][ny].se < tmp.se){
            Spin(D,dir);
            field[x][y] = tmp;
            Fall(x+dx[i],y+dy[i],D);
            k = 0;
            break;
          }
        }
      }
    }
  }
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll n,F,T;
  while(cin >> n && n){
    rep(i,n){
      auto D = dice;
      cin >> T >> F;
      rep(i,4){
        if(T == D[t]){
          break;
        }
        Spin(D,f);
      }
      if( T != D[t] ){
        rep(i,4){
          if(T == D[t]){
            break;
          }
          Spin(D,r);
        }
      }
      rep(i,4){
        if(F == D[f]){
          break;
        }
        Spin(D,d);
      }
      Fall(50,50,D);
    }
    ll ans[7] ={};
    rep(i,100){
      rep(j,100){
        ans[field[j][i].fi]++;
        field[j][i] = {0,0};
      }
    }
    rep(i,6){
      if(i) cout << ' ';
      cout << ans[i+1];
    }
    cout << endl;
  }
  return 0;
}
