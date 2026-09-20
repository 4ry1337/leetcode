#include <vector>

using namespace std;

/* link: https://leetcode.com/problems/binary-search/ */
class Solution {
 public:
  static auto search(vector<int>& nums, int target) -> int {
    int base = 0;
    int size = nums.size();
    while (size > 1) {
      int const half = size / 2;
      int const mid = base + half;
      if (target == nums[mid]) {
        return mid;
      }
      if (target > nums[mid]) {
        base = mid;
      }
      size -= half;
    }
    if (target == nums[base]) {
      return base;
    }
    return -1;
  }
};
