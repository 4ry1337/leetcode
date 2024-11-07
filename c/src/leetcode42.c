#include <stdio.h>
int trap(int *height, int heightSize) {
  int lres = 0, rres = 0, max = height[0], maxids = 0;

  for (int i = 1; i < heightSize; i++) {
    if (height[i] >= max) {
      max = height[i];
      maxids = i;
    }
  }

  int l = 0, r = 1, count = 0;

  for (r = 1; r <= maxids; r++) {
    if (height[l] <= height[r]) {
      lres += height[l] * (r - l - 1) - count;
      l = r;
      count = 0;
    } else {
      count += height[r];
    }
  }

  printf("%d\n", lres);

  l = heightSize - 2, r = heightSize - 1, count = 0;
  for (l = heightSize - 2; l >= maxids; l--) {
    if (height[r] <= height[l]) {
      rres += height[r] * (r - l - 1) - count;
      r = l;
      count = 0;
    } else {
      count += height[l];
    }
  }

  printf("%d\n", rres);
  return lres + rres;
}
