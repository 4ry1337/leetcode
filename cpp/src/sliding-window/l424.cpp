#include <bits/stdc++.h>

using namespace std;

/* link: https://leetcode.com/problems/longest-repeating-character-replacement
 *
 */

class Solution {
 public:
  int characterReplacement(string s, int k) {
    array<int, 26> win;
    int res = 0, l = 0, r = 0, temp = k;
    while (r < s.size()) {
      if (s[l] == s[r]) {
        r++;
      }
    }
    return res;
  }
};
