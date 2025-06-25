#include "bits/stdc++.h"

using namespace std;

// My solution
// Time: O(n)
// Space: O(n)
class Solution {
public:
  string removeStars(string s) {
    stack<char> st;
    for (const auto &x : s) {
      if (x == '*') {
        st.pop();
      } else {
        st.push(x);
      }
    }
    string res = "";
    while (st.size()) {
      res += st.top();
      st.pop();
    }
    reverse(res.begin(), res.end());
    return res;
  }
};

// Better solution

class Solution2 {
public:
  string removeStars(string s) {
    int pos = 0;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '*') {
        pos--;
      } else {
        s[pos++] = s[i];
      }
    }
    s.resize(pos);
    return s;
  }
};
