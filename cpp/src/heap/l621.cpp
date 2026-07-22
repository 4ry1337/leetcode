#include <bits/stdc++.h>

using namespace std;

/* https://leetcode.com/problems/task-scheduler */

class Solution {
 public:
  int leastInterval(vector<char>& tasks, int n) {
    int res = 0;
    array<int, 26> ts;
    for (auto& task : tasks) ts[task - 'A'];
    return res;
  }
};
