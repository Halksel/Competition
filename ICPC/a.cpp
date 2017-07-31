#include<bits/stdc++.h>

using namespace std;

#define int long long

signed main(){
  int n,m;
  while(cin >> n >> m,n + m){
    vector<int> v(n);
    for(int i = 0; i < n;++i){
      cin >> v[i];
    }
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    int ans = -1;
    for(int i = 0; i < n;++i){
      for(int j = i + 1; j < n;++j){
        if(v[i] + v[j] <= m){
          ans = max(ans,v[i]+v[j]);
        }
      }
    }
    if(ans == -1){
      cout << "NONE" << endl;
    }
    else
      cout << ans << endl;
  }
  return 0;
}
