#include <algorithm>
#include <boost/range/algorithm/reverse.hpp>
#include <vector>

using namespace std;

/* https://leetcode.com/problems/squares-of-a-sorted-array/ */

class Solution {
 public:
  static auto sortedSquares(vector<int>& nums) -> vector<int> {
    vector<int> res;
    int l = 0;
    int r = nums.size() - 1;
    while (l <= r) {
      int sl = nums[l] * nums[l];
      int sr = nums[r] * nums[r];
      if (sl > sr) {
        res.push_back(sl);
        l++;
      } else {
        res.push_back(sr);
        r--;
      }
    }
    boost::range::reverse(res);
    return res;
  }
};
