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

template<typename T>
T ston(string& str, T n){
  istringstream sin(str) ;
  T num ;
  sin >> num ;
  return num ;
}
#define rep(i,n) for(int i = 0; i < (int)(n);++i)
class BrokenButtons {
  string nb = "";
  public:
  int minPresses(int page, vector<int> broken) {
    if(page == 100){
      return 0;
    }
    int mi = abs(page-100),res = -1;
    string p = to_string(page),ans;
    rep(i,10){
      if(find(broken.begin(),broken.end(),i) == broken.end()){
        nb += to_string(i);
      }
    }
    if(pushable(page)){
      return min(mi,(int)to_string(page).size()) ;
    }
    rep(i,1000000){
      if(pushable(i)){
        if(mi > abs(page-i)){
          mi = abs(page-i);
          res = i;
        }
      }
    }
    return min(abs(page-100),mi+(int)to_string(res).size());
  }
  bool pushable(int n){
    string s = to_string(n);
    rep(i,s.size()){
      if(find(nb.begin(),nb.end(),s[i]) == nb.end()){
        return false;
      }
    }
    return true;
  }
};

// CUT begin
ifstream data("BrokenButtons.sample");

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

bool do_test(int page, vector<int> broken, int __expected) {
  time_t startClock = clock();
  BrokenButtons *instance = new BrokenButtons();
  int __result = instance->minPresses(page, broken);
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
    int page;
    from_stream(page);
    vector<int> broken;
    from_stream(broken);
    next_line();
    int __answer;
    from_stream(__answer);

    cases++;
    if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
      continue;

    cout << "  Testcase #" << cases - 1 << " ... ";
    if ( do_test(page, broken, __answer)) {
      passed++;
    }
  }
  if (mainProcess) {
    cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
    int T = time(NULL) - 1457678343;
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
    cout << "BrokenButtons (500 Points)" << endl << endl;
  }
  return run_test(mainProcess, cases, argv[0]);
}
// CUT end
