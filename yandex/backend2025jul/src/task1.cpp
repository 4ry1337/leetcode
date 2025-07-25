#include "bits/stdc++.h"

using namespace std;

int task1() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  short int n, m, x, y;
  cin >> n >> m >> x >> y;
  int half = ceil((double)(x * y) / 2.0);
  int rows = n * x;
  int cols = m * y;
  vector<vector<char>> a(rows, vector<char>(cols));

  int res = 0;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      cin >> a[i][j];
    }
  }

  for (int i = 0; i < rows; i += x) {
    for (int j = 0; j < cols; j += y) {
      int check = 0;
      for (int k = 0; k < x; k++) {
        for (int l = 0; l < y; l++) {
          if (a[i + k][j + l] == 'X')
            check++;
        }
      }
      if (check >= half)
        res++;
    }
  }
  cout << res;
}
