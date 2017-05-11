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
#define rep(i,n) for(int i = 0; i < (int)(n);++i)
using ll = long long;

using namespace std;
class Union_Find{
  public:
  Union_Find(){};
  static const ll MAX_N = 100000*2+1;
  int par[MAX_N];
  int ranks[MAX_N];
  int cost[MAX_N];
  void init(int n){
    rep(i,MAX_N){
      par[i] = i;
      ranks[i] = 0;
      cost[i] = 1;
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
    if(a == b) return;
    if(ranks[a] < ranks[b]){
      par[a] = b;
    }
    else{
      par[b] = a;
      cost[a] += cost[b];
      if(ranks[a] == ranks[b]) ranks[a]++;
    }
  }
  bool same(int a,int b){
    return find(a) == find(b);
  }
};
class Permatchd2 {
    public:
    int fix(vector<string> graph) {
      Union_Find u;
      u.init(0);
      int x = graph[0].size(),y = graph.size();
      int cnt = 0,ans = 0;
      rep(j,y){
        rep(i,x){
          if(graph[j][i] == 'Y'){
            u.Unite(i,j);
            ++cnt;
          }
        }
      }
      cnt /= 2;
      if(cnt % 2 && cnt == x) return -1;
      while(1){
        rep(i,x){
          cout << i << ' ' << u.find(i) << endl;
        }
        rep(i,x){
          rep(j,x){
            if(!u.same(i,j)){
              u.Unite(i,j);
              ++cnt;
              ++ans;
              i = x;
              break;
            }
          }
        }
        rep(i,x){
          cout << i << ' ' << u.find(i) << endl;
        }
        bool f = true;
        int a = u.find(0);
        rep(i,x){
          if(a != u.find(i)){
            f = false;
          }
        }
        if(f) break;
      }
      cout << cnt << ' ' << ans << endl;
      if(cnt % 2 && cnt == x) return -1;
      if(cnt % 2) ++ans;
      return ans;
    }
};

// CUT begin
ifstream data("Permatchd2.sample");

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

bool do_test(vector<string> graph, int __expected) {
    time_t startClock = clock();
    Permatchd2 *instance = new Permatchd2();
    int __result = instance->fix(graph);
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
        vector<string> graph;
        from_stream(graph);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(graph, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1487693606;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 500 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
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
        cout << "Permatchd2 (500 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
