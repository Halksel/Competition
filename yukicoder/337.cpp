#include<iostream>

using namespace std;

int main(){
  int a,b;
  std::cin >> a >> b;
  std::cout << ((b == b*a) ? "=" : "!=")<<std::endl;
}
