#include <bits/stdc++.h>

using namespace std;

/* link: https://leetcode.com/problems/merge-k-sorted-lists/ */

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
 public:
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    ListNode* dummy = new ListNode(0);
    while (!lists.empty()) {
      for (auto& node : lists) {
        if (!node) continue;
      }
    }
    auto res = dummy->next;
    delete dummy;
    return res;
  }
};
