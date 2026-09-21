#include <bits/stdc++.h>

using namespace std;

/*
 * link: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/ */

class Solution {
public:
  int findMin(vector<int> &n) {
    int base = 0;
    int size = n.size();
    while (size > 1) {
      int const half = size / 2;
      int const mid = base + half;
      if (n[base] < n[mid]) {
        base = mid;
      }
      size -= half;
    }
    return n[(base + 1) % n.size()];
  }
};
