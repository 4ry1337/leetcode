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
  ListNode *reverseKGroup(ListNode *head, int k) {
    int length = 0;
    for (ListNode *temp = head; temp != nullptr; temp = temp->next) {
      length++;
    }

    ListNode *prev = nullptr, *curr = head;

    while (length - k >= 0) {
      for (int i = 0; i < k; i++) {
        ListNode *next = curr->next;
        curr->next = prev;

        prev = curr;
        curr = next;
      }
      cout << prev->val << "\n";
      cout << curr->val << "\n";
    }

    return head;
  }
};

/*
1 -> 2 -> 3 -> 4 -> 5
k = 2
2 -> 1 -> 4 -> 3 -> 5
c
p
l r
 n
*/
