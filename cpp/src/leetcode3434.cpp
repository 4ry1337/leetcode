#include <algorithm>
#include <climits>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
  int maxFrequency(vector<int> &nums, int k) {
    auto nearability = make_pair(nums, k);
    int baseCount = 0;
    for (int v : nums) {
      if (v == k) {
        baseCount++;
      }
    }
    int ans = 0;
    for (int v = 1; v <= 50; v++) {
      if (v == k)
        continue;
      vector<int> count(nums.size());
      for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == k) {
          count[i] = -1;
        } else if (nums[i] == v) {
          count[i] = 1;
        } else {
          count[i] = 0;
        }
      }
      int curr = 0, mx = INT_MIN;
      for (int x : count) {
        curr = max(curr, curr + x);
        mx = max(mx, curr);
      }
      ans = max(ans, mx);
    }
    ans = max(ans, 0);
    return baseCount + ans;
  }
};
