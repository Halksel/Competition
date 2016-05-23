#include<iostream>
#include<algorithm>
#include<string>
#include<cmath>
#include<iostream>
#include<vector>

using namespace std ;

  template <typename T>
T Out(vector < T > v,int n)
{
  if(n == 1)
  {
    for(int i = 0; i < v.size(); i++)
    {
      cout << v[i] << endl ;
    }
  }
  else if(n == 2)
  {
    for(int i = 0; i < v.size(); i++)
    {
      cout << v[i] ;
    }
    cout << endl ;
  }
  else
  {
    for(int i = 0; i < v.size(); i++)
    {
      cout << v[i] << " " ;
    }
    cout << endl ;
  }
}

int main()
{
  int N ;
  vector<int> a, b, ans ;
  while(1)
  {
    cin >> N ;
    if(N == 0)
    {
      break ;
    }
    for(int h = 0; h < N ;++h)
    {
      a.resize(4) ;
      b.resize(4) ;
      ans.clear() ;
      ans.resize(4) ;
      for(int i = 0; i < 4; ++i)
      {
        cin >> a[i] ;
      }
      for(int i = 0; i < 4; ++i)
      {
        cin >> b[i] ;
      }
      for(int i = 0; i < 4;++i)
      {
        for(int j = 0; j < 4; ++j)
        {
          if(i == j && i != 0)
          {
            ans[0] -= a[i] * b[j] ;
          }
          else if(i == j && i == 0)
          {
            ans[0] += a[i] * b[j] ;
          }
          else if(i == 0)
          {
            ans[j] += a[i] * b[j] ;
          }
          else if(j == 0)
          {
            ans[i] += a[i] * b[j] ;
          }//
          else if(i == 1 && j == 2)
          {
            ans[3] += a[i] * b[j] ;
          }
          else if(i == 1 && j == 3)
          {
            ans[2] -= a[i] * b[j] ;
          }
          else if(i == 2 && j == 1)
          {
            ans[3] -= a[i] * b[j] ;
          }
          else if(i == 2 && j == 3)
          {
            ans[1] += a[i] * b[j] ;
          }
          else if(i == 3 && j == 1)
          {
            ans[2] += a[i] * b[j] ;
          }
          else if(i == 3 && j == 2)
          {
            ans[1] -= a[i] * b[j] ;
          }
        }
      }
      for(int i = 0; i < 4;++i){
        if(i){
          cout << " ";
        }
        cout << ans[i];
      }
      cout << endl;
    }
  }
  return 0 ;
}
