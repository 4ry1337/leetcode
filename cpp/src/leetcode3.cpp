#include <algorithm>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    int mx = 0, l = 0, r = 0;
    unordered_set<char> ss;
    while (r < s.size()) {
      if (ss.count(s[r]) != 0) {
        ss.erase(s[l++]);
      } else {
        mx = max(r - l + 1, mx);
        ss.insert(s[r++]);
      }
    }
    return mx;
  }
};
