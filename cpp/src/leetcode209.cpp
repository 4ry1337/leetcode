#include <algorithm>
#include <climits>
#include <vector>
using namespace std;

class Solution {
public:
  int minSubArrayLen(int target, vector<int> &nums) {
    int l = 0, r = 0, min = INT_MAX;
    int current_sum = 0;
    while (r < nums.size()) {
      current_sum += nums[r];
      while (current_sum >= target && l < r) {
        min = std::min(min, r - l + 1);
        current_sum -= nums[l];
        l++;
      }
      r++;
    }
    if (min == INT_MAX) {
      return 0;
    }
    return min;
  }
};
