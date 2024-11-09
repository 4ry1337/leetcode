#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  string convert(string s, int numRows) {
    if (numRows == 1 || numRows >= s.size()) {
      return s;
    }
    vector<string> rows(numRows);
    int curRow = 0;
    bool down = false;
    for (char c : s) {
      rows[curRow] += c;
      if (curRow == 0 || curRow == numRows - 1) {
        down = !down;
      }
      curRow += down ? 1 : -1;
    }
    string res = "";
    for (string v : rows) {
      res += v;
    }
    return res;
  }
};
