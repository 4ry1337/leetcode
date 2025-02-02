#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  bool containsNearbyDuplicate(vector<int> &nums, int k) {
    unordered_map<int, int> mp;
    int l = 0, r = 0;
    for (; r < nums.size(); r++) {
      while (r - l > k) {
        mp[nums[l++]]--;
      }
      mp[nums[r]]++;
      if (mp[nums[r]] == 2) {
        return true;
      }
    }
    return false;
  }
};
