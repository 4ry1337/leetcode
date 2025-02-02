#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
  int longestConsecutive(vector<int> &nums) {
    unordered_set<int> ns(nums.begin(), nums.end());
    int res = 0;
    for (auto n : ns) {
      if (ns.find(n - 1) != ns.end())
        continue;
      int temp = 1;
      while (ns.find(++n) != ns.end())
        temp++;
      res = max(res, temp);
    }
    return res;
  }
};
