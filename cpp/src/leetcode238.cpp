#include <vector>

using namespace std;

class Solution {
public:
  vector<int> productExceptSelf(vector<int> &nums) {
    vector<int> res(nums.size(), 0);
    int prefix_prod = 1;
    for (int i = 0; i < nums.size(); i++) {
      res[i] = prefix_prod;
      prefix_prod *= nums[i];
    }
    int suffix_prod = 1;
    for (int i = nums.size() - 1; i >= 0; i--) {
      res[i] *= suffix_prod;
      suffix_prod *= nums[i];
    }
    return res;
  }
};
