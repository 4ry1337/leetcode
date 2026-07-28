#include <bits/stdc++.h>

using namespace std;

/* https://leetcode.com/problems/subsets-ii/description/ */

class Solution {
 private:
  void backtrack(int k, vector<int>& nums, vector<int>& subset,
                 vector<vector<int>>& res) {
    if (k == nums.size()) {
      res.push_back(subset);
      return;
    }
    // include
    subset.push_back(nums[k]);
    backtrack(k + 1, nums, subset, res);
    subset.pop_back();

    // exclude skip whole chunk
    while (k + 1 < nums.size() && nums[k] == nums[k + 1]) {
      k++;
    }
    backtrack(k + 1, nums, subset, res);
  }

 public:
  vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    vector<int> subset;
    backtrack(0, nums, subset, res);
    return res;
  }
};
