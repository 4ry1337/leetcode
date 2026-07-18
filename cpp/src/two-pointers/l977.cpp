#include <bits/stdc++.h>

using namespace std;

/* https://leetcode.com/problems/squares-of-a-sorted-array/ */

class Solution {
 public:
  vector<int> sortedSquares(vector<int>& nums) {
    vector<int> res;
    int l = 0, r = nums.size() - 1;
    while (l <= r) {
      int sl = nums[l] * nums[l], sr = nums[r] * nums[r];
      if (sl > sr) {
        res.push_back(sl);
        l++;
      } else {
        res.push_back(sr);
        r--;
      }
    }
    reverse(res.begin(), res.end());
    return res;
  }
};
