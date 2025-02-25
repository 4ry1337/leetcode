#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    for (int i = 0; i < nums.size() - 2; i++) {
      if (i > 0 && nums[i] == nums[i - 1])
        continue;
      int l = i + 1;
      int r = nums.size() - 1;
      while (l < r) {
        int three_sum = nums[i] + nums[l] + nums[r];
        if (three_sum > 0) {
          r--;
        } else if (three_sum < 0) {
          l++;
        } else {
          res.push_back({nums[i], nums[l], nums[r]});
          while (l < r && nums[l] == nums[l + 1])
            l++;
          while (l < r && nums[r] == nums[r - 1])
            r--;
          l++;
          r--;
        }
      }
    }
    return res;
  }
};
