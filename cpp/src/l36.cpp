#include <bits/stdc++.h>

using namespace std;

/* link: https://leetcode.com/problems/valid-sudoku/
 *
 *
 * */

class Solution {
 public:
  bool isValidSudoku(vector<vector<char>>& board) {
    array<array<int, 9>, 9> rows;
    array<array<int, 9>, 9> cols;
    // array<, 9> grid;
    for (int i{}; i < 9; ++i) {
      for (int j{}; j < 9; ++j) {
        if (rows[i][board[i][j]]++ > 1) return false;
        if (cols[j][board[i][j]]++ > 1) return false;
      }
    }
  }
};
