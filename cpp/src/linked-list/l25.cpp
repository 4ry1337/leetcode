#include <bits/stdc++.h>

using namespace std;

/* link: https://leetcode.com/problems/reverse-nodes-in-k-group/
 *
 * solution 1
 * hint 1 fast and slow
 * hint 2 think in groups (group prev, group, group next)
 * hint 3 return prev of second group
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
  ListNode* reverseKGroup(ListNode* head, int k) {
    if (k == 1) return head;
    int cnt = k;
    ListNode* res = head;
    ListNode *g = head, *gp = g, *gn = head;
    while (true) {
      if (cnt == 0) {
        ListNode *prev = nullptr, *curr = g;
        while (curr != gn) {
          ListNode* next = curr->next;
          curr->next = prev;
          prev = curr;
          curr = next;
        }
        if (gp != g) {
          gp->next = prev;
          gp = g;
        } else {
          res = prev;
        }
        g->next = gn;
        g = curr;
        cnt = k;
      }
      if (!gn) break;
      gn = gn->next;
      cnt--;
    }
    return res;
  }
};
