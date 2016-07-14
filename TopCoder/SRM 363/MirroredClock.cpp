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

class MirroredClock {
    public:
    string whatTimeIsIt(string time) {
      auto vs = Split(time,":");
      auto s1 = vs[0],s2 = vs[1];
      auto n1 = ston(s1,1),n2 = ston(s2,1);
      if(n1 == 0 && n2 == 0) return time;
      n1 = 12 - n1;
      if(n2 != 0)
        --n1;
      n2 = 60 - n2;
      if(n2 == 60) n2 = 0;
      s1 = to_string(n1);
      s2 = to_string(n2);
      if(s1.size() == 1) s1 = "0" + s1;
      if(s2.size() == 1) s2 = "0" + s2;
        return s1 + ":"+s2;
    }
    template<typename T>
      T ston(string& str, T n){
        istringstream sin(str) ;
        T num ;
        sin >> num ;
        return num ;
      }
    vector<string> Split(const string& s,const string d){
      string item(s);
      vector<string> res(0);
      for(int pos = item.find(d); pos != string::npos; pos = item.find(d,pos)){
        item.replace(pos,d.size()," ");
      }
      stringstream buf(item);
      while(buf >> item){
        res.push_back(item);
      }
      return res;
    }
};

// CUT begin
ifstream data("MirroredClock.sample");

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

bool do_test(string time, string __expected) {
    time_t startClock = clock();
    MirroredClock *instance = new MirroredClock();
    string __result = instance->whatTimeIsIt(time);
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
        string time;
        from_stream(time);
        next_line();
        string __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(time, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1468483887;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 250 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
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
        cout << "MirroredClock (250 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
