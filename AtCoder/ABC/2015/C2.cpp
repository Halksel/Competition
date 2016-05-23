#include<iostream>
#include<sstream>
#include<string>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<map>
#include<vector>

using namespace std ;

#define pb(n) push_back(n)
#define fi first
#define se second
#define np string::npos
#define all(r) (r).begin(),(r).end()
#define gsort(st,en) sort((st),(en),greater<int>())
#define vmax(ary) *max_element(all(ary))
#define vmaxi(ary) max_element(all(ary))
#define vmin(ary) *min_element(all(ary))
#define debug(x) cout<<#x<<": "<<x<<endl

#define rep(i,n) for(int i = 0; i < (int)(n);++i)
#define repc(i,a,b) for(int i = (a);i < (int)(b);++i)
#define repi(it,array) for(auto it = array.begin(),end = array.end(); it != end;++it)
#define repa(n,array) for(auto n :(array))

typedef long long ll ;
typedef vector<int> vi ;
typedef vector<ll> vl ;
typedef map<string,int> dict;


int main(){
  ios::sync_with_stdio(false);
  int N,M,x;
  vector<int>::iterator i1,i2 ;
  bool flag = true;
  scanf("%d%d",&N,&M);
  if(N < M){
    flag = false ;
  }
  else{
    vi A(N,0) ,B(M,0) ;
    rep(i,N){
      scanf("%d",&A[i]) ;
    }
    rep(i,M){
      scanf("%d",&B[i]) ;
    }
    i1 = vmaxi(A) ;
    i2 = vmaxi(B) ;
    if(*i1 < *i2 ){
      flag = false;
    }
    else{
      while(!B.empty()){
        i1 = vmaxi(A) ;
        i2 = vmaxi(B) ;
        if(*i1 >= *i2){
          A.erase(i1) ;
          B.erase(i2) ;
        }
        else{
          flag = false;
          break;
        }
      }
    }
  }
  if(flag){
    printf("YES\n") ;
  }
  else{
    printf("NO\n") ;
  }

  return 0;
}
