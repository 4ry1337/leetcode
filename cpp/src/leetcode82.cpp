#include <bits/stdc++.h>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *deleteDuplicates(ListNode *h) {
    ListNode *d = new ListNode(101, h), *slow = d, *fast = d->next,
             *prev = nullptr;

    while (fast != nullptr) {
      if (slow->val == fast->val) {
        while (fast != nullptr && slow->val == fast->val) {
          fast = fast->next;
        }
        prev->next = fast;
        slow = fast;
      } else {
        prev = slow;
        slow = slow->next;
      }
      if (fast != nullptr)
        fast = fast->next;
    }

    return d->next;
  }
};
