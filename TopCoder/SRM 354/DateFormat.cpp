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

#define debug(x) cout<<#x<<": "<<x<<endl
class DateFormat {
  public:
    string fromEuropeanToUs(vector<string> dateList) {
      int month,day,suf = 0,nowm = 0, nowd = 0, tmpd = 0;
      bool flag = true;
      vector<string> vs = {""};
      string str,ans;

      if(dateList.size() > 1){
        for(int i = 0; i < dateList.size();++i){
          for(int j = 0; j < dateList[i].size();++j){
            if((dateList[i][j] - '0' >= 0 && dateList[i][j] - '0' <= 9) || (dateList[i][j] == '/')){
              vs[suf] += dateList[i][j] ;
              if(vs[suf].size() == 5){
                vs.push_back("");
                ++suf ;
              }
            }
          }
        }
      }
      else{
        for(int j = 0; j < dateList[0].length();++j){
          if((dateList[0][j] - '0' >= 0 && dateList[0][j] - '0' <= 9) || (dateList[0][j] == '/')){
            vs[suf] += dateList[0][j] ;
            if(vs[suf].size() == 5){
              vs.push_back("");
              ++suf ;
            }
          }
        }
      }
      /*
        m/d(US)
        m/d(en)
        d/m(en)
       */
      for(int i = 0; i < vs.size()-1; ++i){
        month = (vs[i][0]-'0') * 10 + vs[i][1]-'0';
        day = (vs[i][3]-'0') * 10 + vs[i][4]-'0' ;
//         debug(month) ;
//         debug(day);
        debug(nowm);
        debug(nowd);
        if( day < nowm || (day > nowm && month < nowd)){
          flag = false;
          break;
        }
        else if(day == nowm && month > tmpd){
          swap(month,day);
          nowd = day;
          tmpd = day;
          nowm = month;
        }
        else if(nowd < month && nowm < day){
          swap(month,day);
          if(month > nowm){
            nowd = 0;
          }
          else{
            nowd = day;
          }
          tmpd = day;
          nowm = month;
        }
        else if( month > nowd && day >= nowm  ){
          swap(month,day);
          if(month > nowm){
            nowd = 0;
          }
          else{
            nowd = day;
          }
          tmpd = day;
          nowm = month;
        }
        else{
          if(month > nowm){
            nowd = 0;
          }
          else{
            nowd = day;
          }
          tmpd = day;
          nowm = month;
        }
        vs[i][0] = month / 10 + '0' ;
        vs[i][1] = month % 10 + '0' ;
        vs[i][3] = day / 10 + '0' ;
        vs[i][4] = day % 10 + '0' ;
      }
      for(auto n: vs){
        cout << n << endl;
      }
      cout << vs.size()<< endl;
      for(int i = 0; i < vs.size()-1; ++i){
        if(vs.size()-2 == i){
          ans += vs[i] ;
        }
        else{
          ans += vs[i] + " ";
        }
      }
      if(flag){
        return ans;
      }
      return "";
    }
};

// CUT begin
ifstream data("DateFormat.sample");

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

bool do_test(vector<string> dateList, string __expected) {
    time_t startClock = clock();
    DateFormat *instance = new DateFormat();
    string __result = instance->fromEuropeanToUs(dateList);
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
        vector<string> dateList;
        from_stream(dateList);
        next_line();
        string __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(dateList, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1450688283;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 600 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
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
        cout << "DateFormat (600 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
