#include <bits/stdc++.h>

#include <unordered_map>

using namespace std;

/* link: https://leetcode.com/problems/minimum-window-substring
 *
 * solutio 1 - sliding window
 * 1. check if s is smaller that t
 * 2.
 * */

class Solution {
 public:
  string minWindow(string s, string t) {
    if (s.size() < t.size()) return "";

    unordered_map<char, int> freq{}, curr{};
    for (auto& c : t) freq[c]++;

    int start = 0, len = INT_MAX;
    int have = 0, need = freq.size();

    for (int l{}, r{}; r < s.size(); r++) {
      curr[s[r]]++;
      if (freq.count(s[r]) && curr[s[r]] == freq[s[r]]) have++;
      while (have == need) {
        if (r - l + 1 < len) {
          len = r - l + 1;
          start = l;
        }
        curr[s[l]]--;
        if (freq.count(s[l]) && curr[s[l]] < freq[s[l]]) have--;
        l++;
      }
    }
    return len == INT_MAX ? "" : s.substr(start, len);
  }
};
