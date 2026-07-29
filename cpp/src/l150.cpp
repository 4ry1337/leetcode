#include <bits/stdc++.h>

using namespace std;

/*
 * link: https://leetcode.com/problems/evaluate-reverse-polish-notation/
 * */

class Solution {
 public:
  int val(string& t) {
    if (t.empty()) return 0;
    int res = 0, i = t[0] == '-' ? 1 : 0;
    for (; i < t.size(); ++i) {
      res *= 10;
      res += t[i] - '0';
    }
    return res * (t[0] == '-' ? -1 : 1);
  }
  pair<int, int> top2(stack<int>& st) {
    int a = st.top();
    st.pop();
    int b = st.top();
    st.pop();
    return {a, b};
  }
  int evalRPN(vector<string>& tokens) {
    stack<int> st;
    for (auto& t : tokens) {
      if (t == "+") {
        auto [a, b] = top2(st);
        st.push(b + a);
      } else if (t == "-") {
        auto [a, b] = top2(st);
        st.push(b - a);
      } else if (t == "*") {
        auto [a, b] = top2(st);
        st.push(b * a);
      } else if (t == "/") {
        auto [a, b] = top2(st);
        st.push(b / a);
      } else {
        st.push(val(t));
      }
    }
    return st.top();
  }
};
