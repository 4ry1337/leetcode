#include <bits/stdc++.h>
using namespace std;

/* link: https://leetcode.com/problems/set-matrix-zeroes/
 *
 * solution 1:
 * we copy whole matrix and have original as reference
 *
 * solution 2:
 *
 * use simple data structure to store 0's and refernce it to convert rows and
 * columns
 *
 * solution 3:
 * set rows first
 * read each position in row if 0 make it 1 and make other places 0 continue
 * then do same for columns but check if line is 0 where is 1 make 1
 * no.
 * what if matrix comes 0 1
 * wait then we make whole linex 11110111
 * and then do dolummns result be different not a problem but how it is supposed
 * to be?
 *
 * store results of first col and row and mark them with 0s if need to be turned
 *
 * */

class Solution {
 public:
  void setZeroes(vector<vector<int>>& m) {
    int r = m.size();
    int c = m[0].size();
    bool row = false;
    bool col = false;
    for (int i{}; i < r; ++i) {
      if (m[i][0] == 0) {
        col = true;
        break;
      };
    }
    for (int i{}; i < c; ++i) {
      if (m[0][i] == 0) {
        row = true;
        break;
      }
    }
    for (int i = 0; i < r; ++i) {
      for (int j = 0; j < c; ++j) {
        if (m[i][j] == 0) {
          m[i][0] = 0;
          m[0][j] = 0;
        }
      }
    }
    for (int i = 1; i < r; ++i) {
      for (int j = 1; j < c; ++j) {
        if (m[i][0] == 0 || m[0][j] == 0) {
          m[i][j] = 0;
        }
      }
    }
    if (col) {
      for (int i{}; i < r; ++i) {
        m[i][0] = 0;
      }
    }
    if (row) {
      for (int i{}; i < c; ++i) {
        m[0][i] = 0;
      }
    }
  }
};

/* int main() {
  Solution sol;
  vector<vector<int>> m = {
      {0, 1, 2, 0},
      {3, 4, 5, 2},
      {1, 3, 1, 5},
  };
  sol.setZeroes(m);
  for (auto v : m) {
    for (auto i : v) {
      cout << i << " ";
    }
    cout << "\n";
  }
} */
