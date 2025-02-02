#include <vector>

using namespace std;

class Solution {
public:
  void gameOfLife(vector<vector<int>> &board) {
    for (int i = 0; i < board.size(); i++) {
      for (int j = 0; j < board[0].size(); j++) {
        int n = neighbor(board, i, j);
        if (board[i][j] == 0) {
          if (n == 3) {
            board[i][j] = -1;
          }
        } else {
          if (n < 2 || n > 3) {
            board[i][j] = 2;
          }
        }
      }
    }
    for (int i = 0; i < board.size(); i++) {
      for (int j = 0; j < board[0].size(); j++) {
        if (board[i][j] == 2) {
          board[i][j] = 0;
        }
        if (board[i][j] == -1) {
          board[i][j] = 1;
        }
      }
    }
  }
  int neighbor(const vector<vector<int>> &board, int a, int b) {
    int res = 0;
    for (int i = -1; i <= 1; i++) {
      for (int j = -1; j <= 1; j++) {
        if (i == 0 && j == 0)
          continue;
        if (0 > a + i || 0 > b + j || board.size() <= a + i ||
            board[0].size() <= b + j)
          continue;
        if (board[a + i][b + j] > 0) {
          res++;
        }
      }
    }
    return res;
  }
};
