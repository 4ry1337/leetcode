#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
  int characterReplacement(string s, int k) {
    unordered_map<char, int> mp;
    int res = 0, f = 0;

    int l = 0;
    for (int r = 0; r < s.size(); r++) {
      mp[s[r]]++;
      // most frequent char in current window
      f = max(f, mp[s[r]]);

      // shrink window if length - most frequent char in current window is
      // larger than k
      while ((r - l + 1) - f > k) {
        mp[s[l]]--;
        l++;
      }

      // write the resulting length
      res = max(res, r - l + 1);
    }
    return res;
  }
};
