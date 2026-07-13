#include <bits/stdc++.h>

using namespace std;

/* link: https://leetcode.com/problems/find-the-duplicate-number/
 *
 * solution 1 - brute force
 * nested iteration while we enouncter duplicate
 *
 * time: O(N^2)
 * space: O(1)
 *
 * solution 2 - linear
 *
 * we use array itself as hashset
 * we mark position corresponding entry
 * if we ennounter mark again we return current search
 *
 * */

class Solution {
 public:
  int findDuplicate(vector<int>& nums) {
    int res = nums[0];
    for (int i{}; i < nums.size(); ++i) {
      int next = nums[res];
      if (next == 0) return res;
      nums[res] = 0;
      res = next;
    }
    return res;
  }
};
