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
  ListNode *deleteDuplicates(ListNode *head) {
    ListNode *dummy = new ListNode(0, head), *left = dummy,
             *right = dummy->next;
    while (right != nullptr) {
      if (left->val != right->val) {
        left->next = right;
        left = right;
      }
      right = right->next;
    }
    return dummy->next;
  }
};
