#include <climits>
#include <cstdlib>
#include <vector>

using namespace std;

class Solution {
public:
  int countPartitions(vector<int> &nums) {
    int left = nums[0], right = 0;
    for (int i = 1; i < nums.size(); i++) {
      right += nums[i];
    }

    int res = 0;

    for (int i = 1; i < nums.size() - 1; i++) {
      if (abs(left - right) % 2 == 0) {
        res++;
      }
      left += nums[i];
      right -= nums[i];
    }
    if (abs(left - right) % 2 == 0) {
      res++;
    }
    return res;
  }
};
