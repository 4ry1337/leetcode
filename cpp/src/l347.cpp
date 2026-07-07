#include <bits/stdc++.h>

#include <queue>
#include <unordered_map>
#include <vector>

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
    for (auto& num : nums) mp[num]++;

    vector<vector<int>> freq(nums.size() + 1);
    for (const auto& [k, v] : mp) freq[v].push_back(k);

    vector<int> res;
    for (int i = freq.size() - 1; i >= 0; --i) {
      for (const auto& v : freq[i]) {
        res.push_back(v);
        if (res.size() == k) return res;
      }
    }
    return res;
  }
};
