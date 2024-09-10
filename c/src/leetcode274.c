#include <stdio.h>
#include <stdlib.h>

int Max274(int a, int b) {
  if (a > b)
    return a;
  else
    return b;
}

int hIndex(int *citations, int citationsSize) {
  int max = 0, res = 0;
  for (int i = 0; i < citationsSize; i++) {
    max = Max274(max, citations[i]);
  }
  max++;
  int *countArray = (int *)calloc(max, sizeof(int));
  for (int i = 0; i < citationsSize; i++) {
    countArray[citations[i]]++;
  }
  for (int i = 0; i < max; i++) {
    if (citationsSize >= i) {
      res = Max274(res, i);
    }
    citationsSize -= countArray[i];
  }
  free(countArray);
  return res;
}

/*
int main(int argc, char *argv[]) {
  int arr[5] = {3, 0, 6, 1, 5};
  printf("%d", hIndex(arr, 5));
  return 0;
}
*/
