#include <unordered_set>

using namespace std;

class Solution {
public:
  bool isHappy(int n) {
    unordered_set<int> visited;
    while (visited.count(n) == 0) {
      if (n == 1)
        return true;
      visited.insert(n);
      int res = 0;
      while (n > 0) {
        int x = n % 10;
        res += x * x;
        n /= 10;
      }
      n = res;
    }
    return false;
  }
};
