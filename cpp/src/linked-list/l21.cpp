#include <bits/stdc++.h>

using namespace std;

/* link: https://leetcode.com/problems/merge-two-sorted-lists */

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

/* ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
  ListNode *dummy = new ListNode(0), *curr = dummy;
  while (list1 != nullptr || list2 != nullptr) {
    int val1 = list1 == nullptr ? INT_MAX : list1->val;
    int val2 = list2 == nullptr ? INT_MAX : list2->val;
    if (val1 > val2) {
      curr->next = new ListNode(val2);
      list2 = list2->next;
    } else {
      curr->next = new ListNode(val1);
      list1 = list1->next;
    }
    curr = curr->next;
  }
  ListNode* res = dummy->next;
  delete dummy;
  return res;
} */

class Solution {
 public:
  ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode *dummy = new ListNode(0), *curr = dummy;
    while (list1 != nullptr && list2 != nullptr) {
      if (list1->val < list2->val) {
        curr->next = list1;
        list1 = list1->next;
      } else {
        curr->next = list2;
        list2 = list2->next;
      }
      curr = curr->next;
    }
    if (list1 != nullptr)
      curr->next = list1;
    else
      curr->next = list2;

    ListNode* res = dummy->next;
    delete dummy;
    return res;
  }
};
