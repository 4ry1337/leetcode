#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
  vector<int> dailyTemperatures(vector<int> &t) {
    stack<pair<int, int>> st;
    vector<int> res(t.size(), 0);
    for (int i = 0; i < t.size(); i++) {
      int x = t[i];
      while (!st.empty() && st.top().first < x) {
        res[st.top().second] = i - st.top().second;
        st.pop();
      }
      st.push({x, i});
    }
    return res;
  }
};
