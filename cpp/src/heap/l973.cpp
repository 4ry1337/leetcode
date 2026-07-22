#include <bits/stdc++.h>

using namespace std;

/* https://leetcode.com/problems/find-k-closest-elements/description/ */

class Solution {
 public:
  vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    priority_queue<vector<int>, vector<vector<int>>,
                   decltype([](const vector<int>& a, const vector<int>& b) {
                     return (a[0] * a[0]) + (a[1] * a[1]) <
                            (b[0] * b[0]) + (b[1] * b[1]);
                   })>
        pq;
    for (auto& point : points) {
      pq.push(point);
      if (pq.size() > k) pq.pop();
    }
    vector<vector<int>> res;
    while (!pq.empty()) {
      res.push_back(pq.top());
      pq.pop();
    }
    return res;
  }
};
