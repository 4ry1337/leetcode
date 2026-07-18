#include <bits/stdc++.h>

using namespace std;

/* link: https://leetcode.com/problems/valid-sudoku/
 *
 * solution 1 brute force
 * 1. first loop, init freq map
 * 2. nested loop 1 through each row calculate freq in a row if any more than 1
 * return false
 * 3. nested loop 2 for col
 * 4. separete 3 nested loops going thourgh each 3x3 cell doing the same
 *
 * solution 2 one pass
 * 1. create freq matrices 9x9 for each rows and cols, and 3x3x3 for cells
 * 2. iteratre through matrix
 *  - calculate freq if more than 1 early return
 *  - for cells use index / 3. it would land in needed 3x3 check box and do
 *  thesame
 *
 *  time: O(N^2) space: O(N)
 *  it is faster only one iteration
 * */

class Solution {
 public:
  bool isValidSudoku(vector<vector<char>>& board) {
    array<array<int, 9>, 9> rows;
    array<array<int, 9>, 9> cols;
    array<array<array<int, 9>, 3>, 3> grid;
    for (int i{}; i < 9; ++i) {
      for (int j{}; j < 9; ++j) {
        if (board[i][j] == '.') continue;
        if (++rows[i][board[i][j] - '1'] > 1) return false;
        if (++cols[j][board[i][j] - '1'] > 1) return false;
        if (++grid[i / 3][j / 3][board[i][j] - '1'] > 1) return false;
      }
    }
    return true;
  }
};
