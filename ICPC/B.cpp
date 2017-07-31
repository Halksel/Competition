#include<bits/stdc++.h>

using namespace std;

int main() {
  string s1, s2;
  while (cin >> s1) {
    if (s1 == ".") {
      break;
    }
    cin >> s2;
    if (s1 == s2) {
      cout << "IDENTICAL" << endl;
    } else {
      vector<string> v1, v2;
      string a;
      int c = 0;
      string ss1, ss2;
      for (int i = 0; i < s1.size(); i++) {
        if (s1[i] == '"') {
          ss1 += s1[i];
          if (c == 0) {
            c++;
          } else {
            c--;
            v1.push_back(a);
            a = "";
          }
        } else if (c > 0) {
          a += s1[i];
        } else {
          ss1 += s1[i];
        }
      }
      for (int i = 0; i < s2.size(); i++) {
        if (s2[i] == '"') {
          ss2 += s2[i];
          if (c == 0) {
            c++;
          } else {
            c--;
            v2.push_back(a);
            a = "";
          }
        } else if (c > 0) {
          a += s2[i];
        } else {
          ss2 += s2[i];
        }
      }
      if (ss1 == ss2) {
        if (v1.size() == v2.size()) {
          int c2 = 0;
          for (int i = 0; i < v1.size(); i++) {
            if (v1[i] != v2[i]) {
              c2++;
            }
          }
          if (c2 == 1) {
            cout << "CLOSE" << endl;
          } else {
            cout << "DIFFERENT" << endl;
          }
        } else {
          cout << "DIFFERENT" << endl;
        }
      } else {
        cout << "DIFFERENT" << endl;
      }
    }
  }
}