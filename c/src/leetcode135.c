#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int candy(int *ratings, int ratingsSize) {
  int *can = (int *)calloc(ratingsSize, sizeof(int));
  for (int i = 0; i < ratingsSize; i++) {
    can[i] = 1;
  }

  for (int i = 1; i < ratingsSize; i++) {
    if (ratings[i - 1] < ratings[i]) {
      can[i] += can[i - 1];
    }
  }
  for (int i = ratingsSize - 2; i >= 0; i--) {
    if (ratings[i] > ratings[i + 1] && can[i] <= can[i + 1]) {
      can[i] = can[i + 1];
    }
  }

  int count = 0;
  for (int i = 0; i < ratingsSize; i++) {
    count += can[i];
  }
  return count;
}
