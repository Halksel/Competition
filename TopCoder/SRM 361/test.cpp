#include <bits/stdc++.h>
using namespace std ;

#define pb(n) push_back(n)
#define fi first
#define se second
#define all(r) (r).begin(),(r).end()
#define vmax(ary) *max_element(all(ary))
#define vmin(ary) *min_element(all(ary))
#define debug(x) cout<<#x<<": "<<x<<endl
#define fcout(n) cout<<fixed<<setprecision((n))
#define scout(n) cout<<setw(n)
#define vary(type,name,size,init) vector< type> name(size,init)
#define vvl(v,w,h,init) vector<vector<ll>> v(w,vector<ll>(h,init))
#define mp(a,b) make_pair(a,b)

#define rep(i,n) for(int i = 0; i < (int)(n);++i)
#define REP(i,a,b) for(int i = (a);i < (int)(b);++i)
#define repi(it,array) for(auto it = array.begin(),end = array.end(); it != end;++it)
#define repa(n,array) for(auto &n :(array))

using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using dict = map<string,int>;
using pii = pair<int,int> ;
using pll = pair<ll,ll> ;

const int mod = 1000000007;
constexpr int inf = ((1<<30)-1)*2+1 ;
constexpr double PI = acos(-1.0) ;
double eps = 1e-10 ;
const int dy[] = {-1,0,1,0,1,-1,1,-1};
const int dx[] = {0,-1,0,1,1,-1,-1,1};

inline bool value(int x,int y,int w,int h){
  return (x >= 0 && x < w && y >= 0 && y < h);
}

template<typename T>
void Unique(vector<T> &v){
  sort(all(v));
  v.erase(unique(all(v)),v.end());
}
template<typename T,typename U>
ll FindErase(T &v,U tar){
  ll cnt = 0;
  for(auto it = v.begin(); it != v.end();){
    if(*it == tar){
      it = v.erase(it);
      ++cnt;
    }
    else{
      ++it;
    }
  }
  return cnt;
}

template<typename T>
bool SuffixErase(T &v,size_t suf){
  if(suf > v.size()) return false;
  for(auto it = v.begin(); it != v.end();){
    if(distance(v.begin(),it) == suf){
      v.erase(it);
      return true;
    }
    else{
      ++it;
    }
  }
  return false;
}

template<typename T>
T ston(string& str, T n){
  istringstream sin(str) ;
  T num ;
  sin >> num ;
  return num ;
}

class SearchBox {
  int ans;
    public:
    int find(string text, string search, string wholeWord, int start) {
      string tmp = text;
      int f = 0;
      int cnt = 0;
      int spc = 0;
      if(wholeWord == "Y"){
        text = " " + text;
        text += " ";
        for(int i = start+1; i < text.size(); ++ i){
          if(text[i] == search[0]){
            for(int j = 0; j < search.size() ++ j){
              if(text[i+j] != search[j]){
                break;
              }
              if(j == search.size()-1 && text[i+j+1] == ' ' && text[i-1] == ' '){
                return i;
              }
            }
          }
        }
        return -1;
      }
      else{
        text = text.substr(start);
        if(text.find(search) != string::npos){
          ans = text.find(search);
          return ans + start;
        }
        return -1;
      }
    }
    vector<string> Split(const string& s,const string d){
      string item(s);
      vector<string> res(0);
      for(int pos = item.find(d); pos != string::npos; pos = item.find(d,pos)){
        item.replace(pos,d.size(),"@");
      }
      string k = "@";
      for(int pos = item.find(k); pos != string::npos; pos = item.find(k,pos)){
        item.replace(pos,k.size()," ");
      }
      stringstream buf(item);
      while(buf >> item){
        res.push_back(item);
      }
      return res;
    }
};
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  string s,s2,s3;
  int n;
  cin >> s >> s2 >> s3 >> n;
  SearchBox S;
  cout << S.find(s,s2,s3,n) << endl;
  return 0;
}
