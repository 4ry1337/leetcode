#include <bits/stdc++.h>

using namespace std;

/* link: https://leetcode.com/problems/product-of-array-except-self/
 *
 * solution 1:
 * 1. init vector
 * 2. run nested loop
 * 3. write a product into a vector
 *
 * solution 2:
 * 1. init vector
 * 2. run loops
 * 3. create prefix and suffix
 * 4. multiply i's prefix and suffix
 *
 * solution 3:
 * 1. init result vector
 * 2.
 *
 * 1 2 3 4
 * 1 1 1 1
 * 1 1 2 6
 * 24 12 4 1
 * 24 12 8 6
 *
 * */

class Solution {
 public:
  vector<int> productExceptSelf(vector<int>& n) {
    vector<int> res(n.size());
    int pre = 1, post = 1;
    for (int i = 0; i < n.size(); ++i) {
      res[i] = pre;
      pre *= n[i];
    }
    for (int i = n.size() - 1; i >= 0; --i) {
      res[i] *= post;
      post *= n[i];
    }
    return res;
  }
};
