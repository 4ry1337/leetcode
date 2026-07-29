#include <bits/stdc++.h>

using namespace std;

/*
 * link: https://leetcode.com/problems/search-in-rotated-sorted-array/
 * */

class Solution {
 public:
  int search(vector<int>& n, int t) {
    int base = 0, size = n.size();
    while (size > 1) {
      int half = size / 2;
      int mid = base + half;
      if (n[mid] == t)
        return mid;
      else if ((n[0] <= t && n[0] <= n[mid] && n[mid] < t) ||
               (n[0] > t && (n[0] <= n[mid] || n[0] > n[mid] && t > n[mid]))) {
        base = mid;
      }
      size -= half;
    }
    cout << n[base];
    if (n[base] == t) return base;
    return -1;
  }
};
