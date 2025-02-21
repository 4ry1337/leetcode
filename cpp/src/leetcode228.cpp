#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  vector<string> summaryRanges(vector<int> &nums) {
    vector<string> res;

    for (int i = 0; i < nums.size(); i++) {
      int l = nums[i];
      while (i + 1 < nums.size() && nums[i] == nums[i + 1] - 1) {
        i++;
      }
      int r = nums[i];
      if (l == r) {
        res.push_back(to_string(l));
      } else {
        res.push_back(to_string(l) + "->" + to_string(r));
      }
    }

    return res;
  }
};
