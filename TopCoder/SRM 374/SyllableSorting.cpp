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
vector<string> Split(const string& s){
  vector<string> res(0);
  string t;
  int k = 0;
  for (auto&& n : s) {
    if((n == 'a' || n == 'i' || n == 'u' || n == 'e' || n == 'o')){
      ++k;
      t += n;
    }
    else{
      if(k != 0){
        res.push_back(t);
        k = 0;
        t.clear();
      }
      t += n;
    }
  }
  res.push_back(t);
  return res;
}

bool comp(const string& a,const string& b){
  vector<string> as,bs,e,d;
  as = Split(a); bs = Split(b); e = as; d = bs;
  sort(as.begin(),as.end());
  sort(bs.begin(),bs.end());
  if(as == bs){
    return e<d;
  }
  return as<bs;
}

class SyllableSorting {
    public:
    vector<string> sortWords(vector<string> words) {
      sort(words.begin(),words.end(),comp);
      return words;
    }
};

// CUT begin
ifstream data("SyllableSorting.sample");

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

template <typename T> string to_string(vector<T> ts) {
    stringstream s;
    s << "[ ";
    for (int i = 0; i < ts.size(); ++i) {
        if (i > 0) s << ", ";
        s << to_string(ts[i]);
    }
    s << " ]";
    return s.str();
}

bool do_test(vector<string> words, vector<string> __expected) {
    time_t startClock = clock();
    SyllableSorting *instance = new SyllableSorting();
    vector<string> __result = instance->sortWords(words);
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
        vector<string> words;
        from_stream(words);
        next_line();
        vector<string> __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(words, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1491531519;
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
        cout << "SyllableSorting (500 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
