#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

int task4() {
  int n;
  string s;
  cin >> n >> s;

  if (n % 2 != 0) {
    cout << 0 << endl;
    return 0;
  }

  vector<vector<long long>> dp(n, vector<long long>(n, 0));

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < i; ++j) {
      dp[i][j] = 1;
    }
  }

  vector<pair<char, char>> brackets = {{'(', ')'}, {'[', ']'}, {'{', '}'}};

  for (int len = 2; len <= n; len += 2) {
    for (int i = 0; i + len <= n; ++i) {
      int j = i + len - 1;

      int ways = 0;
      for (auto &br : brackets) {
        char open = br.first;
        char close = br.second;
        if ((s[i] == open || s[i] == '?') && (s[j] == close || s[j] == '?')) {
          ways++;
        }
      }

      if (i + 1 <= j - 1) {
        dp[i][j] = (dp[i][j] + ways * dp[i + 1][j - 1]) % MOD;
      } else {
        dp[i][j] = (dp[i][j] + ways) % MOD;
      }

      for (int k = i; k < j; ++k) {
        dp[i][j] = (dp[i][j] + dp[i][k] * dp[k + 1][j]) % MOD;
      }
    }
  }

  cout << dp[0][n - 1] % MOD << endl;

  return 0;
}
