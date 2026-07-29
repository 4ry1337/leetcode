#include <bits/stdc++.h>

using namespace std;

/*
 * link: https://leetcode.com/problems/koko-eating-bananas/
 *
 * */

class Solution {
 public:
  int minEatingSpeed(vector<int>& p, int h) {
    int base = 1;
    int size = *max_element(p.begin(), p.end());
    while (size > 1) {
      int half = size / 2;
      int mid = base + half;
      long long val = 0;
      for (int x : p) val += ceil(static_cast<double>(x) / mid);
      if (val > h) base = mid;
      size -= half;
    }
    long long val = 0;
    for (int x : p) val += ceil(static_cast<double>(x) / base);
    return base + (val > h);
  }
};
