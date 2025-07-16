#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
  bool checkInclusion(string s1, string s2) {
    if (s2.size() < s1.size())
      return false;

    unordered_map<int, int> mp1;
    for (char c : s1) {
      mp1[c]++;
    }

    int l = 0;
    unordered_map<int, int> mp2;
    for (int r = 0; r < s2.size(); r++) {
      mp2[s2[r]]++;
      while ((r - l + 1) > s1.size()) {
        mp2[s2[l]]--;
        if (mp2[s2[l]] == 0) {
          mp2.erase(s2[l]);
        }
        l++;
      }
      if (mp1 == mp2)
        return true;
    }
    return false;
  }
};
