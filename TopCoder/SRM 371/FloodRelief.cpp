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

#define rep(i,n) for(int i = 0; i < (int)(n);++i)
#define REP(i,a,b) for(int i = (a);i < (int)(b);++i)
#define repi(it,array) for(auto it = array.begin(),end = array.end(); it != end;++it)
#define repa(n,array) for(auto &n :(array))
const int dy[] = {-1,0,1,0,1,-1,1,-1};
const int dx[] = {0,-1,0,1,1,-1,-1,1};

using ll = long long;

class FloodRelief {
  vector<string> s;
  int h,w,ans;
    public:
    int minimumPumps(vector<string> heights) {
      h = heights.size(),w = heights[0].size(),ans = 0;
      s = heights;
      d.resize(h);
      rep(i,h){
        d[i].resize(w);
        rep(j,w){
          d[i][j] = -1;
        }
      }
      rep(i,26){
        char c = i + 'a';
        rep(j,h){
          rep(k,w){
            if(heights[j][k] == c && d[j][k] == -1){
              dfs(j,k,ans);
              ++ans;
            }
          }
        }
      }
      rep(j,h){
        rep(k,w){
          cout << d[j][k] ;
        }
        cout << endl;
      }

      return ans;
    }
    void dfs(int y,int x,int g){
      if(d[y][x] != -1) return;
      d[y][x] = g;
      rep(i,4){
        int nx = x + dx[i],ny = y + dy[i];
        if(value(nx,ny,w,h) && s[ny][nx] >= s[y][x]){
          dfs(ny,nx,g);
        }
      }
    }
    vector<vector<int>> d;
};

// CUT begin
ifstream data("FloodRelief.sample");

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

template <typename T> void from_stream(vector<T> &ts) {
    int len;
    from_stream(len);
    ts.clear();
    for (int i = 0; i < len; ++i) {
        T t;
        from_stream(t);
        ts.push_back(t);
    }
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

bool do_test(vector<string> heights, int __expected) {
    time_t startClock = clock();
    FloodRelief *instance = new FloodRelief();
    int __result = instance->minimumPumps(heights);
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
        vector<string> heights;
        from_stream(heights);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(heights, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1488520145;
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
        cout << "FloodRelief (1000 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
