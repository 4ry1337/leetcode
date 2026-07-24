#include <bits/stdc++.h>

using namespace std;

/* https://leetcode.com/problems/remove-duplicates-from-sorted-array/ */

class Solution {
 public:
  int removeDuplicates(vector<int>& nums) {
    int l = 0, r = 0;
    while (r < nums.size()) {
      nums[l] = nums[r];
      while (r < nums.size() && nums[l] == nums[r]) r++;
      l++;
    }
    return l;
  }
};

// 0 1 1 1 1 2 2 3 3 4
//   l
//           r
