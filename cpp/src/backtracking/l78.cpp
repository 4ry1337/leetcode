#include <bits/stdc++.h>

using namespace std;

/* https://leetcode.com/problems/subsets */

class Solution {
 public:
  vector<vector<int>> subsets(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> res;
    for (int b{}; b < (1 << n); ++b) {
      vector<int> subset;
      for (int i = 0; i < n; ++i) {
        if (b & (1 << i)) subset.push_back(nums[i]);
      }
      res.push_back(subset);
    }
    return res;
  }
};
