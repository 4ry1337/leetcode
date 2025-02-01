#include <vector>

using namespace std;

class Solution {
public:
  void rotate(vector<vector<int>> &matrix) {
    int n = matrix.size() - 1;
    for (int layer = 0; layer < matrix.size() / 2; layer++) {
      for (int index = layer; index < n - layer; index++) {
        int temp = matrix[layer][index];
        matrix[layer][index] = matrix[index][n - layer];
        matrix[index][n - layer] = temp;

        temp = matrix[layer][index];
        matrix[layer][index] = matrix[n - index][layer];
        matrix[n - index][layer] = temp;

        temp = matrix[n - index][layer];
        matrix[n - index][layer] = matrix[n - layer][n - index];
        matrix[n - layer][n - index] = temp;
      }
    }
  }
};
