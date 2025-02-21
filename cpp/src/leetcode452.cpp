#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int findMinArrowShots(vector<vector<int>> &points) {
    int res = 1;

    sort(points.begin(), points.end());

    int r = points[0][1];

    for (int i = 1; i < points.size(); i++) {
      if (points[i][0] > r) {
        res += 1;
        r = points[i][1];
      } else {
        r = min(r, points[i][1]);
      }
    }

    return res;
  }
};
