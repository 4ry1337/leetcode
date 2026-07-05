#include <bits/stdc++.h>
using namespace std;

/* link:
 * https://leetcode.com/problems/remove-duplicates-from-an-unsorted-linked-list
 * BCR(O(N))
 *
 * is linked list sorted?
 *
 * solution 1
 * have a temporary data structure that keeps track of all
 * duplicates and removed nodes that are dups
 *
 * time: O(N) space: O(N)
 *
 * solution 2 - runnner
 *
 * have two pointers one faster and one slower
 *
 * time: O(N^2) space: O(1)
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
  ListNode* deleteDuplicatesUnsorted(ListNode* head) {
    ListNode* dummy = new ListNode(0, head);
    ListNode *prev = dummy, *curr = head;
    while (curr) {
      int v = curr->val;

      bool dup = false;
      for (ListNode* r = curr->next; r; r = r->next) {
        if (v == r->val) {
          dup = true;
          break;
        }
      }
      if (dup) {
        ListNode* scan = prev;
        while (scan->next) {
          if (scan->next->val == v) {
            ListNode* scan_next = scan->next;
            scan->next = scan_next->next;
            delete scan_next;
          } else {
            scan = scan->next;
          }
        }
        curr = prev->next;
      } else {
        prev = curr;
        curr = curr->next;
      }
    }
    return dummy->next;
  }
};
