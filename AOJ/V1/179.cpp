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

const int mod = 1000000007;
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

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  string s;
  while(cin >> s && s!= "0"){
    set<string> st;
    queue<string> q;
    q.push(s);
    int num = 0;
    int flag = 0;
    while(1){
      auto n = q.size();
      rep(i,n){
        auto el = q.front();q.pop();
//         debug(el);
        if(st.insert(el).se){
          auto el2 = el;
          bool f = true;
          rep(j,el.size()){
            if(el[0] != el[j]){
              f = false;
              break;
            }
          }
          if(f){
            flag = 2;
            break;
          }
          rep(j,el.size()-1){
            el = el2;
            if(el[j] != el[j+1]){
              if(el[j] != 'g' && el[j+1] != 'g'){
                el[j] = 'g';
                el[j+1] = 'g';
              }
              else if(el[j] != 'r' && el[j+1] != 'r'){
                el[j] = 'r';
                el[j+1] = 'r';
              }
              else{
                el[j] = 'b';
                el[j+1] = 'b';
              }
              q.push(el);
            }
          }
        }
      }
      if(!q.size() && flag != 2){
        cout << "NA" <<endl;
        break;
      }
      else if(flag == 2){
        cout << num <<endl;
        break;
      }
      ++num;
    }
  }
  return 0;
}
