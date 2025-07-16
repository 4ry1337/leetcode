#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
  int maxProfit(vector<int> &p) {
    int res = 0, m = p[0];
    for (int x : p) {
      res = max(res, x - m);
      m = min(m, x);
    }
    return res;
  }
};
