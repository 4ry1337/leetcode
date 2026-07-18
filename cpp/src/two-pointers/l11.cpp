#include <bits/stdc++.h>

#include <algorithm>

using namespace std;

/* link: https://leetcode.com/problems/container-with-most-water
 *
 * solution - brute force
 * calculate all possible water trappings
 * find max among
 *
 * solution - two pointer
 * 1. init res, l and r
 * 2. calculate area using (r - l) min(h[r], h[l])
 * 3. write to res max between area and res;
 * 4. if right wall is smaller than left move left by one
 *  - else right one by one
 *
 * Example:
 *
 * 0 1 2 3 4 5 6 7 8
 * 1 8 6 2 5 4 8 3 7
 *           l r
 *
 * res
 * 8 49 49 49 49 49 49 49
 * w
 * 8 49 18 40 24 6 10 4
 *
 * */

class Solution {
 public:
  int maxArea(vector<int>& h) {
    int res = 0, l = 0, r = h.size() - 1;
    while (l < r) {
      res = max(res, (r - l) * min(h[r], h[l]));
      if (h[l] > h[r]) {
        r--;
      } else {
        l++;
      }
    }
    return res;
  }
};
