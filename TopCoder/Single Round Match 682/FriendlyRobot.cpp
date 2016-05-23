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
using namespace std;

class FriendlyRobot {
  int udlr[4] ={},maxud,maxlr;
  char list[4] = {'U','D','L','R'};
  public:
  int findMaximumReturns(string instructions, int changesAllowed) {
    string str = instructions;
    int change = 0,change2 = 0;
      for(int j = 0; j < str.size()-1; j += 2){
        if(changesAllowed > change){
          if(str[j] == 'U' && str[j+1] != 'D'){
            ++change;
          }
          if(str[j] == 'D' && str[j+1] != 'U'){
            ++change;
          }
          if(str[j] == 'R' && str[j+1] != 'L'){
            ++change;
          }
          if(str[j] == 'L' && str[j+1] != 'R'){
            ++change;
          }
        }
        if(str[j] == 'U' && str[j+1] == 'D'){
          ++change;
        }
        if(str[j] == 'D' && str[j+1] == 'U'){
          ++change;
        }
        if(str[j] == 'R' && str[j+1] == 'L'){
          ++change;
        }
        if(str[j] == 'L' && str[j+1] == 'R'){
          ++change;
        }
      }
      for(int j = 0; j < str.size()-1; j += 2){
        if(changesAllowed > change){
          if(str[j] == 'U' && str[j+1] != 'D'){
            ++change;
          }
          if(str[j] == 'D' && str[j+1] != 'U'){
            ++change;
          }
          if(str[j] == 'R' && str[j+1] != 'L'){
            ++change;
          }
          if(str[j] == 'L' && str[j+1] != 'R'){
            ++change;
          }
        }
        if(str[j] == 'U' && str[j+1] == 'D'){
          ++change;
        }
        if(str[j] == 'D' && str[j+1] == 'U'){
          ++change;
        }
        if(str[j] == 'R' && str[j+1] == 'L'){
          ++change;
        }
        if(str[j] == 'L' && str[j+1] == 'R'){
          ++change;
        }
      }
    return 0;
  }
};

// CUT begin
ifstream data("FriendlyRobot.sample");

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

bool do_test(string instructions, int changesAllowed, int __expected) {
    time_t startClock = clock();
    FriendlyRobot *instance = new FriendlyRobot();
    int __result = instance->findMaximumReturns(instructions, changesAllowed);
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
        string instructions;
        from_stream(instructions);
        int changesAllowed;
        from_stream(changesAllowed);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(instructions, changesAllowed, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1456194831;
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
        cout << "FriendlyRobot (1000 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
