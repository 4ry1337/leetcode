#include <vector>

using namespace std;

class Solution {
public:
  int removeDuplicates(vector<int> &nums) {
    int k = 0;
    for (int i = 2; i < nums.size(); i++) {
      if (nums[i] == nums[i - 2 - k]) {
        k++;
      }
      nums[i - k] = nums[i];
    }
    return nums.size() - k;
  }
};
/*
1 1 1 1 2 2 2 3 k = 0
1 1 1 1 2 2 2 3 k = 1
1 1 1 1 2 2 2 3 k = 2
1 1 2 2 2 2 2 3 k = 2
1 1 2 2 2 2 2 3 k = 3
*/
