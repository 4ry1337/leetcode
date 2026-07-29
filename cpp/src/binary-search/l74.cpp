#include <bits/stdc++.h>

using namespace std;

/* link: https://leetcode.com/problems/search-a-2d-matrix/ */

class Solution {
 public:
  bool searchMatrix(vector<vector<int>>& m, int t) {
    int r = m.size();
    int c = m[0].size();
    int base = 0;
    int size = r * c;
    while (size > 1) {
      int half = size / 2;
      int mid = base + half;
      if (m[mid / c][mid % c] == t) {
        return true;
      } else if (t > m[mid / c][mid % c]) {
        base = mid;
      }
      size -= half;
    }
    if (m[base / c][base % c] == t) return true;
    return false;
  }
};
