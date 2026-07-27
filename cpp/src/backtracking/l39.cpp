#include <bits/stdc++.h>

using namespace std;

/* https://leetcode.com/problems/combination-sum */

class Solution {
 private:
  void backtrack(int idx, int t, vector<int>& nums, vector<int>& subset,
                 vector<vector<int>>& res) {
    if (t == 0) {
      res.push_back(subset);
      return;
    }
    if (idx == nums.size()) return;
    for (int i{idx}; i < nums.size(); i++) {
      subset.push_back(nums[i]);
      backtrack(i, t - nums[i], nums, subset, res);
      subset.pop_back();
    }
  }

 public:
  vector<vector<int>> combinationSum(vector<int>& nums, int t) {
    vector<vector<int>> res;
    vector<int> subset;
    backtrack(0, t, nums, subset, res);
    return res;
  }
};
