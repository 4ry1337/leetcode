#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
  bool closeStrings(string a, string b) {
    if (a.size() != b.size())
      return false;
    vector<int> fa(26, 0);
    vector<int> fb(26, 0);
    for (char c : a) {
      fa[c - 'a']++;
    }
    for (char c : b) {
      fb[c - 'a']++;
    }
    for (int i = 0; i < 26; i++) {
      if (fa[i] == 0 ^ fb[i] == 0)
        return false;
    }
    sort(fa.begin(), fa.end());
    sort(fb.begin(), fb.end());
    return fa == fb;
  }
};
