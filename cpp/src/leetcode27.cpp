#include <vector>

using namespace std;

class Solution {
public:
  int removeElement(vector<int> &nums, int val) {
    int j = 0;
    for (int i = 0; i < nums.size(); i++) {
      nums[i - j] = nums[i];
      if (nums[i] == val) {
        j++;
      }
    }
    return nums.size() - j;
  }
};
