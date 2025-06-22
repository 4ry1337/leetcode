#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
  int longestOnes(vector<int> &nums, int k) {
    int l = 0, r = 0, res = 0, count = 0;
    while (l < nums.size() && r < nums.size()) {
      if (nums[r++] == 0) {
        count++;
      }
      if (count > k && nums[l++] == 0) {
        count--;
      }
      res = max(res, r - l);
    }
    return res;
  }
};
