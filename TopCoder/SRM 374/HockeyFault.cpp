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
#include <complex>

#define rep(i,a,b) for(int i = (a); i < (int)(b);++i)
#define value(x,y,w,h) (x >= 0 && x <= w && y >= 0 && y <= h)
using namespace std;
const double EPS = 1e-8;
const double INF = 1e12;
typedef complex<double> P;
double dot(const P& a, const P& b) {
  return real(conj(a)*b);
}
double distancePP(const P &p,const P &q){
  return dot((p - q), (p - q));
}

class HockeyFault {
    public:
    int numPlayers(int width, int height, int x, int y, vector<int> px, vector<int> py) {
      int res = 0;
      int n = px.size();
      vector<P> ps(n);
      double r = height/2;
      P a = P(0,r),b = P(width,r);
      /* cout << endl << a << endl; */
      rep(i,0,n){
        ps[i] = P(px[i]-x,py[i]-y);
        /* cout << ps[i] << endl;               */
        /* cout << distancePP(a,ps[i]) << endl; */
        /* cout << a << endl;                         */
        /* cout << px[i]-x <<' '<< py[i] - y << endl; */
        if(value(px[i]-x,py[i]-y,width,height) || distancePP(a,ps[i]) <= r*r || distancePP(b,ps[i]) <= r*r ) ++res;
        else{
          cout << i << ' ' << ps[i] << endl;
        }
      }

      return res;
    }
};

// CUT begin
ifstream data("HockeyFault.sample");

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

bool do_test(int width, int height, int x, int y, vector<int> px, vector<int> py, int __expected) {
    time_t startClock = clock();
    HockeyFault *instance = new HockeyFault();
    int __result = instance->numPlayers(width, height, x, y, px, py);
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
        int width;
        from_stream(width);
        int height;
        from_stream(height);
        int x;
        from_stream(x);
        int y;
        from_stream(y);
        vector<int> px;
        from_stream(px);
        vector<int> py;
        from_stream(py);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(width, height, x, y, px, py, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1491529231;
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
        cout << "HockeyFault (250 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
