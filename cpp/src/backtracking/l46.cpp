#include <bits/stdc++.h>

#include <algorithm>

using namespace std;

/* https://leetcode.com/problems/permutations/
 *
 * solution 1 - backtracking
 * same as combination but keep track of what you have chosen
 *
 * time: O(n * n!)
 * space: O(n * n!)
 * */

/* class Solution {
 private:
  void backtrack(vector<int>& nums, vector<vector<int>>& res,
                 vector<int>& subset, vector<bool>& chosen) {
    if (subset.size() == nums.size()) {
      res.push_back(subset);
      return;
    }
    for (int i{}; i < nums.size(); i++) {
      if (chosen[i]) continue;
      subset.push_back(nums[i]);
      chosen[i] = true;
      backtrack(nums, res, subset, chosen);
      subset.pop_back();
      chosen[i] = false;
    }
  }

 public:
  vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> res;
    vector<int> subset;
    vector<bool> choose(nums.size(), false);
    backtrack(nums, res, subset, choose);
    return res;
  }
}; */

/* solution 2 - built-in
 * time: O(n * n!)
 * space: O(n * n!)
 * */
class Solution {
 public:
  vector<vector<int>> permute(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    do {
      res.push_back(nums);
    } while (next_permutation(nums.begin(), nums.end()));
    return res;
  }
};
