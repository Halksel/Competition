#include <cstdio>
#include <cmath>
#include <cstring>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <sstream>
#include <typeinfo>
#include <fstream>

using namespace std;

int dp[51][51];

#define pb(n) push_back(n)
#define fi first
#define se second
#define X real()
#define Y imag()
#define value(x,y,w,h) (x >= 0 && x < w && y >= 0 && y < h)
#define all(r) (r).begin(),(r).end()
#define gsort(st,en) sort((st),(en),greater<int>())
#define vmax(ary) *max_element(all(ary))
#define vmin(ary) *min_element(all(ary))
#define debug(x) cout<<#x<<": "<<x<<endl
#define fcout(n) cout<<fixed<<setprecision((n))
#define scout(n) cout<<setw(n)
#define vary(type,name,size,init) vector< type> name(size,init)

#define rep(i,a,b) for(int i = (a); i < (int)(b);++i)
#define repi(it,array) for(auto it = array.begin(),end = array.end(); it != end;++it)
#define repa(n,array) for(auto &n :(array))

using ll = long long;

constexpr int imax = ((1<<30)-1)*2+1 ;
constexpr int inf = 100000000;
constexpr double PI = acos(-1.0) ;
double eps = 1e-10 ;
const int dy[] = {-1,0,1,0,1,-1,1,-1};
const int dx[] = {0,-1,0,1,1,-1,-1,1};
class RainyDay {
  string f,p;
  int yp,hp;
    public:
    int minimumRainTime(string path, string forecast) {
      p = path,f = forecast;
      rep(i,0,p.size()){
        if(p[i] == 'Y'){
          yp = i;
          p[i] = 'C';
        }
        if(p[i] == 'H'){
          hp = i;
          p[i] = 'C';
        }
      }
      path = p;
      rep(i,0,51){
        rep(j,0,51){
          dp[i][j] = inf;
        }
      }
      dp[yp][0] = 0;
      int k = path.size();
      if(yp < hp){
        rep(i,yp,k){
          rep(t,0,k*2){
            dp[i][(t+1)%k] = min(dp[i][t%k]+cost(i,t%k),dp[i][(t+1)%k]);
            if(i == 4){
              cout<<cost(i, t%k)<<" "<<dp[i][t%k]<<endl;
            }
          }
          rep(t,0,k){
            dp[i+1][(t+1)%k] = min(dp[i][t]+cost(i+1,t),dp[i+1][(t+1)%k]);
          }
        }
        int ans = inf;
        rep(i,0,k){
          ans = min(ans,dp[hp][i]);
        }
        cout << endl;
        rep(i,0,k){
          rep(j,0,k){
            cout << dp[i][j] << ' ';

          }
          cout << endl;
        }
        return ans;
      }
      else{
        for(int i = yp; i > 0; --i){
          rep(t,0,k){
            dp[i][(t+1)%k] = min(dp[i][t]+cost(i,t),dp[i][(t+1)%k]);
          }
          rep(t,0,k){
            dp[i-1][(t+1)%k] = min(dp[i][t]+cost(i-1,t),dp[i-1][(t+1)%k]);
          }
        }
        int ans = inf;
        rep(i,0,k){
          ans = min(ans,dp[hp][i]);
        }
        return ans;
      }
    }
    int cost(int i,int t){
      int n = p.size();
      int ret = 0;
      if(p[i] != 'C' && f[(t+1+i)%n] == 'R'){
        ++ret;
      }
      if(p[i] != 'C' && f[(t+2+i)%n] == 'R')++ret;
      return ret;
    }
};

// CUT begin
ifstream data("RainyDay.sample");

string next_line() {
    string s;
    getline(data, s);
    return s;
}

template <typename T> void from_stream(T &t) {
    stringstream ss(next_line());
    ss >> t;
}

void from_stream(string &s) {
    s = next_line();
}

template <typename T>
string to_string(T t) {
    stringstream s;
    s << t;
    return s.str();
}

string to_string(string t) {
    return "\"" + t + "\"";
}

bool do_test(string path, string forecast, int __expected) {
    time_t startClock = clock();
    RainyDay *instance = new RainyDay();
    int __result = instance->minimumRainTime(path, forecast);
    double elapsed = (double)(clock() - startClock) / CLOCKS_PER_SEC;
    delete instance;

    if (__result == __expected) {
        cout << "PASSED!" << " (" << elapsed << " seconds)" << endl;
        return true;
    }
    else {
        cout << "FAILED!" << " (" << elapsed << " seconds)" << endl;
        cout << "           Expected: " << to_string(__expected) << endl;
        cout << "           Received: " << to_string(__result) << endl;
        return false;
    }
}

int run_test(bool mainProcess, const set<int> &case_set, const string command) {
    int cases = 0, passed = 0;
    while (true) {
        if (next_line().find("--") != 0)
            break;
        string path;
        from_stream(path);
        string forecast;
        from_stream(forecast);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(path, forecast, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1488525361;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 1000 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(2);
    set<int> cases;
    bool mainProcess = true;
    for (int i = 1; i < argc; ++i) {
        if ( string(argv[i]) == "-") {
            mainProcess = false;
        } else {
            cases.insert(atoi(argv[i]));
        }
    }
    if (mainProcess) {
        cout << "RainyDay (1000 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
