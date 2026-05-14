#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int maxProfit(vector<int> &prices) {
    int m_res = 0, m_min = prices[0];
    for (int price : prices) {
      m_res = max(m_res, price - m_min);
      m_min = min(m_min, price);
    }
    return m_res;
  }
};
