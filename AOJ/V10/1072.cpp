#include <bits/stdc++.h>
using namespace std ;
int main(){
  int r,c;
  while(cin >> r >> c && r + c){
    if(r*c%2) cout << "no" << endl;
    else cout << "yes" << endl;
  }
}
