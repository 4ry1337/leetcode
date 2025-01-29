#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

int task1(int argc, char *argv[]) {
  int r, c;
  cin >> r >> c;
  vector<vector<char>> matrix(r, vector<char>(c));
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      cin >> matrix[i][j];
    }
  }

  string res;

  for (int i = 0; i < r; i++) {
    string curr;
    for (int j = 0; j < c; j++) {
      if (matrix[i][j] != '#') {
        curr += matrix[i][j];
      } else {
        if (curr.size() >= 2) {
          if (res.empty() || curr < res) {
            res = curr;
          }
        }
        curr.clear();
      }
    }
    if (curr.size() >= 2) {
      if (res.empty() || curr < res) {
        res = curr;
      }
    }
  }

  for (int i = 0; i < c; i++) {
    string curr;
    for (int j = 0; j < r; j++) {
      if (matrix[j][i] != '#') {
        curr += matrix[j][i];
      } else {
        if (curr.size() >= 2) {
          if (res.empty() || curr < res) {
            res = curr;
          }
        }
        curr.clear();
      }
    }
    if (curr.size() >= 2) {
      if (res.empty() || curr < res) {
        res = curr;
      }
    }
  }

  cout << res << endl;

  return 0;
}
