#include <bits/stdc++.h>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *partition(ListNode *head, int x) {
    ListNode *curr = head, *left = nullptr, *right = nullptr;
    while (curr != nullptr) {
      if (curr->val < x) {
      } else {
      }
    }
    return head;
  }
};
