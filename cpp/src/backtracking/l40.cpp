#include <algorithm>
#include <boost/range/algorithm/sort.hpp>
#include <vector>

using namespace std;

/* https://leetcode.com/problems/combination-sum-ii/ */

class Solution {
 private:
  void backtrack(int idx, int t, vector<int>& nums, vector<int> subset,
                 vector<vector<int>>& res) {
    if (t == 0) {
      res.push_back(subset);
      return;
    }
    for (int i{idx}; i < nums.size(); i++) {
      if (i > idx && nums[i] == nums[i - 1]) {
        continue;
      }
      if (t - nums[i] < 0) {
        break;
      }
      subset.push_back(nums[i]);
      backtrack(i + 1, t - nums[i], nums, subset, res);
      subset.pop_back();
    }
  }

 public:
  auto combinationSum2(vector<int>& nums, int t) -> vector<vector<int>> {
    boost::range::sort(nums);
    vector<vector<int>> res;
    vector<int> const subset;
    backtrack(0, t, nums, {}, res);
    return res;
  }
};
