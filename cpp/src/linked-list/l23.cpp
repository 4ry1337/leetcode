#include <vector>

using namespace std;

/* link: https://leetcode.com/problems/merge-k-sorted-lists/
 *
 * solution
 * think like stride reduction pattern and merging tow lists
 * and it also can be parallelised
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
  static auto merge(ListNode* l1, ListNode* l2) -> ListNode* {
    ListNode* dummy = new ListNode(0);
    ListNode* curr = dummy;
    while (l1 != nullptr && l2 != nullptr) {
      if (l1->val < l2->val) {
        curr->next = l1;
        l1 = l1->next;
      } else {
        curr->next = l2;
        l2 = l2->next;
      }
      curr = curr->next;
    }
    if (l1 != nullptr) {
      curr->next = l1;
    } else {
      curr->next = l2;
    }
    ListNode* res = dummy->next;
    delete dummy;
    return res;
  }

  auto mergeKLists(vector<ListNode*>& lists) -> ListNode* {
    if (lists.empty()) {
      return nullptr;
    }

    for (int step = 1; step < lists.size(); step *= 2) {
      for (int i{}; i + step < lists.size(); i += step * 2) {
        lists[i] = merge(lists[i], lists[i + step]);
      }
    }

    return lists[0];
  }
};
