#include <vector>

using namespace std;

/*
class Solution {
public:
  bool isValidSudoku(vector<vector<char>> &board) {
    unordered_set<int> digits(
        {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'});
    for (int i = 0; i < 9; i++) {
      unordered_set<int> temp = digits;
      for (int j = 0; j < 9; j++) {
        if (board[i][j] != '.') {
          if (temp.contains(board[i][j])) {
            temp.erase(board[i][j]);
          } else {
            return false;
          }
        }
      }
      temp = digits;
      for (int j = 0; j < 9; j++) {
        if (board[j][i] != '.') {
          if (temp.contains(board[j][i])) {
            temp.erase(board[j][i]);
          } else {
            return false;
          }
        }
      }
    }
    for (int i = 1; i < 9; i += 3) {
      for (int j = 1; j < 9; j += 3) {
        unordered_set<int> temp = digits;
        for (int k = -1; k <= 1; k++) {
          for (int m = -1; m <= 1; m++) {
            if (board[i + k][j + m] != '.') {
              if (temp.contains(board[i + k][j + m])) {
                temp.erase(board[i + k][j + m]);
              } else {
                return false;
              }
            }
          }
        }
      }
    }
    return true;
  }
};*/

class Solution {
public:
  bool isValidSudoku(vector<vector<char>> &board) {
    int rows[9][9] = {0};
    int columns[9][9] = {0};
    int box[3][3][9] = {0};

    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
        if (board[i][j] == '.') {
          continue;
        } else {
          if (rows[i][board[i][j] - '1']++)
            return false;
          if (columns[j][board[i][j] - '1']++)
            return false;
          if (box[i / 3][j / 3][board[i][j] - '1']++)
            return false;
        }
      }
    }
    return true;
  }
};
