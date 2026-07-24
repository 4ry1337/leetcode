#include <bits/stdc++.h>

using namespace std;

/* https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/ */

class Solution {
 public:
  int removeDuplicates(vector<int>& nums) {
    int l = 0;
    for (auto& num : nums) {
      if (l < 2 || num != nums[l - 2]) {
        nums[l] = num;
        l++;
      }
    }
    return l;
  }
};
