#include <bits/stdc++.h>

using namespace std;

/* link: https://leetcode.com/problems/valid-anagram */

class Solution {
public:
  bool isAnagram(const string &s, const string &t) {
    array<int, 26> freq{};
    for (const auto &c : s) {
      ++freq[c - 'a'];
    }
    for (const auto &c : t) {
      --freq[c - 'a'];
    }
    for (auto const &f : freq) {
      if (f != 0) {
        return false;
      }
    }
    return true;
  }
};
