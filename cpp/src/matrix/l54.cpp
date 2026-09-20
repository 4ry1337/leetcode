#include <utility>
#include <vector>

using namespace std;

/* https://leetcode.com/problems/spiral-matrix/
 *
 * solution 1 - iterative optimal
 *
 * */

class Solution {
 public:
  static auto spiralOrder(vector<vector<int>>& matrix) -> vector<int> {
    vector<int> res;
    vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    vector<int> steps = {static_cast<int>(matrix[0].size()),
                         static_cast<int>(matrix.size()) - 1};
    int r = 0;
    int c = -1;
    int d = 0;
    while (steps[d % 2] != 0) {
      for (int i = 0; i < steps[d % 2]; i++) {
        r += directions[d].first;
        c += directions[d].second;
        res.push_back(matrix[r][c]);
      }
      steps[d % 2]--;
      d = (d + 1) % 4;
    }
    return res;
  }
};
