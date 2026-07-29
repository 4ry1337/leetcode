#include <bits/stdc++.h>

using namespace std;

/* https://leetcode.com/problems/generate-parentheses */

class Solution {
 private:
  void backtrack(vector<string>& res, string& s, int n, int count) {
    if (s.size() == n * 2) {
      if (count == 0) {
        res.push_back(s);
      }
      return;
    }
    if (count < n) {
      s.push_back('(');
      backtrack(res, s, n, count + 1);
      s.pop_back();
    }
    if (count > 0) {
      s.push_back(')');
      backtrack(res, s, n, count - 1);
      s.pop_back();
    }
  }

 public:
  vector<string> generateParenthesis(int n) {
    vector<string> res;
    string s = "";
    backtrack(res, s, n, 0);
    return res;
  }
};
