#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  string decodeString(string s) {
    stack<string> st;
    st.push("");
    int curr = 0;
    while (curr < s.size()) {
      if (s[curr] == '[') {
        st.push("");
        curr++;
        continue;
      }
      if (s[curr] == ']') {
        string temp = st.top();
        st.pop();
        string digit = st.top();
        st.pop();
        int d = stoi(digit);
        if (st.empty())
          st.push("");
        for (int i = 0; i < d; i++)
          st.top() += temp;
        curr++;
        continue;
      }
      if (!isdigit(st.top()[0]) && isdigit(s[curr])) {
        st.push("");
        st.top() += s[curr++];
        continue;
      }
      st.top() += s[curr++];
    }
    return st.top();
  }
};
