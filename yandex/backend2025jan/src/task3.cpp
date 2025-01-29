#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

int task3() {
  int n;
  cin >> n;
  vector<int> a(n), b(n), c(n);
  for (int i = 0; i < n; ++i)
    cin >> a[i];
  for (int i = 0; i < n; ++i)
    cin >> b[i];
  for (int i = 0; i < n; ++i)
    cin >> c[i];

  unordered_set<int> setA(a.begin(), a.end());
  unordered_set<int> setB(b.begin(), b.end());
  unordered_set<int> setC(c.begin(), c.end());

  unordered_set<int> common;
  for (int event : setA) {
    if (setB.count(event) && setC.count(event)) {
      common.insert(event);
    }
  }

  int count = 0;
  for (int i = 0; i < n; i++) {
    if (!common.count(a[i]) || !common.count(b[i]) || !common.count(c[i])) {
      common.erase(a[i]);
      count++;
    }
  }

  cout << count << endl;

  return 0;
}
