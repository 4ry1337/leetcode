#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int task2() {
  int n, b;
  cin >> n >> b;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  int result = 0;

  int index = -1;
  for (int i = 0; i < n; ++i) {
    if (a[i] == b) {
      index = i;
      break;
    }
  }

  int balance = 0;
  unordered_map<int, int> count;
  count[0] = 1;

  for (int i = 0; i < n; ++i) {
    if (a[i] < b) {
      balance--;
    } else if (a[i] > b) {
      balance++;
    }

    if (i >= index) {
      result += count[balance];
    } else {
      count[balance]++;
    }
  }

  cout << result << endl;

  return 0;
}
