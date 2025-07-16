#include "bits/stdc++.h"

using namespace std;

/* class Solution {
public:
  int longestConsecutive(vector<int> &nums) {
    unordered_set<int> ns(nums.begin(), nums.end());

    int res = 0;
    for (auto n : ns) {
      if (ns.find(n - 1) != ns.end())
        continue;
      int temp = 1;
      while (ns.find(++n) != ns.end())
        temp++;
      res = max(res, temp);
    }
    return res;
  }
}; */

class Solution {
public:
  int longestConsecutive(vector<int> &n) {
    int res = 0;
    // length of sequence (value) containing the index (key)
    unordered_map<int, int> mp;
    for (int x : n) {
      if (!mp[x]) {
        mp[x] = mp[x - 1] + mp[x + 1] + 1;
        mp[x - mp[x - 1]] = mp[x];
        mp[x + mp[x + 1]] = mp[x];
        res = max(res, mp[x]);
      }
    }
    return res;
  }
};
