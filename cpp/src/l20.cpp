#include <stack>
#include <string>

using namespace std;

/* link: https://leetcode.com/problems/valid-parentheses */

class Solution {
 public:
  static auto isValid(const string& s) -> bool {
    stack<char> st;
    for (const auto& c : s) {
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
