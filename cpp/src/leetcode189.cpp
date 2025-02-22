#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  void reverse(vector<int> &nums, int start, int end) {
    while (start < end) {
      int temp = nums[start];
      nums[start++] = nums[end];
      nums[end--] = temp;
    }
  }

  void rotate(vector<int> &nums, int k) {
    k %= nums.size();
    this->reverse(nums, 0, nums.size() - 1);
    this->reverse(nums, 0, k - 1);
    this->reverse(nums, k, nums.size() - 1);
  }
};
