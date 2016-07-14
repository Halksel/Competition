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

class SearchBox {
  int ans;
    public:
    int find(string text, string search, string wholeWord, int start) {
      string tmp = text;
      int f = 0;
      int cnt = 0;
      int spc = 0;
      if(wholeWord == "Y"){
        text = " " + text;
        text += " ";
        for(int i = start+1; i < text.size(); ++ i){
          if(text[i] == search[0]){
            for(int j = 0; j < search.size();++ j){
              if(text[i+j] != search[j]){
                break;
              }
              if(j == search.size()-1 && text[i+j+1] == ' ' && text[i-1] == ' '){
                return i-1;
              }
            }
          }
        }
        return -1;
      }
      else{
        text = text.substr(start);
        if(text.find(search) != string::npos){
          ans = text.find(search);
          return ans + start;
        }
        return -1;
      }
    }
    vector<string> Split(const string& s,const string d){
      string item(s);
      vector<string> res(0);
      for(int pos = item.find(d); pos != string::npos; pos = item.find(d,pos)){
        item.replace(pos,d.size(),"@");
      }
      string k = "@";
      for(int pos = item.find(k); pos != string::npos; pos = item.find(k,pos)){
        item.replace(pos,k.size()," ");
      }
      stringstream buf(item);
      while(buf >> item){
        res.push_back(item);
      }
      return res;
    }
};

// CUT begin
ifstream data("SearchBox.sample");

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

bool do_test(string text, string search, string wholeWord, int start, int __expected) {
    time_t startClock = clock();
    SearchBox *instance = new SearchBox();
    int __result = instance->find(text, search, wholeWord, start);
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
        string search;
        from_stream(search);
        string wholeWord;
        from_stream(wholeWord);
        int start;
        from_stream(start);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(text, search, wholeWord, start, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1467274509;
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
        cout << "SearchBox (250 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
