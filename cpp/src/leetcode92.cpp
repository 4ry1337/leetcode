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

    ListNode *dummy = new ListNode(0), *prev = dummy;
    dummy->next = head;
    for (int i = 0; i < left - 1; i++) {
      prev = prev->next;
    }

    ListNode *curr = prev->next;

    for (int i = 0; i < right - left; i++) {
      ListNode *next = curr->next;
      curr->next = next->next;

      next->next = prev->next;
      prev->next = next;
    }

    return dummy->next;
  }
};

/*
0 -> 1 -> 2 -> 3

*/
