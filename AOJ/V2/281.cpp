#include<iostream>
#include<algorithm>
#include<string>
#include <time.h>
#include<vector>

using namespace std ;

int main()
{
  int N ,c,a,n ;
  vector< int > ans;
  cin >> N ;
  ans.assign( N, 0) ;
  for( int i = 0 ; i < N ; ++i )
  {
    cin >> c >> a >> n ;
    if(c <= a && c <= n)
    {
      ans[i] += c ;
      c = 0 ;
    }
    else if(a > n && c > n)
    {
      ans[i] += n ;
      c -= n ;
      a -= n ;
    }
    else if( n > a && c > a )
    {
      ans[i] += a ;
      c -= a ;
      a = 0 ;
    }
    if(a != 0)
    {
      if(a <= c / 2)
      {
        ans[i] += a ;
        c -= a * 2 ;
      }
      else
      {
        ans[i] += c / 2 ;
        c = 0 ;
      }
    }
    ans[i] += c / 3 ;
    cout << ans[i]<<endl;
  }
  return 0 ;
}
