#include <bits/stdc++.h>
using namespace std ;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  double b3,b2,b1;
  cin >> b1 >> b2 >> b3;
  std::cout << (int)(b3 + (b3-b2)*(b3-b2)/(b2-b1)) << std::endl;
  return 0;
}
