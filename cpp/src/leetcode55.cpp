#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  bool canJump(vector<int> &nums) {
    int length = nums.size();
    vector<bool> canJump(length, false);
    canJump[0] = true;
    for (int i = 0; i < length; i++) {
      if (canJump[i]) {
        for (int j = 0; j <= nums[i]; j++) {
          if (i + j < length) {
            canJump[i + j] = true;
          }
        }
      }
    }
    return canJump[length - 1];
  }
};

/*
// BETTER SOLUTION
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxa=0;
        for(int i=0;i<nums.size();i++){
            if(i>maxa) return false;
            maxa=max(maxa,nums[i]+i);
        }
        return true;
    }
};
*/
