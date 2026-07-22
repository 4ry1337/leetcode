#include <bits/stdc++.h>

using namespace std;

/* https://leetcode.com/problems/last-stone-weight */

class Solution {
 public:
  int lastStoneWeight(vector<int>& stones) {
    priority_queue<int> pq(stones.begin(), stones.end());
    while (pq.size() > 1) {
      int h1 = pq.top();
      pq.pop();
      int h2 = pq.top();
      pq.pop();
      int new_stone = h1 - h2;
      if (new_stone) pq.push(new_stone);
    }
    return pq.empty() ? 0 : pq.top();
  }
};
