#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    int res = 0, l = 0, r = 0;
    unordered_set<char> set;
    while (r < s.size()) {
      if (set.count(s[r])) {
        set.erase(s[l++]);
      } else {
        res = max(r - l + 1, res);
        set.insert(s[r++]);
      }
    }
    return res;
  }
};
