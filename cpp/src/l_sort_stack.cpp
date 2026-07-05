#include <bits/stdc++.h>

#include <cassert>
#include <stack>
using namespace std;

/*  */

void sort_stack(stack<int>& s) {
  stack<int> sorted, helper;
  while (!s.empty()) {
    while (!sorted.empty() && sorted.top() < s.top()) {
      helper.push(sorted.top());
      sorted.pop();
    }
    sorted.push(s.top());
    s.pop();
    while (!helper.empty()) {
      sorted.push(helper.top());
      helper.pop();
    }
  }
  s = sorted;
}

int main() {
  stack<int> a({1, 2, 3});
  sort_stack(a);
  assert(a == stack<int>({3, 2, 1}));
  stack<int> b({3, 2, 1});
  sort_stack(b);
  assert(b == stack<int>({3, 2, 1}));
  stack<int> c({1, 4, 2, 3});
  sort_stack(c);
  assert(c == stack<int>({4, 3, 2, 1}));
  stack<int> d({1, 6, 5, 2, 3});
  sort_stack(d);
  assert(d == stack<int>({6, 5, 3, 2, 1}));
  stack<int> e({1, 5, 6, 2, 3});
  sort_stack(e);
  assert(e == stack<int>({6, 5, 3, 2, 1}));
}
