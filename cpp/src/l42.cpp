#include <bits/stdc++.h>

using namespace std;

/* link: https://leetcode.com/problems/trapping-rain-water
 *
 * 0 1 0
 *
 * h 0 1 0 2 1 0 1 3 2 1 2 1
 * */

class Solution {
 public:
  int trap(vector<int>& h) {
    int res = 0;
    int l = 0, r = h.size() - 1;
    int lh = h[l], rh = h[r];
    while (l < r) {
      if (lh < rh) {
        l++;
        lh = max(lh, h[l]);
        res += lh - h[l];
      } else {
        r--;
        rh = max(rh, h[r]);
        res += rh - h[r];
      }
    }
    return res;
  }
};
