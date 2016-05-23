#include <bits/stdc++.h>
using namespace std ;

#define pb(n) push_back(n)
#define fi first
#define se second
#define all(r) (r).begin(),(r).end()
#define gsort(st,en) sort((st),(en),greater<int>())
#define vmax(ary) *max_element(all(ary))
#define vmin(ary) *min_element(all(ary))
#define debug(x) cout<<#x<<": "<<x<<endl
#define fcout(n) cout<<fixed<<setprecision((n))
#define scout(n) cout<<setw(n)
#define vary(type,name,size,init) vector< type> name(size,init)

#define rep(i,n) for(int i = 0; i < (int)(n);++i)
#define REP(i,a,b) for(int i = (a);i < (int)(b);++i)
#define repi(it,array) for(auto it = array.begin(),end = array.end(); it != end;++it)
#define repa(n,array) for(auto &n :(array))

using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using dict = map<string,int>;
using pii = pair<int,int> ;

constexpr int imax = ((1<<30)-1)*2+1 ;
constexpr int inf = 100000000;
constexpr double PI = acos(-1.0) ;
double eps = 1e-10 ;
const int dy[] = {-1,0,1,0};
const int dx[] = {0,-1,0,1};

inline bool value(int x,int y,int w,int h){
  return (x >= 0 && x < w && y >= 0 && y < h);
}

template<typename T>
void Unique(vector<T> &v){
  sort(all(v));
  v.erase(unique(all(v)),v.end());
}

template<typename T>
T ston(string& str, T n){
  istringstream sin(str) ;
  T num ;
  sin >> num ;
  return num ;
}

void Ans(bool f){
  if(f) cout << "YES"<<endl;
  else cout << "NO"<<endl;
}

struct Edge{
  int to;
  long long cost;
};

struct NODE{
  int pos;
  long long cost;
};
bool operator < (const NODE &a,const NODE &b){
  return a.cost > b.cost;
}
vector<Edge> g[100000],rg[100000];

int N;
const ll INF = 1e15;
vector<ll> dijkstra(vector<Edge> g[100000]){
  priority_queue<NODE> Q;
  Q.push({0,0});
  vector<ll> res(N,INF);
  while(Q.size()){
    NODE q= Q.top();Q.pop();
    if(res[q.pos] == INF){
      res[q.pos] = q.cost;
    }
    else{
      continue;
    }
    for(auto n : g[q.pos]){
      Q.push({n.to,q.cost+n.cost});
    }
  }
  return res;
}
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  string s;
  stringstream ss;
  int nodenum = 0,maxk=0,high=0;
  char c;
  vector<int> v[2000];
  while(getline(cin,s)){
    int k = count(all(s),',');
    if(maxk < k){
      maxk = k;
      high = nodenum;
    }
    string tmp = "";
    rep(i,s.size()){
      if(s[i] != ','){
        tmp += s[i];
      }
      else{
        v[nodenum].pb(ston(tmp,1));
        tmp.clear();
      }
    }
    v[nodenum].pb(ston(tmp,1));
    tmp.clear();
    nodenum++;
  }
  ++maxk;
  vector<vector<int>> v2(maxk,vector<int>(maxk+1,0));
  vector<vector<int>> dp(maxk,vector<int>(maxk+1,0));
  int j = 0,k=0,l =0;
  rep(i,maxk){
    j = 0;
    l = k;
    while(j<maxk){
      if(high >= l){
        v2[j][i] = v[l][v[l].size()-k-1];
      }
      else{
        v2[j][i] = v[l][maxk - k-1];
      }
      ++j;
      ++l;
    }
    ++k;
  }
  rep(i,maxk){
    rep(j,maxk){
//       cout << v2[j][i]<< " ";
      if(i+j == 0){
        dp[0][0] = v2[0][0];
      }
      if(j>0 && i>0){
        dp[j][i] = max(dp[j-1][i],dp[j][i-1])+v2[j][i];
      }
      else if(j == 0){
        dp[j][i] = dp[j][i-1]+v2[j][i];
      }
      else if(i == 0){
        dp[j][i] = dp[j-1][i]+v2[j][i];
      }
    }
//     cout << endl;
  }
  cout << dp[maxk-1][maxk-1]<<endl;
  return 0;
}
