#include <bits/stdc++.h>

using namespace std;

/* link: https://leetcode.com/problems/reorder-list/
 *
 * solution 1 - vector
 * we store each node in extra vector
 * then reconnect them using that vector
 *
 * solution 2 -
 *
 * */

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
 public:
  void reorderList(ListNode* head) {
    ListNode *slow = head, *fast = head;
    while (fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;
    }
    ListNode *curr = slow, *prev = nullptr;
    while (curr != nullptr) {
      ListNode* next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
    }
    ListNode *h1 = head, *h2 = prev;
    while (h1->next != h2 && fast != h2) {
      ListNode *h1_next = h1->next, *h2_next = h2->next;

      h1->next = h2;
      h2->next = h1_next;

      h1 = h1_next;
      h2 = h2_next;
    }
  }
};
