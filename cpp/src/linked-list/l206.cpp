
using namespace std;

/* link: https://leetcode.com/problems/reverse-linked-list/
 * BCR(O(N))
 *
 * */

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  explicit ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
} __attribute__((aligned(16)));

class Solution {
 public:
  static auto reverseList(ListNode* head) -> ListNode* {
    ListNode* prev = nullptr;
    ListNode* curr = head;
    while (curr != nullptr) {
      ListNode* next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
    }
    return prev;
  }
};
