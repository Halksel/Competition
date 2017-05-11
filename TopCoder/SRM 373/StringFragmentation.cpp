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

vector<string> Split(const string& s,const string d){
  string item(s);
  vector<string> res(0);
  for(auto pos = item.find(d); pos != string::npos; pos = item.find(d,pos)){
    item.replace(pos,d.size()," ");
  }
  stringstream buf(item);
  while(buf >> item){
    res.push_back(item);
  }
  return res;
}

class StringFragmentation {
  vector<string> sp;
    public:
    int largestFontSize(string text, int width, int height) {
      for (int i = 0; i < text.size(); i++) {
        if(text[i] == ' '){
          text[i] = '_';
        }
      }
      sp = Split(text,"_");
      int ans = -1;
      for(int pix = 8; pix <= 10000;++pix){
        if(cond(pix,width,height)){
          ans = max(ans,pix);
        }
      }
      return ans;
    }
    bool cond(int p,int w,int h){
      int x = 0,y = 1,X = -1;
      for(int i = 0; i < sp.size();){
        if ( (x + sp[i].size())* (p+2) <= w) {
          x += sp[i].size() + 1;
          X = max(X,x-1);
          ++i;
        }
        else if(sp[i].size() * (p+2) > w){
          return false;
        }
        else {
          --x;
          X = max(X,x);
          x = 0;
          ++y;
        }
      }
      if (2 * p * y <= h && X * (p+2) <= w) {
        return true;
      }
      return false;
    }
};

// CUT begin
ifstream data("StringFragmentation.sample");

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

bool do_test(string text, int width, int height, int __expected) {
    time_t startClock = clock();
    StringFragmentation *instance = new StringFragmentation();
    int __result = instance->largestFontSize(text, width, height);
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
        string text;
        from_stream(text);
        int width;
        from_stream(width);
        int height;
        from_stream(height);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(text, width, height, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1490946402;
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
        cout << "StringFragmentation (500 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
