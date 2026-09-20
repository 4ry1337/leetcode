#include <vector>

using namespace std;

/* https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/ */

class Solution {
 public:
  static auto removeDuplicates(vector<int>& nums) -> int {
    int l = 0;
    for (auto const& num : nums) {
      if (l < 2 || num != nums[l - 2]) {
        nums[l] = num;
        l++;
      }
    }
    return l;
  }
};
