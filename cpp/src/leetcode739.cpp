#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
  vector<int> dailyTemperatures(vector<int> &t) {
    stack<int> st;
    vector<int> res(t.size(), 0);
    for (int i = 0; i < t.size(); i++) {
      int x = t[i];
      while (!st.empty() && t[st.top()] < x) {
        res[st.top()] = i - st.top();
        st.pop();
      }
      st.push(i);
    }
    return res;
  }
};
