#include <bits/stdc++.h>

using namespace std;

/* https://leetcode.com/problems/minimum-time-visiting-all-points/
 *
 * intuition: distance is max between diff x or y
 * */

class Solution {
 public:
  int minTimeToVisitAllPoints(vector<vector<int>>& points) {
    int res = 0;
    for (size_t i{}; i < points.size() - 1; ++i) {
      res += max(abs(points[i + 1][0] - points[i][0]),
                 abs(points[i + 1][1] - points[i][1]));
    }
    return res;
  }
};
