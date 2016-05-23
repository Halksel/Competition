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
#define debugm(it) cout<<"fi "<<it->fi<<": "<<"se "<<it->se<<endl

#define rep(i,n) for(int i = 0; i < (n);++i)
#define repc(i,a,b) for(int i = (a);i <(b);++i)
#define repi(it,STL) for(auto it = STL.begin(); it != STL.end();++it)
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
T ston(string str){
  istringstream sin(str) ;
  T num ;
  sin >> num ;
  return num ;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int N, s, e, st,en ;
  char tmp ;
  bool flag = false ;
  vi begt, endt, ansb, anse ;
  map<int,int> m,temp, ans ;
  cin >> N ;
  rep(i,N){
    cin >> s >> tmp >> e ;
    s -= s % 5 ;
    e += (e%5 == 0)? 0 : 5 - (e % 5) ;
    if(m[s] < e){
      m[s] = e ;
    }
  }
  /*repi(it,m){
    cout << it->fi << "-" << it->se << endl;
  }*/
  //cout << "Sort is ended." << endl ;
  repi(it,m){
    repi(it2,m){
      if(it->se >= it2->fi){
        if(it->se < it2->se){
          temp[it->fi] = it2->se ;
        }
        else{
          temp[it->fi] = it->se ;
        }
      }
    }
  }
  repi(it,temp){
    if(it == temp.begin()){//初期値設定
      st = it->fi ;
      en = it->se ;
      ans[st] = en ;
    }
    if(it->fi > en)//雨がここで途切れる
    {
      ans[st] = en ;
      flag = true ;
    }
    if(flag){//途切れた後なら
      flag = !flag ;
      st = it->fi ;
      en = it->se ;
      ans[st] = en ;
    }
    else{
      if(it->se > en){
        en = it->se ;
        ans[st] = en ;
      }
    }
    //debug(st) ;
    //debug(en) ;
    //debugm(it) ;
  }
  repi(it,ans){
    string s1,s2 ;
    s1 = ntos(it->fi) ;
    s2 = ntos(it->se) ;
    while(s1.size() != 4){
      s1 = "0"+s1 ;
    }
    while(s2.size() != 4){
      s2 = "0"+s2 ;
    }
    cout << s1+"-"+s2 << endl;
  }
  return 0;
    }
