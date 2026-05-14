#include <bits/stdc++.h>

using namespace std;

int maxArea(vector<int>& height) {
  int l = 0;
  int r = height.size() - 1;
  int res = min(height[r], height[l]) * (r - l);

  while (l < r) {
    if (height[l] < height[r]) {
      l++;
    } else {
      r--;
    }

    res = max(res, min(height[r], height[l]) * (r - l));
  }

  return res;
}
