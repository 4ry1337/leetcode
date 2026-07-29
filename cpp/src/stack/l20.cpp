#include <bits/stdc++.h>

using namespace std;

/* link: https://leetcode.com/problems/valid-parentheses */

class Solution {
 public:
  bool isValid(string s) {
    stack<char> st;
    for (auto& c : s) {
      if (!st.empty() &&
          ((st.top() == '{' && c == '}') || (st.top() == '[' && c == ']') ||
           (st.top() == '(' && c == ')'))) {
        st.pop();
      } else {
        st.push(c);
      }
    }
    return st.empty();
  }
};
