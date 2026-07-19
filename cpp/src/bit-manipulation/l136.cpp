#include <bits/stdc++.h>

using namespace std;

/* https://leetcode.com/problems/single-number/
 *
 * solution xor
 * xor operation results in 1 if operands are different
 * and 0 on same
 *
 * 3 = 011
 * 4 = 100
 * 4 = 100
 * -------
 * 3 = 011
 * */

class Solution {
 public:
  int singleNumber(vector<int>& nums) {
    int res = 0;
    for (auto& num : nums) res ^= num;
    return res;
  }
};
