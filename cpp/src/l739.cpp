#include <bits/stdc++.h>

using namespace std;

/*
 * link: https://leetcode.com/problems/daily-temperatures/
 *
 * 73 74 75 71 69 72 76 73
 *
 * solution 1 - brute force
 * 1. start a loop over temps
 * 2. start a second loop from current temp till we meet some higher
 * 3. write into res vector
 * 4. return res
 *
 * time: O(N^2)
 * space: O(1) + space for result vector
 * problem: is nested loops are bottleneck
 *
 * solution 2 - monotonic stack
 * 1. init output array
 * 2. init stack of pairs
 * 3. loop through vector temps
 *    - we store current temp and its index in stack
 *    - whenever we encounter temp higher that top's temp
 *    - we write to its index in res a difference on current and top's temps
 * 4. return res
 *
 * time: O(N)
 * space: O(1) - extra space O(N) output space
 *
 * */

class Solution {
 public:
  vector<int> dailyTemperatures(vector<int>& t) {
    vector<int> res(t.size());

    stack<pair<int, int>> st;
    for (int i{}; i < t.size(); ++i) {
      while (!st.empty() && st.top().first < t[i]) {
        res[st.top().second] = i - st.top().second;
        st.pop();
      }
      st.push({t[i], i});
    }

    return res;
  }
};
