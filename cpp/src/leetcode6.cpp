#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  string convert(string s, int numRows) {
    if (numRows == 1 || s.size() <= numRows) {
      return s;
    }
    vector<string> ss(numRows);
    bool down = false;
    int currRow = 0;
    for (int i = 0; i < s.size(); i++) {
      ss[currRow] += s[i];
      if (currRow + 1 == numRows || currRow == 0) {
        down = !down;
      }
      currRow += (down ? 1 : -1);
    }
    string res = "";
    for (string i : ss) {
      res += i;
    }
    return res;
  }
};
