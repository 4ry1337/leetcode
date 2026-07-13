#include <bits/stdc++.h>

using namespace std;

/* link: https://leetcode.com/problems/binary-search/ */
class Solution {
 public:
  int search(vector<int>& nums, int target) {
    int base = 0, size = nums.size();
    while (size > 1) {
      int half = size / 2;
      int mid = base + half;
      if (target == nums[mid]) {
        return mid;
      } else if (target > nums[mid]) {
        base = mid;
      }
      size -= half;
    }
    if (target == nums[base]) return base;
    return -1;
  }
};
