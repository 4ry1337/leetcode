#include <bits/stdc++.h>

using namespace std;

/* https://leetcode.com/problems/sum-of-two-integrs/
 *
 *
 * intuition
 * we need to add two integers without using + or -.
 * binary addition can be built from two operations:
 *
 * 1. sum without carry: a ^ b gives the bit-by-bit sum ignoring carry (because
 * 1 ^ 1 = 0, which matches sum without carry)
 * 2. carry information: a & b tells us where both bits are 1, which creates a
 * carry shifting left by 1 (<< 1) moves that carry to the next higher bit
 *
 * so we can repeatedly:
 *
 * 1. compute the carry
 * 2. update the partial sum using xor
 * 3. add the carry again (by setting b = carry)
 * 4. we keep doing this until there is no carry left (b == 0).
 * */

class Solution {
 public:
  /* int getSum(int a, int b) {
    int res = 0;
    int carry = 0;
    for (int i = 0; i < 32; i++) {
      int bit_a = (a >> i) & 1;               // get ith bit from right
      int bit_b = (b >> i) & 1;               // get ith bit from right
      res |= ((bit_a ^ bit_b ^ carry) << i);  // set ith bit from right
      carry = (bit_a + bit_b + carry) > 1;    // calculate carry
    }
    return res;
  } */
  int getSum(int a, int b) {
    while (b != 0) {
      int carry = (a & b) << 1;
      a ^= b;
      b = carry;
    }
    return a;
  }
};
