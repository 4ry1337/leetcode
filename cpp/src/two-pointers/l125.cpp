#include <cctype>
#include <string>

using namespace std;

/* link: https://leetcode.com/problems/valid-palindrome */

class Solution {
 public:
  static auto isPalindrome(string s) -> bool {
    int l = 0;
    int r = s.size() - 1;
    while (l < r) {
      while (l < r && (isalnum(tolower(s[l++])) == 0)) {
        ;
      }
      while (l < r && (isalnum(tolower(s[r--])) == 0)) {
        ;
      }
      if (tolower(s[l++]) != tolower(s[r--])) {
        return false;
      }
    }
    return true;
  }
};
