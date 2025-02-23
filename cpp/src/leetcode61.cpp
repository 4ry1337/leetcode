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
  ListNode *rotateRight(ListNode *head, int k) {
    ListNode *iter = head;
    int n = 0;
    while (iter->next != nullptr) {
      iter = iter->next;
      n++;
    }
    k = k %= ++n;

    iter->next = head;

    while (n - k == 0) {
      iter = iter->next;
      n--;
    }

    ListNode *dummy = iter->next;
    iter->next = nullptr;
    return dummy;
  }
};

/*
1 2 3 4 5 1 2 3 4 5
        i
1 2 3
  2

1   3
3 1 2
2 3 1
1 2 3
*/
