#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

/*int jump(int *nums, int numsSize) {*/
/*  int *jumps = (int *)malloc(sizeof(int) * numsSize);*/
/*  for (int i = 0; i < numsSize; i++) {*/
/*    jumps[i] = INT_MAX;*/
/*  }*/
/*  jumps[0] = 0;*/
/*  for (int i = 0; i < numsSize; i++) {*/
/*    if (jumps[i] != INT_MAX) {*/
/*      for (int j = 0; j <= nums[i]; j++) {*/
/*        jumps[i + j] =*/
/*            jumps[i] + 1 < jumps[i + j] ? jumps[i] + 1 : jumps[i + j];*/
/*        if (i + j == numsSize - 1) {*/
/*          return jumps[numsSize - 1];*/
/*        }*/
/*      }*/
/*    }*/
/*  }*/
/*  return jumps[numsSize - 1];*/
/*}*/

int Max(int x, int y) {
  if (x < y) {
    return y;
  } else {
    return x;
  }
}

int jump(int *nums, int numsSize) {
  int timesOfJump = 0, lastJumpIndex = 0, curFar = 0;
  for (int i = 0; i < numsSize - 1; i++) {
    curFar = Max(curFar, i + nums[i]);
    if (i == lastJumpIndex) {
      lastJumpIndex = curFar;
      timesOfJump++;
      if (curFar >= numsSize - 1) {
        return timesOfJump;
      }
    }
  }
  return 0;
}

int main(int argc, char *argv[]) {
  int nums[5] = {2, 3, 1, 1, 4};
  int res = jump(nums, 5);
  printf("%d\n", res);
  return 0;
}

/*
int Max (int x, int y) {
    if (x < y) {
        return y;
    } else {
        return x;
    }
}

int jump(int* nums, int numsSize) {
    int timesOfJump=0, lastJumpIndex = 0, curFar = 0;
    for (int i = 0; i < numsSize-1; i++) {
        // Update the farthest reachable index of this jump.
        curFar = Max (curFar, i+nums[i]);
        // If we finish the starting range of this jump,
        // Move on to the starting range of the next jump.
        if (i == lastJumpIndex) {
            lastJumpIndex = curFar;
            timesOfJump++;
            //check if reached destination already
            if (curFar >= numsSize-1) {
                return timesOfJump;
            }
        }
    }
    return 0;
}
*/
