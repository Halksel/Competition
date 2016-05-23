#include<iostream>
#include <algorithm>
#include <string>

using namespace std ;

int main()
{
  vector< int > hand ;
  char arg ;
  int N ,player, field;
  while(1)
  {
    hand.clear() ;
    player = 0 ;
    field = 0 ;
    cin >> N ;
    hand.assign(N,0) ;
    if(N == 0)
    {
      break ;
    }
    for(int i = 0; i < 100; ++i)
    {
      cin >> arg ;
      if(arg == 'S')
      {
        field += (hand.at( player ) + 1 );
        hand.at( player ) = 0 ;
      }
      if(arg == 'M')
      {
        ++hand.at( player ) ;
      }
      if(arg == 'L')
      {
        hand.at(player) += (field + 1) ;
        field = 0 ;
      }
      ++player ;
      if(player == N )
      {
        player = 0 ;
      }
    }
    sort(hand.begin(),hand.end()) ;
    for(int i = 0; i < N ; ++i)
    {
      cout << hand.at( i ) << " " ;
    }
    cout << field << endl ;
  }

  return 0 ;
}
