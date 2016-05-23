#include<iostream>
#include<algorithm>
#include<string>
#include<cmath>
#include<iostream>
#include<vector>

using namespace std ;

int vtonum(vector<int> v )
{
  int num = 0 ,base = 10 ;
  for(int i = 0; i < v.size(); ++i)
  {
    if(i == 0)
    {
      num += v[i] ;
    }
    else
    {
      num += v[i] * (base) ;
      base *= 10 ;
    }
  }
  return num ;
}

int main()
{
  int N,L,S,ans,d, i = 0;
  vector<int> v ;
  while(1)
  {
    cin >> N ;
    ans = 0 ;
    if(N == 0)
    {
      break ;
    }
    while(1)
    {
      if(N == 6174)
      {
        cout << ans << endl ;
        break ;
      }
      v.resize(4) ;
      i = 0 ;
      for(d = 1000; d >= 1; d /= 10)
      {
        v[i] = N /d ;
        N %= d ;
        ++i ;
      }
      if(v[0] == v[1] && v[1] == v[2] && v[2] == v[3])
      {
        cout << "NA" << endl ;
        break ;
      }
      std::sort(v.begin(),v.end()) ;
      S = vtonum(v) ;
      std::sort(v.begin(),v.end(),std::greater<int>()) ;
      L = vtonum(v) ;
      N = S - L ;
      ++ans ;
    }
  }
  return 0 ;
}
