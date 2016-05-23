#include <cstdio>
#include <bits/stdc++.h>
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
#include <queue>

using namespace std;

template<typename T>
T ston(string& str, T n){
  istringstream sin(str) ;
  T num ;
  sin >> num ;
  return num ;
}
#define rep(i,n) for(int i = 0; i < (int)(n);++i)
#define REP(i,a,b) for(int i = (a);i < (int)(b);++i)
int dp[1<<21];
class SumOfSelectedCells {
  int W;
    public:
    vector<vector<int>> tables;
    bool solve(int sum, int state,int k,vector<vector<int>> &table){
      if(dp[state]){
        if(dp[state] != sum){
          return false;
        }
        return true;
      }
      dp[state] =sum;
      if(k >= W) return true;

      bool res = true;
      rep(i,W){
        if(!(state & (1 << i))){
          res &= solve(sum+table[k][i],state | (1 << i),k+1,table);
        }
      }
      return res;
    }
    string hypothesis(vector<string> table) {
      tables.resize(table.size());
      rep(i,table.size()){
        tables[i] = split(table[i]);
      }
      W = tables.size();
      if(!solve(0,0,0,tables)) return string("INCORRECT");
      int a = -1;
      rep(i,(1 <<tables[0].size())){
        int cnt = 0;
        rep(j,tables[0].size()){
          if( i & ( 1 << j)){
            ++cnt;
          }
        }
        if(cnt == W){
          if(a < 0){
            a = dp[i];
          }
          if(a != dp[i]){
            return "INCORRECT";
          }
        }
      }
      return "CORRECT";
    }
    vector<int> split(string s){
      vector<int> n;
      string s2;
      rep(i,s.size()){
        if(s[i] == ' '){
          n.push_back(ston(s2,1));
          s2.clear();
        }
        else s2 += s[i];
      }
      n.push_back(ston(s2,1));
      return n;
    }
};

// CUT begin
ifstream data("SumOfSelectedCells.sample");

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

bool do_test(vector<string> table, string __expected) {
    time_t startClock = clock();
    SumOfSelectedCells *instance = new SumOfSelectedCells();
    string __result = instance->hypothesis(table);
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
        vector<string> table;
        from_stream(table);
        next_line();
        string __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(table, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1459486057;
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
        cout << "SumOfSelectedCells (500 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
