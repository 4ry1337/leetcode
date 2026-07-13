#include <bits/stdc++.h>

using namespace std;

/* link: https://leetcode.com/problems/largest-rectangle-in-histogram/
 *
 * */

class Solution {
 public:
  int largestRectangleArea(vector<int>& h) {
    int res = 0;
    stack<pair<int, int>> st;
    for (int i{}; i < h.size(); ++i) {
      int start = i;
      while (!st.empty() && st.top().second > h[i]) {
        auto& [index, height] = st.top();
        res = max(res, height * (i - index));
        st.pop();
        start = index;
      }
      st.push({start, h[i]});
    }
    while (!st.empty()) {
      auto& [index, height] = st.top();
      res = max(res, height * ((int)h.size() - index));
      st.pop();
    }
    return res;
  }
};
