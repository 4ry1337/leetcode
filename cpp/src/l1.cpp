#include <bits/stdc++.h>

using namespace std;

/* link: https://leetcode.com/problems/two-sum/
 * BCR(O(N))
 *
 * solution 1 - brute force
 * run nested loop in nums until we find two indicies that sum to target
 * bottleneck is search for second item
 *
 * solution 2 - hashmap
 * we could record what number we need in hash map
 * with a key as number that we need and value as index of that number
 * we search throw nums
 * if we find that number exist we return those two
 * */
class Solution {
 public:
  vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> mp;
    for (int i{}; i < nums.size(); ++i) {
      auto it = mp.find(nums[i]);
      if (it != mp.end()) {
        return vector<int>({it->second, i});
      }
      mp[target - nums[i]] = i;
    }
    return vector<int>();
  }
};
