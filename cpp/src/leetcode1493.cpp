#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
  int longestSubarray(vector<int> &s) {
    int l = 0, res = 0, check = 0;
    for (int r = 0; r < s.size(); r++) {
      if (s[r] == 0 && check++ > 0) {
        while (s[l++] == 1)
          ;
        check--;
      }
      res = max(res, r - l);
    }
    return res;
  }
};
