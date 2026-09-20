#include <stack>

using namespace std;

/* link: https://leetcode.com/problems/implement-queue-using-stacks/
 *
 * solution:
 * use two stacks
 * one in right order second for reverse
 * reverse between then only when needed
 * */

class MyQueue {
 private:
  stack<int> A, B;

 public:
  MyQueue() = default;

  void push(int x) {
    while (!B.empty()) {
      A.push(B.top());
      B.pop();
    }
    A.push(x);
  }

  auto pop() -> int {
    while (!A.empty()) {
      B.push(A.top());
      A.pop();
    }
    int const val = B.top();
    B.pop();
    return val;
  }

  auto peek() -> int {
    while (!A.empty()) {
      B.push(A.top());
      A.pop();
    }
    return B.top();
  }

  auto empty() -> bool { return A.empty() || B.empty(); }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
