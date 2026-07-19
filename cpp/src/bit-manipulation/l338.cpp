#include <bits/stdc++.h>

using namespace std;

/* https://leetcode.com/problems/counting-bits/
 *
 * solution 1 - builtin
 * use __builtin_pocount to find 1's in number
 * iterate use function and push
 *
 * solution 2 - dp
 *
 * 0  = 0000 - 0
 * 1  = 0001 - 1 1 + dp[1 - 1 = 0] = 0
 * 2  = 0010 - 1 1 + dp[2 - 2 = 0] = 0
 * 3  = 0011 - 2 1 + dp[3 - 2 = 1] = 1
 * 4  = 0100 - 1 1+dp[0]
 * 5  = 0101 - 2 1+dp[1]
 * 6  = 0110 - 2 1+dp[2]
 * 7  = 0111 - 3 1+dp[3]
 * 8  = 1000 - 1
 *
 * 1. create a dp array dp of size n + 1
 *    - dp[i] will store the number of set bits in i
 * 2. initialize:
 *    - dp[0] = 0
 *    - offset = 1 (tracks the most recent power of two)
 * 3. for each number i from 1 to n:
 *    - if i reaches the next power of two (i == 2 * offset) update offset = i
 *    - compute: dp[i] = 1 + dp[i - offset]
 *
 * */

class Solution {
 public:
  /* vector<int> countBits(int n) {
    vector<int> res;
    for (int i{}; i <= n; ++i) res.push_back(__builtin_popcount(i));
    return res;
  } */
  vector<int> countBits(int n) {
    vector<int> res(n + 1);
    for (int i = 1; i <= n; ++i) {
      int offset = 1;
      while (offset * 2 <= i) offset *= 2;
      res[i] = 1 + res[i - offset];
    }
    return res;
  }
};
