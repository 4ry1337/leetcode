#include <bits/stdc++.h>

using namespace std;

/*
 * link: https://leetcode.com/problems/rotate-image/
 *
 * BCR(O(N^2))
 *
 * solution 1 - brute force
 *
 * 1. create second matrix
 * 2. map everything
 * 3. return that matrix
 *
 * solution 2 - transpose
 *
 * 1. rotate matrix by second dioganal
 * 2. rotate matrix horizontally
 *
 * */

class Solution {
 public:
  void rotate(vector<vector<int>>& m) {
    int l = m.size();
    for (int i{}; i < l; ++i) {
      for (int j{}; j < l - 1 - i; ++j) {
        swap(m[i][j], m[l - 1 - j][l - 1 - i]);
      }
    }
    for (int i{}; i < l / 2; ++i) {
      for (int j{}; j < l; ++j) {
        swap(m[i][j], m[l - 1 - i][j]);
      }
    }
  }
};
