#include <bits/stdc++.h>

using namespace std;

/* https://leetcode.com/problems/letter-combinations-of-a-phone-number/ */

class Solution {
 private:
  vector<string> res;
  unordered_map<char, vector<char>> mp{
      {'2', {'a', 'b', 'c'}}, {'3', {'d', 'e', 'f'}},
      {'4', {'g', 'h', 'i'}}, {'5', {'j', 'k', 'l'}},
      {'6', {'m', 'n', 'o'}}, {'7', {'p', 'q', 'r', 's'}},
      {'8', {'t', 'u', 'v'}}, {'9', {'w', 'x', 'y', 'z'}},
  };
  void backtrack(string& digits, int idx, string& curr) {
    if (digits.size() == idx) {
      res.push_back(curr);
    }
    for (char& c : mp[digits[idx]]) {
      curr += c;
      backtrack(digits, idx + 1, curr);
      curr.pop_back();
    }
  }

 public:
  vector<string> letterCombinations(string digits) {
    string curr = "";
    backtrack(digits, 0, curr);
    return res;
  }
};
