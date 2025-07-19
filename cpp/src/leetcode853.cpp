#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
  int carFleet(int k, vector<int> &p, vector<int> &s) {
    vector<pair<int, int>> temp;
    for (int i = 0; i < p.size(); i++)
      temp.push_back({p[i], s[i]});
    sort(temp.rbegin(), temp.rend());

    stack<double> st;
    for (auto p : temp) {
      double t = (double)(k - p.first) / p.second;
      if (st.empty() || st.top() < t) {
        st.push(t);
      }
    }
    return st.size();
  }
};
