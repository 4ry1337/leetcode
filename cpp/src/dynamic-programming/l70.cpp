#include <bits/stdc++.h>

using namespace std;

/* https://leetcode.com/problems/climbing-stairs/
 *
 * n = 2
 * 1 + 1 = 2
 * 2 = 2
 * res = 2
 *
 * n = 3
 * 1 + 1 + 1
 * 1 + 2
 * 2 + 1
 * res = 3
 *
 * n = 4
 * 1 + 1 + 1 + 1
 * 1 + 1 + 2
 * 1 + 2 + 1
 * 2 + 1 + 1
 * 2 + 2
 * res = 5
 * */

class Solution {
 public:
  int climbStairs(int n) {
    int pp = 1;
    int p = 1;
    for (int i; i < n - 1; ++i) {
      int prev = p;
      p += pp;
      pp = prev;
    }
    return p;
  }
};
