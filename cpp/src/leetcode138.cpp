#include <cstddef>

class Node {
public:
  int val;
  Node *next;
  Node *random;

  Node(int _val) {
    val = _val;
    next = NULL;
    random = NULL;
  }
};

class Solution {
public:
  Node *copyRandomList(Node *head) {
    if (!head) {
      return nullptr;
    }
    for (Node *cur = head; cur != nullptr;) {
      Node *temp = new Node(cur->val);
      temp->next = cur->next;
      cur->next = temp;
      cur = temp->next;
    }
    for (Node *cur = head; cur != nullptr; cur = cur->next->next) {
      if (cur->random != nullptr) {
        cur->next->random = cur->random->next;
      }
    }
    Node *res = head->next;
    for (Node *cur = head; cur != nullptr;) {
      Node *temp = cur->next;
      cur->next = temp->next;
      if (temp->next != nullptr) {
        temp->next = temp->next->next;
      }
      cur = cur->next;
    }
    return res;
  }
};
