#include <bits/stdc++.h>

using namespace std;

/* https://leetcode.com/problems/word-search */

class Solution {
 private:
  int rows, cols;

  bool dfs(vector<vector<char>>& board, string& word, int i, int j, int idx) {
    if (idx == word.size()) return true;
    if (i < 0 || j < 0 || i >= rows || j >= cols || board[i][j] != word[idx] ||
        board[i][j] == '#') {
      return false;
    }
    board[i][j] = '#';
    bool res = dfs(board, word, i, j + 1, idx + 1) ||
               dfs(board, word, i, j - 1, idx + 1) ||
               dfs(board, word, i + 1, j, idx + 1) ||
               dfs(board, word, i - 1, j, idx + 1);
    board[i][j] = word[idx];
    return res;
  }

 public:
  bool exist(vector<vector<char>>& board, string word) {
    rows = board.size();
    cols = board[0].size();

    for (int i{}; i < rows; ++i) {
      for (int j{}; j < cols; ++j) {
        if (board[i][j] == word[0] && dfs(board, word, i, j, 0)) {
          return true;
        }
      }
    }
    return false;
  }
};
