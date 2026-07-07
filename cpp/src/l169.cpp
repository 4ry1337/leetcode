#include <bits/stdc++.h>

using namespace std;
/* link: https://leetcode.com/problems/majority-element/
 * BCR(O(N))
 *
 * solution 1 - sort
 * 1. sort array
 * 2. take middle element
 * time: O(NlogN) space: O(1)
 *
 * follow up: can you solve in linear time?
 *
 * solution 2 - moore voting
 * 1. init count and candidate
 * 2. iterate through array
 * 3. if count == 0 -> candidate = val;
 * 4. if candidate == val count ++
 * 5. else count --
 * */

class Solution {
 public:
  int majorityElement(vector<int>& nums) {
    int count = 0, cnd;
    for (auto& n : nums) {
      if (count == 0) {
        cnd = n;
      }
      count += (cnd == n) ? 1 : -1;
    }
    return cnd;
  }
};
