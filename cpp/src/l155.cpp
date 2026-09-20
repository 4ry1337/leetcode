#include <algorithm>
#include <stack>
#include <utility>

using namespace std;

/* link: https://leetcode.com/problems/min-stack/description/ */

class MinStack {
 private:
  stack<pair<int, int>> m_data;

 public:
  MinStack() = default;

  void push(int val) {
    m_data.emplace(val, !m_data.empty() ? min(m_data.top().second, val) : val);
  }

  void pop() { m_data.pop(); }

  auto top() -> int { return m_data.top().first; }

  auto getMin() -> int { return m_data.top().second; }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
