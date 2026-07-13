#include <bits/stdc++.h>

#include <stack>

using namespace std;

/*
 * link: https://leetcode.com/problems/car-fleet/
 *
 * solution 1 - stack
 * 1. sort in descending position and speed by creating a temp vector pair
 * 2. init stack
 * 3. we calcualte time to reach target for each
 *    - t[i] = (target - p[i]) / s[i]
 *    - if time of ahead car if higher than curr they merge into fleet
 * 4. we return size of stack
 *
 * */

class Solution {
 public:
  int carFleet(int t, vector<int>& p, vector<int>& s) {
    vector<pair<int, int>> ps;
    for (size_t i{}; i < p.size(); ++i) ps.push_back({p[i], s[i]});
    sort(ps.rbegin(), ps.rend());
    stack<double> st;
    for (auto& [pos, sp] : ps) {
      double time = (double)(t - pos) / sp;
      if (!st.empty() && st.top() >= time) continue;
      st.push(time);
    }
    return st.size();
  }
};
