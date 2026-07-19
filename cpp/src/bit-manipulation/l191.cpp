#include <bits/stdc++.h>

using namespace std;

/* https://leetcode.com/problems/number-of-1-bits
 *
 * solution 1
 * 1. initialize a counter res = 0.
 * 2. for each bit position i from 0 to 31:
 * 3. create a mask with only the i-th bit set:
 *    - mask = 1 << i
 * 4. check if this bit is set in n:
 *    - if (mask & n) != 0, increment res
 * 5. after checking all 32 bits, return res.
 *
 * solution 2 - optimal
 * intuition: performing n & (n - 1) removes the rightmost 1 bit from n
 *
 * 1. initialize a counter res = 0.
 * 2. while n is not zero:
 *    - update n = n & (n - 1) to remove the rightmost 1 bit increment res by 1
 *    - when n becomes 0, all 1 bits have been removed.
 * 3. return res.
 * */

class Solution {
 public:
  /* int hammingWeight(int n) {
    int res = 0;
    for (int i = 0; i < 32; i++) {
      if ((1 << i) & n) res++;
    }
    return res;
  } */
  int hammingWeight(int n) {
    int res = 0;
    while (n) {
      n &= n - 1;
      res++;
    }
    return res;
  }
};
