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
  ListNode *reverseKGroup(ListNode *head, int k) {
    ListNode *dummy = new ListNode(-1), *begin = dummy;
    dummy->next = head;
    ListNode *curr = dummy->next;

    int length = 0;

    for (ListNode *temp = head; temp != nullptr; temp = temp->next) {
      length++;
    }

    while (length - k >= 0) {
      for (int i = 1; i < k; i++) {
        ListNode *next = curr->next;
        curr->next = next->next;
        next->next = begin->next;
        begin->next = next;
      }
      length -= k;
      begin = curr;
      curr = curr->next;
    }

    return dummy->next;
  }
};

/*
1 -> 2 -> 3 -> 4 -> 5
k = 2
2 -> 1 -> 4 -> 3 -> 5
c
p
l r
 n
*/
