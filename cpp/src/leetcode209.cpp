#include <algorithm>
#include <climits>
#include <vector>

using namespace std;

class Solution {
public:
  int minSubArrayLen(int target, vector<int> &nums) {
    int l = 0, r = 0, mn = INT_MAX, sum = 0;
    while (r < nums.size()) {
      sum += nums[r];
      while (sum >= target && l < r) {
        mn = min(mn, r - l + 1);
        sum -= nums[l];
        l++;
      }
      r++;
    }
    return mn == INT_MAX ? 0 : mn;
  }
};
