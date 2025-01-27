#include <cctype>
#include <string>

using namespace std;

class Solution {
public:
  bool isPalindrome(string &s) {
    int i = 0;
    int len = s.size();
    while (i < len) {
      if (!isalnum(s[i])) {
        s.erase(i, 1);
        len--;
      } else {
        s[i] = tolower(s[i]);
        i++;
      }
    }
    string comp = s;
    int l = 0, r = s.size() - 1;
    while (l < r) {
      char temp = s[l];
      s[l++] = s[r];
      s[r--] = temp;
    }
    return comp == s;
  }
};
