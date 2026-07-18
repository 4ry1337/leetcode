#include <bits/stdc++.h>

#include <vector>

using namespace std;

/* link: https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/ */

class Solution {
 public:
  vector<int> twoSum(vector<int>& nums, int t) {
    int l = 0, r = nums.size() - 1;
    while (l < r) {
      int val = nums[l] + nums[r];
      if (val == t)
        return vector<int>{l + 1, r + 1};
      else if (val < t)
        l++;
      else
        r--;
    }
    return vector<int>{};
  }
};
