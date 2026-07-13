#include <bits/stdc++.h>

using namespace std;

/*
 * link: https://leetcode.com/problems/copy-list-with-random-pointer/
 *
 * solution 1 - hash map pair value / vector pair
 * we store each val with pair next and random
 * recreate new nodes using it
 *
 * solution 2 - copy
 * we create copy of nodes next to each other so we get from
 * A -> B ->
 * A -> A' -> B -> B' ->
 * we substitude their random to original random->next
 * + - - - - -+
 * +          +
 * A -> A' -> B -> B' ->
 *      +     +
 *      + - - +
 * we remove interleaving returning first copy node
 * + - - - - -+
 * +          +
 * A -> A' -> B -> B' ->
 *      +          +
 *      + - - - - -+
 * */

class Node {
 public:
  int val;
  Node* next;
  Node* random;

  Node(int _val) {
    val = _val;
    next = NULL;
    random = NULL;
  }
};

class Solution {
 public:
  Node* copyRandomList(Node* head) {
    if (!head) return nullptr;
    Node* curr = head;
    while (curr) {
      Node* copy = new Node(curr->val);
      copy->next = curr->next;
      curr->next = copy;
      curr = copy->next;
    }
    curr = head;
    while (curr) {
      if (curr->random) curr->next->random = curr->random->next;
      curr = curr->next->next;
    }
    curr = head;
    Node* res = head->next;
    while (curr) {
      Node* copy = curr->next;
      curr->next = copy->next;
      curr = curr->next;
      copy->next = curr ? curr->next : nullptr;
    }
    return res;
  }
};
