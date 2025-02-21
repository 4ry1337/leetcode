#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  vector<vector<int>> insert(vector<vector<int>> &intervals,
                             vector<int> &newInterval) {
    int i = 0;
    while (i < intervals.size() && intervals[i][1] < newInterval[0]) {
      i++;
    }
    intervals.insert(intervals.begin() + i, newInterval);

    vector<vector<int>> res;
    for (auto interval : intervals) {
      if (res.empty() || res.back()[1] < interval[0]) {
        res.push_back(interval);
      } else {
        res.back()[1] = max(res.back()[1], interval[1]);
      }
    }
    return res;
  }
};
