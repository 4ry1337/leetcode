#include <bits/stdc++.h>

using namespace std;

/* https://leetcode.com/problems/kth-largest-element-in-an-array
 *
 * solution 1 - sort
 * 1. sort
 * 2. return kth element
 *
 * solution 2 - heap
 * */

class Solution {
 public:
  /* int findKthLargest(vector<int>& nums, int k) {
    sort(nums.rbegin(), nums.rend());
    return nums[k - 1];
  } */
  int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int> pq(nums.begin(), nums.end());
    while (--k) pq.pop();
    return pq.top();
  }
};
