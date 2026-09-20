
#include <vector>

using namespace std;

/* link: https://leetcode.com/problems/group-anagrams/description/ */

class Solution {
 public:
  static auto removeElement(vector<int>& nums, int val) -> int {
    int index = 0;
    for (int i{}; i < nums.size(); ++i) {
      if (nums[i] != val) {
        nums[index++] = nums[i];
      }
    }
    return index;
  }
};
