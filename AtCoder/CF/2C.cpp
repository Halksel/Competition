#include <bits/stdc++.h>
using namespace std ;

#define debug(x) cout<<#x<<": "<<x<<endl

#define rep(i,n) for(int i = 0; i < (int)(n);++i)
#define REP(i,k,n) for(int i = k; i < (int)(n);++i)
#define all(v) v.begin(),v.end()

using ll = long long;
using pll = pair<ll,ll>;

class Union_Find{
  public:
  Union_Find(){};
  static const ll MAX_N = 100000*2+1;
  int par[MAX_N];
  int ranks[MAX_N];
  void init(int n){
    rep(i,MAX_N){
      par[i] = i;
      ranks[i] = 0;
    }
  }
  int find(int x){
    if(par[x] == x){
      return x;
    }
    else{
      return par[x] = find(par[x]);
    }
  }

  void Unite(int a, int b){
    a = find(a);
    b = find(b);
    if(a == b) return ;
    if(ranks[a] < ranks[b]){
      par[a] = b;
    }
    else{
      par[b] = a;
      if(ranks[a] == ranks[b]) ranks[a]++;
    }
  }
  bool same(int a,int b){
    return find(a) == find(b);
  }
};

struct edge{ll u, v, cost,i;};

bool comp(const edge& e1,const edge& e2){
  return e1.cost < e2.cost;
}

vector<edge> p(100000*2+1);
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll w,h,a,b,k;
  cin >> w >> h;
  rep(i,w+h){
    cin >> k;
    if(i < w){
      p[i] = edge{i,i+1,k,0};
    }
    else
      p[i] = edge{i - w,i+1 - w,k,1};
  }
  sort(all(p),comp);
  a = w+1,b = h+1;
  k = 0;
  Union_Find W,H;
  W.init(a),H.init(b);
  rep(i,p.size()){
      if(p[i].i && !W.same(p[i].u,p[i].v)){
      k += p[i].cost * a;
      W.Unite(p[i].u,p[i].v);
      --b;
    }
    else if(!p[i].i && !H.same(p[i].u,p[i].v)){
      k += p[i].cost * b;
      H.Unite(p[i].u,p[i].v);
      --a;
    }
  }
  cout << k << endl;
  return 0;
}
