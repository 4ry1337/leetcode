

using namespace std;

/* link: https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/ */

class Solution {
 public:
  static auto twoSum(vector<int>& nums, int t) -> vector<int> {
    int l = 0;
    int r = nums.size() - 1;
    while (l < r) {
      int const val = nums[l] + nums[r];
      if (val == t) {
        return vector<int>{l + 1, r + 1};
      }
      if (val < t) {
        l++;
      } else {
        r--;
      }
    }
    return vector<int>{};
  }
};
