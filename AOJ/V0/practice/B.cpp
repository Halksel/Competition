#include<iostream>
#include<sstream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<map>
#include<numeric>

using namespace std ;

#define pb(n) push_back(n)
#define fi first
#define se second
#define all(r) (r).begin(),(r).end()
#define gsort(st,en) sort((st),(en),greater<int>())
#define vmax(ary) *max_element(all(ary))
#define vmin(ary) *min_element(all(ary))
#define debug(x) cout<<#x<<": "<<x<<endl

#define rep(i,n) for(int i = 0; i < (int)(n);++i)
#define repc(i,a,b) for(int i = (a);i < (int)(b);++i)
#define repi(it,array) for(auto it = array.begin(); it != array.end();++it)
#define repa(n,array) for(auto n :(array))

typedef long long ll ;
typedef vector<int> vi ;
typedef vector<ll> vl ;
//template<class Value>
//using dict = std::map< string, Value >;
typedef map<string,int> dict ;

constexpr int imax = ((1<<30)-1)*2+1 ;
constexpr int inf = 100000000;
double eps = 1e-10 ;

  template <typename T>
void out(vector < T > v)
{
  for(size_t i = 0; i < v.size(); i++)
  {
    debug(v[i]);
  }
}

template<typename T>
string ntos( T i ) {
  ostringstream s ;
  s << i ;
  return s.str() ;
}

template<typename T>
T ston(string str, T n){
  istringstream sin(str) ;
  T num ;
  sin >> num ;
  return num ;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int a,b,c,d,e,na,nb,nc,sum,pro = imax,tmp;
  while(1){
    cin >> a >> b >> c >> d >> e;
    if(a + b + c + d + e == 0){
      break;
    }
    cin >> na >> nb >> nc;
    sum = na+nb+nc;
    if(nc >= d){
      pro = nc * e + nb * b + na * a;
    }
    else if(nc + nb >= d){
      repc(i,1,nb+1){
        if(((nc * c + i * b) > (nc+i) * e) && nc+i >= d){
          tmp = (nc+i) * e + (nb-i) * b + na * a;
          if(pro > tmp){
            pro = tmp;
          }
        }
        else if(nc + i < d && (nc*c+i*b) > d*e){
          tmp = d*e + (nb-i)*b+na*a;
          if(pro > tmp){
            pro = tmp;
          }
        }
        else if(i == nb){
          pro = na * a + nb * b + nc *c;
        }
      }
    }
    else if(sum >= d){
      repc(i,1,na+1){
        if((nc*c+nb*b+i*a) > (nc+nb+i) * e){
          tmp = (nc + nb + i)*e+(na-i)*a;
          if(pro > tmp){
            pro = tmp;
          }
        }
        else if(nc+nb+i<d && (nc*c+nb*b+i*a) > d*e){
          tmp = d*e + (na-i) * a;
          if(pro > tmp){
            pro = tmp;
          }
        }
        else if(i == na){
          pro = na * a + nb * b + nc *c;
        }
      }
    }
    else{
      pro = na * a + nb * b + nc *c;
      if(pro > d*e){
        pro = d*e;
      }
    }
    cout << pro << endl;
  }
  return 0;
}
