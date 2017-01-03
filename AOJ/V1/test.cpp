#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  int a[11111], sum=0, n;

  cin>>n;

  for(int i=0;i<n;i++)
    cin>>a[i];

  sort(a, a+n-1);

  for(int i=0;i<n-1;i++){
    for(int j=0;j<=i;j++){
      sum+=a[j];
    }
  }

  cout<<sum<<endl;
  return 0;
}
