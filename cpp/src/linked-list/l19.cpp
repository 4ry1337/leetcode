/* link:
 * https://leetcode.com/problems/remove-nth-node-from-end-of-list/?envType=problem-list-v2&envId=linked-list
 * BCR(O(N))
 *
 * solution 1: fast and slow
 *
 * make fast K distance from slow
 * move together untill fast reaches end
 * remove slow
 *
 * time: O(N)
 * space: O(1)
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
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    if (!head) return head;
    ListNode *dummy = new ListNode(0, head), *slow = dummy, *fast = dummy;
    while (fast) {
      fast = fast->next;
      if (n < 0) slow = slow->next;
      n--;
    }
    if (slow->next) {
      ListNode* temp = slow->next;
      slow->next = slow->next->next;
      delete temp;
    }
    ListNode* res = dummy->next;
    delete dummy;
    return res;
  }
};
