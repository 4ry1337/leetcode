#include <vector>

using namespace std;

class Solution {
public:
  vector<int> spiralOrder(vector<vector<int>> &matrix) {
    vector<int> res;
    int l = 0, r = matrix[0].size() - 1, t = 0, b = matrix.size() - 1;
    while (l <= r && t <= b) {
      int i = l;
      while (i <= r) {
        res.push_back(matrix[t][i]);
        i++;
      }
      i = ++t;
      while (i <= b) {
        res.push_back(matrix[i][r]);
        i++;
      }
      --r;
      if (t <= b) {
        i = r;
        while (i >= l) {
          res.push_back(matrix[b][i]);
          i--;
        }
        --b;
      }

      if (l <= r) {
        i = b;
        while (i >= t) {
          res.push_back(matrix[i][l]);
          i--;
        }
        ++l;
      }
    }
    return res;
  }
};
