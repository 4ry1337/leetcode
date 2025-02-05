#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
  int calculate(string s) {
    int res = 0;
    stack<int> st({0});
    for (char c : s) {
      if (isdigit(c)) {
        st.top() *= 10;
        st.top() += c - '0';
      }
      if (c == ' ') {
        st.push(0);
      }
    }
    while (st.empty()) {
      cout << st.top() << endl;
      st.pop();
    }
    return res;
  }
};
