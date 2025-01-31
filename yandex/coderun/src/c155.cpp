#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int task155() {
  int n;
  cin >> n;
  vector<int> a(n);
  unordered_map<int, int> freq;
  for (int &i : a) {
    cin >> i;
    freq[i]++;
  }

  int res = 0;

  for (auto const &[key, val] : freq) {
    if (val == 1) {
      res++;
    }
  }

  cout << res << endl;

  return 0;
}
