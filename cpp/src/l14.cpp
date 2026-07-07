#include <bits/stdc++.h>

using namespace std;

/* link: https://leetcode.com/problems/longest-common-prefix/description/
 * BCR(O(N))
 *
 * solution
 * create prefix string
 * iterate through string one index at a time and compare and append to prefix.
 * */

class Solution {
 public:
  string longestCommonPrefix(vector<string>& strs) {
    string res = "";
    for (int i{}; i < strs[0].size(); ++i) {
      char& c = strs[0][i];
      for (auto& str : strs) {
        if (i >= str.size() || str[i] != c) {
          return res;
        }
      }
      res += c;
    }
    return res;
  }
};
