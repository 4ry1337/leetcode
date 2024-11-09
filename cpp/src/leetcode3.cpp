#include <algorithm>
#include <set>
#include <string>
using namespace std;

class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    int res = 0, l = 0, r = 0;
    set<char> cs;
    while (r < s.size()) {
      if (cs.count(s[r]) != 0) {
        cs.erase(s[l]);
        l++;
      } else {
        cs.insert(s[r]);
        res = max(r - l + 1, res);
        r++;
      }
    }
    return res;
  }
};
