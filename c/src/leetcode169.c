#include <stdlib.h>

int compare(const void *a, const void *b) { return (*(int *)a - *(int *)b); }

int majorityElement(int *nums, int numsSize) {
  qsort(nums, numsSize, sizeof(int), compare);
  return nums[numsSize / 2];
}

/*

int majorityElement(int *nums, int numsSize) {
  int res = nums[0];
  int count = 1;
  for (int i = 1; i < numsSize; i++) {
    if (nums[i] == candidate) {
      count++;
    } else {
      count--;
      if (count == 0) {
        res = nums[i];
        count = 1;
      }
    }
  }

  return res;
}

*/
