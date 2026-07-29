#include <bits/stdc++.h>

using namespace std;

/* https://leetcode.com/problems/missing-number/description/
 *
 * solution 1 - hashset
 * 1. init hashset from nums
 * 2. iterate throug range 0 to N inclusive see what number is missing from
 * hashset
 * time: O(N) space: O(N)
 *
 * solution 2 - sums
 * intuition: we can see that sum of range minus current sum of nums will result
 * in missing number.
 * 1. using arihemtic progression we fins sum of range
 * 2. iteratire over nums and subtract each number
 * 3. return remaining sum
 * time: O(N) space: O(1)
 * */

class Solution {
 public:
  int missingNumber(vector<int>& nums) {
    int sum = (nums.size() * (nums.size() + 1)) / 2;
    for (auto& i : nums) sum -= i;
    return sum;
  }
};
