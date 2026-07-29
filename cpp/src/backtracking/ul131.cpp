#include <bits/stdc++.h>

using namespace std;

/* https://leetcode.com/problems/palindrome-partitioning/ */

class Solution {
 private:
  vector<vector<string>> res;
  void backtrack(vector<string> partition, string& s, int idx) {
    if (idx == s.size()) return;
  };

 public:
  vector<vector<string>> partition(string s) { return res; }
};
