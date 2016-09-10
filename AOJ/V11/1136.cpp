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
#define vvl(v,w,h,init) vector<vector<ll>> v(w,vector<ll>(h,init));

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
double eps = 1e-6 ;
const int dy[] = {-1,0,1,0,1,-1,1,-1};
const int dx[] = {0,-1,0,1,1,-1,-1,1};

void Correct(complex<double> &a){
  double real = a.real();
  double imag = a.imag();
  if(abs(real) == 0) real = 0;
  if(abs(imag) == 0) imag = 0;
  a = complex<double>(real,imag);
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll n;
  while(cin >> n && n){
    ll m;
    vector<vector<complex<double>>> v(8);
    vector<vector<complex<double>>> v2(n+1);
    double a,b;
    cin >> m;
    v[0].resize(m);
    v[4].resize(m);
    rep(i,m){
      cin >> a >> b;
      v[0][i] = complex<double>(a,b);
    }
    auto tmp = v[0];
    reverse(all(tmp));
    v[4] = tmp;
    REP(i,1,m){
      v[0][i] -= v[0][0];
      v[4][i] -= v[4][0];
    }
    v[0][0] -= v[0][0];
    v[4][0] -= v[4][0];
    REP(j,1,4){
      v[j].resize(m);
      v[j+4].resize(m);
      REP(i,0,m){
        v[j][i] = v[j-1][i] * complex<double> (0,1);
        v[j+4][i] = v[j+3][i] * complex<double> (0,1);
        Correct(v[j][i]);
        Correct(v[j+4][i]);
      }
    }
    rep(i,n){
      cin >> m;
      v2[i].resize(m);
      rep(j,m){
        cin >> a >> b;
        v2[i][j] =complex<double>(a,b);
      }
      REP(j,1,m){
        v2[i][j] -= v2[i][0];
      }
      v2[i][0] -= v2[i][0];
    }
    rep(i,n){
      rep(j,8){
        if(v[j] == v2[i]){
          cout << i + 1 << endl;
          break;
        }
      }
    }
    cout << "+++++"<<endl;
  }
  return 0;
}
