struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *reverseBetween(ListNode *head, int left, int right) {
    if (!head || left == right)
      return head;

    ListNode *dummy = new ListNode(0), *begin = dummy;
    dummy->next = head;

    for (int i = 0; i < left - 1; i++) {
      begin = begin->next;
    }
    ListNode *curr = begin->next;
    for (int i = 0; i < right - left; i++) {
      ListNode *next = curr->next;
      curr->next = next->next;
      next->next = begin->next;
      begin->next = next;
    }
    return dummy->next;
  }
};

/*
0 -> 1 -> 2 -> 3

*/
