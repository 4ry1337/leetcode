/* link: https://leetcode.com/problems/middle-of-the-linked-list/ */

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  explicit ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *middleNode(ListNode *head) {
    ListNode *dummy = new ListNode(0, head);
    ListNode *slow = dummy;
    ListNode *fast = dummy;
    while ((fast != nullptr) && (fast->next != nullptr)) {
      slow = slow->next;
      fast = fast->next->next;
    }
    if (fast != nullptr) {
      return slow->next;
    }
    return slow;
  }
};
