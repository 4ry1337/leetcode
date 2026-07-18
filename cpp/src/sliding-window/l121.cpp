#include <bits/stdc++.h>

using namespace std;

/* link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
 *
 * solution 1 - brute force
 * nested iteration storing max profit
 *
 * time: O(n^2) space: O(1)
 *
 * solution 2 - sliding window
 * init left and right bounderies of sliding window
 * window grows right when left boundary is smaller or equal to right
 * if right becomes smaller than left we move left
 *
 * time: O(N) space: O(1)
 *
 * problem: well we acutally searching current value - min value before it
 *
 * solution 3 - dp
 * we assume current is best price
 * then we need to keep track of min value before today
 * difference will be stored
 *
 * time: O(N) space: O(1)
 * */

class Solution {
 public:
  int maxProfit(vector<int>& p) {
    // int res = 0, l = 0, r = 0;
    // while (r < p.size()) {
    //   res = max(res, p[r] - p[l]);
    //   if (p[l] > p[r]) l++;
    //   else r++;
    // }
    // return res;
    int res = 0, m = INT_MAX;
    for (size_t i{}; i < p.size(); ++i) {
      res = max(res, p[i] - m);
      m = min(m, p[i]);
    }
    return res;
  }
};
