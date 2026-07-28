#include <bits/stdc++.h>

using namespace std;

/* https://leetcode.com/problems/subsets
 * solution 1 - bit mask
 * */

// class Solution {
//  public:
//   vector<vector<int>> subsets(vector<int>& nums) {
//     vector<vector<int>> res;
//     for (int mask{}; mask < (1 << nums.size()); ++mask) {
//       vector<int> subset;
//       for (int i = 0; i < nums.size(); ++i) {
//         if (mask & (1 << i)) subset.push_back(nums[i]);
//       }
//       res.push_back(subset);
//     }
//     return res;
//   }
// };

/* solution 2 - backtrack */

class Solution {
 private:
  void backtrack(int k, vector<int>& nums, vector<int>& subset,
                 vector<vector<int>>& res) {
    if (k == nums.size()) {
      res.push_back(subset);
      return;
    }
    backtrack(k + 1, nums, subset, res);
    subset.push_back(nums[k]);
    backtrack(k + 1, nums, subset, res);
    subset.pop_back();
  }

 public:
  vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> res;
    vector<int> subset;
    backtrack(0, nums, subset, res);
    return res;
  }
};
