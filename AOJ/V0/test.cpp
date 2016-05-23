#include <iostream>
#include <string>
#include <map>
#include <cmath>

using namespace std;

map<char, string> cod;
const char deco[] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ .,-'?"};

void initi(void);

int main()
{
  string src;

  initi();

  while (getline(cin, src)) {
    string dis;

    for (int i = 0; i < src.size(); i++)
      dis += cod[src[i]];

    for (int i = 0; i < dis.size() % 5; i++)
      dis += '0';

    src.clear();
    for (int i = 0; i < dis.size(); i += 5) {
      string tmp = dis.substr(i, 5);
      int ind = 0;

      for (int i = 0; i < 5; i++) {
        if (tmp[i] == '1')
          ind += pow(2, 4 - i);
      }
      cout << deco[ind];
    }
    cout << endl;
  }

  return 0;
}


void initi(void)
{
  cod.insert(pair<char, string>(' ', "101"));
  cod.insert(pair<char, string>('\'', "000000"));
  cod.insert(pair<char, string>(',', "000011"));
  cod.insert(pair<char, string>('-', "10010001"));
  cod.insert(pair<char, string>('.', "010001"));
  cod.insert(pair<char, string>('?', "000001"));
  cod.insert(pair<char, string>('A', "100101"));
  cod.insert(pair<char, string>('B', "10011010"));

  cod.insert(pair<char, string>('C', "0101"));
  cod.insert(pair<char, string>('D', "0001"));
  cod.insert(pair<char, string>('E', "110"));
  cod.insert(pair<char, string>('F', "01001"));
  cod.insert(pair<char, string>('G', "10011011"));
  cod.insert(pair<char, string>('H', "010000"));
  cod.insert(pair<char, string>('I', "0111"));
  cod.insert(pair<char, string>('J', "10011000"));

  cod.insert(pair<char, string>('K', "0110"));
  cod.insert(pair<char, string>('L', "00100"));
  cod.insert(pair<char, string>('M', "10011001"));
  cod.insert(pair<char, string>('N', "10011110"));
  cod.insert(pair<char, string>('O', "00101"));
  cod.insert(pair<char, string>('P', "111"));
  cod.insert(pair<char, string>('Q', "10011111"));
  cod.insert(pair<char, string>('R', "1000"));

  cod.insert(pair<char, string>('S', "00110"));
  cod.insert(pair<char, string>('T', "00111"));
  cod.insert(pair<char, string>('U', "10011100"));
  cod.insert(pair<char, string>('V', "10011101"));
  cod.insert(pair<char, string>('W', "000010"));
  cod.insert(pair<char, string>('X', "10010010"));
  cod.insert(pair<char, string>('Y', "10010011"));
  cod.insert(pair<char, string>('Z', "10010000"));
}
