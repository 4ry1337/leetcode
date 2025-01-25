#include <string>

using namespace std;

class Solution {
public:
  int lengthOfLastWord(string s) {
    int end = s.size() - 1;
    while (end >= 0) {
      if (s[end] != ' ') {
        break;
      }
      end--;
    }
    int start = end + 1;
    while (start >= 0) {
      if (s[start] == ' ') {
        break;
      }
      start--;
    }
    return start - end;
  }
};
