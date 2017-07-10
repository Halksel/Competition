#include <bits/stdc++.h>

using namespace std;

using ll = long long;
#define rep(i,n) for(int i = 0; i < n ;++i)
#define all(v) v.begin(),v.end()

string s[100];
int w,h;
int dx[2]={0,1};
int dy[2]={1,0};
bool used[100][100];
string ans[100][100];

bool check(string s,string t){
  if(s.size()!=t.size())return s.size()>t.size();
  return s>t;
}

int main(){
    while(cin>>w>>h&&w+h){
      //vs.clear();
      rep(i,100)rep(j,100)ans[i][j].clear();
        rep(i,h)cin>>s[i];
        rep(i,h)rep(j,w){
          string t="";
          t+=s[i][j];
          //if(i==0&&j==0){
            if(s[i][j]>='1'&&s[i][j]<='9')ans[i][j]=t;
          //}
        }
        // rep(i,h){
        //   rep(j,w){
        //     cout<<ans[i][j]<<" ";
        //   }
        //   cout<<endl;
        // }
        //rep(i,h)rep(j,w)used[i][j]=0;
        string ret="";
        rep(i,h){
          rep(j,w){
            if(ans[i][j].empty())continue;
            if(i+1<h&&s[i+1][j]>='0'&&s[i+1][j]<='9'){
              ans[i+1][j]=ans[i][j]+s[i+1][j];
            }
            if(j+1<w&&s[i][j+1]>='0'&&s[i][j+1]<='9'){
              if(check(ans[i][j]+s[i][j+1],ans[i][j+1])){
                ans[i][j+1]=ans[i][j]+s[i][j+1];
              }
            }
          }
        }
        rep(i,h){
          rep(j,w){
          if(ans[i][j].size()>ret.size()){
              ret=ans[i][j];
          }
          else if(ans[i][j].size()==ret.size()){
            if(ret<ans[i][j])ret=ans[i][j];
          }
          // cout<<ans[i][j]<<" ";
          }
          // cout<<endl;
        }
        // sort(all(vs),F);
        // reverse(all(vs));
        // cout<<vs[0]<<endl;
        cout<<ret<<endl;
    }
}
