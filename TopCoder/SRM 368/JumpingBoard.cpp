#include <cstdio>
#include <cmath>
#include <cstring>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <sstream>
#include <typeinfo>
#include <fstream>
#include <queue>

using namespace std;

using pii = pair<int,int> ;
using ll = long long;
#define value(x,y,w,h) (x >= 0 && x < w && y >= 0 && y < h)
#define rep(i,n) for(int i = 0; i < (int)(n);++i)
const int dy[] = {-1,0,1,0,1,-1,1,-1};
const int dx[] = {0,-1,0,1,1,-1,-1,1};
struct Edge{
  int to;
  long long cost;
};
struct NODE{
  int pos;
  long long cost;
};
bool operator < (const NODE &a,const NODE &b){
  return a.cost > b.cost;
}
class JumpingBoard {
  const int MAX_V = 1000000;
  vector<Edge> g[2501];
  int N;
  ll INF;
  vector<ll> dijkstra(vector<Edge> g[2501], int s){
    priority_queue<NODE> Q;
    Q.push({s,0});
    vector<ll> res(N,-INF);
    while(Q.size()){
      NODE q= Q.top();Q.pop();
      if(res[q.pos] < -1 * q.cost ){
        res[q.pos] = -1 * q.cost;
      }
      else continue;
      if(-1 * q.cost >= 2501) continue ;
      for(auto n : g[q.pos]){
        Q.push({n.to,-1 * (-1 * q.cost+n.cost)});
      }
    }
    return res;
  }
  public:
  int w,h;
  int func(int x,int y){
    return (x + y*w);
  }
  int maxJumps(vector<string> board) {
    ll ans = 0;
    N = 2502;
    INF = 1e9;
    w = board[0].size(),h = board.size();
    node.resize(2501);
    dis.resize(2501);
    rep(i,w){
      rep(j,h){
        if(board[j][i] == 'H'){
          node[func(i,j)] = -1;
          continue ;
        }
        int k = board[j][i] - '0';
        int f = func(i,j);
        rep(l,4){
          if(value(i + dx[l] * k,j+dy[l]*k,w,h) && board[j + dy[l] * k][i + dx[l] * k] != 'H'){
            g[func(i,j)].push_back({func(i + dx[l] * k,j+dy[l]*k),1});
          }
        }
      }
    }
    if(findDAG(0,0)) return -1;
    auto res = dijkstra(g,0);
    cout  << endl;
    rep(j,h){
      rep(i,w){
        cout << res[func(i,j)] << ' ' ;
      }
      cout  << endl;
    }
    for(auto n : res){
      ans = max(ans,n);
    }
    if(ans >= 2501) return -1;
    return ans+1;
  }
  vector<int> node,dis;
  bool findDAG(int p,int c){
    bool res = false;
    if(node[p] == 0){
      node[p] = 1;
      for(auto e : g[p]){
        res |= findDAG(e.to,c+1);
      }
      node[p] = 2;
      return res;
    }
    else if(node[p] == 1){
      return true;
    }
    return res;
  }
};
// CUT begin
ifstream data("JumpingBoard.sample");

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

bool do_test(vector<string> board, int __expected) {
    time_t startClock = clock();
    JumpingBoard *instance = new JumpingBoard();
    int __result = instance->maxJumps(board);
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
        vector<string> board;
        from_stream(board);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(board, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1487576141;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 900 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
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
        cout << "JumpingBoard (900 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
