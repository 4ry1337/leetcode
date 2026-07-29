#include <bits/stdc++.h>

using namespace std;

/* https://leetcode.com/problems/number-of-islands/
 *
 * solution 1 - brute force
 *
 *
 *
 * */

class Solution {
 public:
  int numIslands(vector<vector<char>>& grid) {
    int res = 0;
    size_t rows = grid.size(), cols = grid[0].size();
    queue<pair<int, int>> q;
    vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    for (size_t r{}; r < rows; ++r) {
      for (size_t c{}; c < cols; ++c) {
        if (grid[r][c] == '1') {
          q.push({r, c});
          grid[r][c] = 'v';
          while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            for (auto& dir : directions) {
              auto row = r + dir.first, col = c + dir.second;
              if (row >= 0 && row < rows && col >= 0 && col < cols &&
                  grid[row][col] == '1') {
                grid[row][col] = 'v';
                q.push({row, col});
              }
            }
          }
          res++;
        }
      }
    }
    return res;
  }
};
