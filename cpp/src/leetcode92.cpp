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
    for (ListNode *curr = head; curr != nullptr; curr = curr->next) {
    }
  }
};

/*
0 -> 1 -> 2 -> 3

*/
