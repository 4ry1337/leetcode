#include "bits/stdc++.h"

using namespace std;

int task2() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;

  vector<long long> q(n);
  vector<int> c(n);
  long long sq = 0, sc = 0;

  for (int i = 0; i < n; ++i) {
    cin >> q[i];
    sq += q[i];
  }

  for (int i = 0; i < n; ++i) {
    cin >> c[i];
    sc += q[i] * c[i];
  }

  long long a, b;
  cin >> a >> b;

  long long res;
  if (a == b) {
    res = a * sq;
  } else {
    res = a * sq + (b - a) * sc / 255;
  }

  cout << res;

  return 0;
}
