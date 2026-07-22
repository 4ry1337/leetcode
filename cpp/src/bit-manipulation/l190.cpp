#include <bits/stdc++.h>

using namespace std;

/* https://leetcode.com/problems/reverse-bits/ */

class Solution {
 public:
  /* int reverseBits(int n) {
    int res = n;
    for (int i = 0; i < 16; i++) {
      bool right = res & (1 << i), left = res & (1 << (31 - i));
      if (right)
        res |= (1 << (31 - i));
      else
        res &= ~(1 << (31 - i));
      if (left)
        res |= (1 << i);
      else
        res &= ~(1 << i);
    }
    return res;
  } */
  int reverseBits(int n) {
    int res = 0;
    for (int i = 0; i < 32; i++) {
      int bit = (n >> i) & 1;
      res += (bit << (31 - i));
    }
    return res;
  }
};
