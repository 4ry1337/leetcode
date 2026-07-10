#include <bits/stdc++.h>

using namespace std;

class DinnerPlates {
 public:
  vector<int> stack;
  priority_queue<int, vector<int>, greater<int>> pq;
  int m_capacity;
  DinnerPlates(int capacity) : m_capacity(capacity) {}

  void push(int val) {
    while (stack.empty() && !pq.empty()) {
      pq.pop();
    }
    if (!pq.empty()) {
      stack[pq.top()] = val;
      pq.pop();
      return;
    }
    stack.push_back(val);
  }

  int pop() {
    if (stack.size() == 0) {
      return -1;
    }
    while (stack[stack.size() - 1] == -1) {
      stack.pop_back();
    }
    int temp = stack[stack.size() - 1];
    stack.pop_back();

    return temp;
  }

  int popAtStack(int index) {
    int end_index = index * m_capacity + m_capacity - 1;
    if (end_index >= stack.size()) return -1;
    int temp = -1;
    while (end_index >= index * m_capacity && temp == -1) {
      temp = stack[end_index--];
    }
    if (temp != -1) {
      pq.push(end_index + 1);
      stack[end_index + 1] = -1;
    }
    return temp;
  }
};
