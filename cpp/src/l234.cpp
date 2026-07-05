/* link: https://leetcode.com/problems/palindrome-linked-list/ */
struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
 public:
  bool isPalindrome(ListNode* head) {
    ListNode *prev = nullptr, *left = head, *right = head;

    while (right != nullptr && right->next != nullptr) {
      right = right->next->next;
      ListNode* next = left->next;
      left->next = prev;
      prev = left;
      left = next;
    }
    // acount for odd list
    if (right != nullptr) left = left->next;
    while (prev != nullptr && left != nullptr) {
      if (prev->val != left->val) return false;
      prev = prev->next;
      left = left->next;
    }
    return prev == nullptr || left == nullptr;
  }
};
