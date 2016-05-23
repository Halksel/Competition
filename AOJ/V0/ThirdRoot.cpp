#include<iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
  double num, x0, x1 ;//変数宣言
  while(cin >> num)//処理開始
  {
    if(num == -1) break;
    else{
      x0 = num/2.0 ;//初期値
      while(1){
        x1 = x0 - (pow(x0,3.0)-num)/(3*pow(x0,2.0)) ;//ニュートン法
        if(abs(pow(x1,3.0)-num)< 0.00001*num)//収束条件確認
        {
          break ;
        }
        x0 = x1 ;//満たしていない場合次の計算の準備
      }
      cout<<fixed<<setprecision(8)<< x1 <<endl;
    }
  }
  return 0 ;
}
