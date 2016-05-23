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
string calc(string s1,string s2){
  string ans;
  ans = string(105,' ') ;
  int a,b,c = 0;
  bool f = s1.size() >= s2.size();
  for(int i = 0;i <min(s1.size(),s2.size());++i){
    if(f){
      a = s1[s1.size()-1-i] - '0' ;
      b = s2[s2.size()-1-i] - '0' ;
    }
    else{
      a = s1[s1.size()-1-i] - '0' ;
      b = s2[s2.size()-1-i] - '0' ;
    }
    //       debug((a+b+c)%10+'0');
    ans[ans.size()-1-i] = (a+b+c)%10+'0';
    c = (a+b+c)/10;
    //       cout << ans.size()-1-i << " :" << a << " :" << b << " :" << c <<endl;
  }
  for(int i = min(s1.size(),s2.size()); i < max(s1.size(),s2.size());++i){
    if(f){
      ans[ans.size()-1-i] = (s1[s1.size()-1-i] - '0' + c)%10+'0';
      c = (s1[s1.size()-1-i] - '0' + c )/10;
    }
    else{
      ans[ans.size()-1-i] = (s2[s2.size()-1-i] + c - '0')%10+'0';
      c = (s2[s2.size()-1-i] + c - '0')/10;
    }
  }
  if(c > 0){
    //       cout << ans << "c :"<<  c << endl;
    ans[0] = c +'0' ;
  }
  if(ans.size()-count(all(ans),' ') > 80){
    cout << "overflow" << endl;
    return "";
  }
  for(size_t c = ans.find_first_of(" "); c != string::npos; c = ans.find_first_of(" ")){
    ans.erase(c,1);
  }
  return ans;
}
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  string line;
  string s1;
  while(cin >> line){
    vector<string> v(3);
    vector<string> vs(3);
    int cnt = 0;
    string tmp ="";
    rep(i,line.size()){
      if(line[i] == '+' || line[i] == '='){
        vs[cnt] = tmp;
        cnt++;
        tmp.clear();
      }
      else{
        tmp+=line[i];
      }
    }
    vs[cnt] = tmp;
    cnt++;
    tmp.clear();
    bool f = false;
    if(!((vs[0][0] == 'X' && vs[0].size() >1) || (vs[2][0] == 'X' &&vs[2].size()>1 ) || (vs[1][0] == 'X'&&vs[1].size() > 1))){
      tmp = vs[0];
      for(auto p=0; (p=tmp.find("X",p))!=-1;){
        tmp.replace(p,1,"0");
      }
      v[0] = tmp;
      tmp = vs[1];
      for(auto p=0; (p=tmp.find("X",p))!=-1;){
        tmp.replace(p,1,"0");
      }
      v[1] = tmp;
      tmp = vs[2];
      for(auto p=0; (p=tmp.find("X",p))!=-1;){
        tmp.replace(p,1,"0");
      }
      v[2] = tmp;
      if(calc(v[0],v[1]) == v[2]){
        f = true;
        cout << 0 << endl;
      }
    }
    if(!f){
      REP(i,1,10){
        tmp = vs[0];
        for(auto p=0; (p=tmp.find("X",p))!=-1;){
          tmp.replace(p,1,to_string(i));
        }
        v[0] = tmp;
        tmp = vs[1];
        for(auto p=0; (p=tmp.find("X",p))!=-1;){
          tmp.replace(p,1,to_string(i));
        }
        v[1] = tmp;
        tmp = vs[2];
        for(auto p=0; (p=tmp.find("X",p))!=-1;){
          tmp.replace(p,1,to_string(i));
        }
        v[2] = tmp;
        if(calc(v[0],v[1])== v[2]){
          f = true;
          cout << i << endl;
          break;
        }
      }
    }
    if(!f) cout << "NA"<<endl;
  }
  return 0;
}
