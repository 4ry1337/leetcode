#include <vector>

using namespace std;

class Solution {
public:
  void setZeroes(vector<vector<int>> &matrix) {
    bool row = false;
    bool col = false;

    for (int c = 0; c < matrix[0].size(); c++) {
      if (matrix[0][c] == 0) {
        row = true;
        break;
      }
    }

    for (int r = 0; r < matrix.size(); r++) {
      if (matrix[r][0] == 0) {
        col = true;
        break;
      }
    }

    for (int i = 0; i < matrix.size(); i++) {
      for (int j = 0; j < matrix[0].size(); j++) {
        if (matrix[i][j] == 0) {
          matrix[0][j] = 0;
          matrix[i][0] = 0;
        }
      }
    }
    for (int i = 1; i < matrix.size(); i++) {
      for (int j = 1; j < matrix[0].size(); j++) {
        if (matrix[i][0] == 0 || matrix[0][j] == 0) {
          matrix[i][j] = 0;
        }
      }
    }
    if (row) {
      for (int i = 0; i < matrix[0].size(); i++)
        matrix[0][i] = 0;
    }
    if (col) {
      for (int i = 0; i < matrix.size(); i++)
        matrix[i][0] = 0;
    }
  }
};
