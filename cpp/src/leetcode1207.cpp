#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
  bool uniqueOccurrences(vector<int> &a) {
    unordered_map<int, int> mp;
    for (int x : a)
      mp[x]++;
    unordered_set<int> s;
    for (const auto &[k, x] : mp) {
      if (s.find(x) != s.end())
        return false;
      s.insert(x);
    }
    return true;
  }
};
