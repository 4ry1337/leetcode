/* link: https://leetcode.com/problems/partition-list/description/
 * BCR(O(N))
 *
 * solution 1 - two dummy lists:
 * 1. create two dummy-headed lists: small (< x) and great (>= x)
 * 2. iterate through the original list
 *    - if curr->val >= x: move node to great list
 *    - otherwise: advance through small list
 * 3. connect tail of small list to head of great list
 * 4. return small->next
 *
 * time: O(N) space: O(1)
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
  ListNode* partition(ListNode* head, int x) {
    ListNode *small = new ListNode(0, head), *prev = small, *curr = small->next;
    ListNode *great = new ListNode(0), *k = great;
    while (curr) {
      if (curr->val >= x) {
        k->next = curr;
        k = k->next;
        curr = curr->next;
        prev->next = curr;
      } else {
        prev = curr;
        curr = curr->next;
      }
    }
    curr = great->next;
    return small->next;
  }
};
