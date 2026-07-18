#include <bits/stdc++.h>

#include <unordered_map>

using namespace std;

/* https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/
 *
 * solution 1 - hashset
 * 1. init hashset from nums
 * 2. iteratire over range 1 to N and if number is missing append it to result
 * vector
 * 3. return result vector
 *
 * Follow up: Could you do it without extra space and in O(n) runtime? You may
 * assume the returned list does not count as extra space.
 *
 * solution - negative marking
 *  4  3  2  7  8  2  3  1
 *  0  1  2  3  4  5  6  7
 * -4 -3 -2 -7  8  2 -3 -1
 * */

class Solution {
 public:
  /* vector<int> findDisappearedNumbers(vector<int>& nums) {
    unordered_set<int> mp(nums.begin(), nums.end());
    vector<int> res;
    for (int i = 0; i <= nums.size(); ++i) {
      if (mp.find(i) == mp.end()) {
        res.push_back(i);
      }
    }
    return res;
  } */
  vector<int> findDisappearedNumbers(vector<int>& nums) {
    for (int i{}; i < nums.size(); ++i) {
      int temp = abs(nums[i]) - 1;
      if (nums[temp] > 0) nums[temp] *= -1;
    }
    vector<int> res;
    for (int i{}; i < nums.size(); ++i) {
      if (nums[i] > 0) res.push_back(i + 1);
    };
    return res;
  }
};
