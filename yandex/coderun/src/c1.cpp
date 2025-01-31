#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int task1() {
  vector<int> arr(3);
  for (int &i : arr) {
    std::cin >> i;
  }
  sort(arr.begin(), arr.end());
  cout << arr[1] << endl;
  return 0;
}
