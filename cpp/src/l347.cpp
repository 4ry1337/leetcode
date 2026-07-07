#include <bits/stdc++.h>

#include <queue>
#include <unordered_map>

using namespace std;

/* link: https://leetcode.com/problems/top-k-frequent-elements/
 * BCR(O(N))
 *
 *
 * */

class Solution {
 public:
  vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> mp;
    for (auto& num : nums) {
      mp[num]++;
    };
  }
};
