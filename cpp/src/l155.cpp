/* link: https://leetcode.com/problems/min-stack/description/ */

#include <bits/stdc++.h>

#include <algorithm>
#include <utility>

using namespace std;
class MinStack {
 private:
  vector<std::pair<int, int>> m_data;

 public:
  MinStack() {}

  void push(int value) {
    int m = m_data.empty() ? value : getMin();
    m_data.push_back(make_pair(value, min(value, m)));
  }

  void pop() { m_data.pop_back(); }

  int top() { return m_data[m_data.size() - 1].first; }

  int getMin() { return m_data[m_data.size() - 1].second; }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
