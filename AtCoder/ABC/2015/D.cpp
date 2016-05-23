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
  int N,M,num,ans;
  double lnum,rnum;
  map<int,int> men;
  bool lflag = true, rflag = true;
  cin >> N >> M ;
  vi train(N,0), ment(N,0),menl(N,0),menr(N,0) ;
  while(cin >> num){
    ment[num-1] = 1 ;
    train[num-1] = 1;
  }
  rep(i,N){
    if(ment[i] == 1){
      lflag = true;
      rflag = true;
      for(int j = 1; j < N; ++j){
        if(i-j > -1 ){
          if(ment[i-j] == 0 && train[i-j] == 0 && lflag){
            ++menl[i] ;
          }
          else if(ment[i-j] != 0 || train[i-j] != 0){
            lflag = false ;
          }
        }
        if(i+j < N){
          if(ment[i+j] == 0 && train[i+j] == 0 && rflag){
            ++menr[i] ;
          }
          else if(ment[i+j] != 0 || train[i+j] != 0){
            rflag = false ;
          }
        }
      }
    }
  }
  //men 1:存在,2:確定右へ,3:確定左へ,4:右へ,5:左へ
  rep(i,N){
    if(ment[i] == 1){
      if(menl[i] == 0 && menr[i] != 0){
        men[i] = 2;
      }
      else if(menr[i] == 0 && menl[i] != 0){
        men[i] = 3;
      }
      else if(menr[i] > menl[i]){
        men[i] = 4;
      }
      else{
        men[i] = 5;
      }
    }
  }
  auto it = men.begin();
  for(int i = 0; i < N; ++i){
    if(ment[i] == 1){
      it = men.find(i);
      if(it->se != 2 || it->se != 3){
        if(it->se == 4){
          ++it;
          if(it->se == 5){
            rnum = 1.0*(it->fi - i -1)/2;
          }
        }
        else if(it->se == 5){
          --it;
          if(it->se == 4){
            lnum = 1.0*(i - it->fi-1)/2;
          }
        }
        ment[i] = (rnum > lnum)?2:3;
      }
      else{
        ment[i] = it->fi;
      }
    }
    ++it;
  }
  cout << "ment 2:右へ,3:左へ" << endl;
  /*repi(it,men){
    cout << "fi" << it->fi << " se" << it->se << endl;
  }*/
  out(menr);
  cout << "menr outputed" << endl;
  out(menl);
  return 0;
}
