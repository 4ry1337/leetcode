#include <bits/stdc++.h>

using namespace std;

/* https://leetcode.com/problems/palindrome-partitioning/ */

class Solution {
 private:
  vector<vector<string>> res;

  void backtrack(string& s, int i, int j, vector<string>& temp) {
    if (j >= s.size()) {
      if (i == j) {
        res.push_back(temp);
      }
      return;
    }
    if (isPalindrome(s, i, j)) {
      temp.push_back(s.substr(i, j - i + 1));
      backtrack(s, j + 1, j + 1, temp);
      temp.pop_back();
    }
    backtrack(s, i, j + 1, temp);
  }

  bool isPalindrome(string& word, int i, int j) {
    while (i < j) {
      if (word[i] != word[j]) {
        return false;
      }
      i++;
      j--;
    }
    return true;
  }

 public:
  vector<vector<string>> partition(string s) {
    vector<string> temp;
    backtrack(s, 0, 0, temp);
    return res;
  }
};
