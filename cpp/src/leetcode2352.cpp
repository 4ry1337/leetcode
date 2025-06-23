#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
  int equalPairs(vector<vector<int>> &grid) {
    int n = grid.size(), res = 0;
    map<vector<int>, int> mp;
    for (auto &c : grid) {
      mp[c]++;
    }
    for (int i = 0; i < n; i++) {
      vector<int> t(n);
      for (int j = 0; j < n; j++) {
        t[j] = grid[j][i];
      }
      res += mp[t];
    }
    return res;
  }
};
