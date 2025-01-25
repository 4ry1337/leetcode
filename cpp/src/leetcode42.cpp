#include <vector>

using namespace std;

// space o(2n)
// time constant
class Solution {
public:
  int trap(vector<int> &height) {
    int length = height.size();
    vector<int> max_left(length);
    vector<int> max_right(length);
    int ml = 0, mr = 0;
    for (int i = 0; i < length; i++) {
      ml = max(ml, height[i]);
      mr = max(mr, height[length - 1 - i]);
      max_left[i] = ml;
      max_right[length - 1 - i] = mr;
    }
    int captured = 0;
    for (int i = 0; i < length; i++) {
      captured += min(max_left[i], max_right[i]) - height[i];
    }
    return captured;
  }
};

/*
space: O(1)
class Solution {
public:
  int trap(vector<int> &height) {
    int left = 0, right = height.size() - 1;
    int leftMax = 0, rightMax = 0;
    int waterTrapped = 0;

    while (left < right) {
      if (height[left] < height[right]) {
        if (height[left] >= leftMax) {
          leftMax = height[left];
        } else {
          waterTrapped += leftMax - height[left];
        }
        left++;
      } else {
        if (height[right] >= rightMax) {
          rightMax = height[right];
        } else {
          waterTrapped += rightMax - height[right];
        }
        right--;
      }
    }
    return waterTrapped;
  }
};
*/
