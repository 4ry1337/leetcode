/*
 * link: https://leetcode.com/problems/add-two-numbers/description/
 * */

#include <cstddef>

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
 public:
  /* ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
    ListNode *curr = headA, *res = nullptr;
    while (curr) {
      curr->val *= -1;
      curr = curr->next;
    }
    curr = headB;
    while (curr) {
      if (curr->val < 0) {
        res = curr;
        break;
      }
      curr = curr->next;
    }
    curr = headA;
    while (curr) {
      curr->val *= -1;
      curr = curr->next;
    }
    return res;
  } */
  // problems: 3 passes, modified values what if node.val is not posisitve
  // numbers?
  ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
    ListNode *a = headA, *b = headB;
    while (a != nullptr && b != nullptr) {
      if (a == b) return a;
      a = a->next;
      b = b->next;
      if (a == nullptr) {
        a = headB;
      } else if (b == nullptr) {
        b = headA;
      }
    }
    return nullptr;
  }
};
