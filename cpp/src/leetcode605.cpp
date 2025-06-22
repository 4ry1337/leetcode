#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
  bool canPlaceFlowers(vector<int> &flowerbed, int n) {
    int s = flowerbed.size(), count = 0;

    if (n == 0)
      return true;

    if (s < n)
      return false;

    for (int i = 0; i < flowerbed.size(); i++) {
      if (flowerbed[i] == 0) {
        int prev = (i == 0) ? 0 : flowerbed[i - 1];
        int next = (i == flowerbed.size() - 1) ? 0 : flowerbed[i + 1];

        if (prev == 0 && next == 0) {
          flowerbed[i] = 1;
          count++;
        }
      }
    }

    return count >= n;
  }
};
