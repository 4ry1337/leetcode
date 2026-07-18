#include <bits/stdc++.h>

using namespace std;

/* https://leetcode.com/problems/longest-mountain-in-array/ */
/* class Solution {
 public:
  int longestMountain(vector<int>& arr) {
    int res = 0, l = 0, r = 0;
    while (r < arr.size()) {
      l = r;
      while (r < arr.size() - 1 && arr[r] < arr[r + 1]) r++;
      while (r < arr.size() - 1 && arr[r] > arr[r + 1]) r++;
      if (r - l >= 3) res = max(r - l, res);
      r++;
    }
    return res;
  }
}; */

class Solution {
 public:
  int longestMountain(vector<int>& arr) {
    int res = 0;
    size_t l = 0;
    while (l < arr.size()) {
      size_t r = l;
      if (r < arr.size() - 1 && arr[r] < arr[r + 1]) {
        while (r < arr.size() - 1 && arr[r] < arr[r + 1]) r++;
        if (r < arr.size() - 1 && arr[r] > arr[r + 1]) {
          while (r < arr.size() - 1 && arr[r] > arr[r + 1]) r++;
          res = max((int)r - (int)l + 1, res);
        }
      }
      l = max(l + 1, r);
    }
    return res;
  }
};
