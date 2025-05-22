#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  bool containsDuplicate(vector<int> &nums) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    unordered_set<int> s;
    for (const int &x : nums) {
      if (s.count(x) == 1) {
        return true;
      }
      s.insert(x);
    }
    return false;
  }
};
