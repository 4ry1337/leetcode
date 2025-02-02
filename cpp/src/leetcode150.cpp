#include <stack>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  int evalRPN(vector<string> &tokens) {
    stack<int> st;

    for (const string &s : tokens) {
      if (s.size() == 1 && (s == "+" || s == "-" || s == "*" || s == "/")) {
        int right = st.top();
        st.pop();
        int left = st.top();
        st.pop();

        switch (s[0]) {
        case '+':
          st.push(left + right);
          break;
        case '-':
          st.push(left - right);
          break;
        case '*':
          st.push(left * right);
          break;
        case '/':
          st.push(left / right);
          break;
        }
      } else {
        st.push(stoi(s));
      }
    }
    return st.top();
  }
};
