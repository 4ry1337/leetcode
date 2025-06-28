#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
  vector<int> asteroidCollision(vector<int> &a) {
    vector<int> res;
    stack<int> s;
    int i = 0;
    while (i < a.size()) {
      if (s.empty()) {
        s.push(a[i++]);
        continue;
      }
      if ((s.top() ^ a[i]) >= 0) {
        s.push(a[i++]);
        continue;
      }
      if (a[i] > 0) {
        s.push(a[i++]);
        continue;
      }
      if (s.top() == -a[i]) {
        s.pop();
        i++;
      } else if (s.top() < -a[i]) {
        s.pop();
      } else {
        i++;
      }
    }
    while (!s.empty()) {
      res.push_back(s.top());
      s.pop();
    }
    reverse(res.begin(), res.end());
    return res;
  }
};
