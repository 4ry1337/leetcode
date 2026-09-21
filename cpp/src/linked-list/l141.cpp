#include <bits/stdc++.h>

using namespace std;

/* link: https://leetcode.com/problems/linked-list-cycle/description/
 *
 * solution 1 - hashset
 * triverse list
 * store pointers in hashset
 * when we find curr in hashset return true
 * if not we reach nullptr and return false
 *
 * solution 2 - fast and slow
 * fast runs two times faster than slow
 * eventually they will meet
 *
 * time: O(N)
 * space: O(1)
 * */

struct ListNode {
  int val;
  ListNode *next;
  explicit ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
  bool hasCycle(ListNode *head) {
    ListNode *slow = head;
    ListNode *fast = head;
    while ((fast != nullptr) && (fast->next != nullptr)) {
      slow = slow->next;
      fast = fast->next->next;
      if (slow == fast) {
        return true;
      }
    }
    return false;
  }
};
