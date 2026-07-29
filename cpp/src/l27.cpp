
#include <bits/stdc++.h>

using namespace std;

/* link: https://leetcode.com/problems/group-anagrams/description/ */

class Solution {
 public:
  int removeElement(vector<int>& nums, int val) {
    int index = 0;
    for (int i{}; i < nums.size(); ++i) {
      if (nums[i] != val) {
        nums[index++] = nums[i];
      }
    }
    return index;
  }
};
