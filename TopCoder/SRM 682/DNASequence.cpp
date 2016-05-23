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

class DNASequence {
  public:
    int longestDNASequence(string sequence) {
      int ans = 0,len = 0;
      for(int i = 0; i < sequence.size();++i){
        if(sequence[i] == 'A' || sequence[i] == 'G' || sequence[i] == 'C' || sequence[i] == 'T'){
          len = 0;
          for(int j = i; j < sequence.size();++j){
            if(sequence[j] == 'A' || sequence[j] == 'G' || sequence[j] == 'C' || sequence[j] == 'T'){
              ++len;
              if(len > ans){
                ans = len;
              }
            }
            else{
              cout << sequence.substr(i,j);
              i = j;
              break;
            }
          }
        }
      }

      return ans;
    }
};

// CUT begin
ifstream data("DNASequence.sample");

string next_line() {
    string s;
    getline(data, s);
    return s;
}

