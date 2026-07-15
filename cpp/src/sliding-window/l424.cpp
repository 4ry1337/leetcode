#include <bits/stdc++.h>

using namespace std;

/* link: https://leetcode.com/problems/longest-repeating-character-replacement
 *
 */

class Solution {
 public:
  int characterReplacement(string s, int k) {
    array<int, 26> win{};
    int res = 0, l = 0, r = 0;
    int max_freq = 0;
    while (r < s.size()) {
      win[s[r] - 'A']++;
      max_freq = max(max_freq, win[s[r] - 'A']);
      if (r - l + 1 > max_freq + k) {
        win[s[l] - 'A']--;
        l++;
      }
      res = max(res, r - l + 1);
      r++;
    }
    return res;
  }
};
