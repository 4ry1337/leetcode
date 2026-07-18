#include <bits/stdc++.h>

using namespace std;

/* link: https://leetcode.com/problems/longest-repeating-character-replacement
 *
 * solution 1 - sliding window
 * 1. init freq map for 26 uppercase letter
 * 2. start two pointers
 * 3. move fastest and keep track of max_freq
 *    - max frequence can change only if current index get's higheer frequency
 * 4. if length of window exceeds max frequency and K we shrink the window
 * 5. store max window size and return it
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
