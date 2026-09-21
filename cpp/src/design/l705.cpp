#include <bits/stdc++.h>

using namespace std;

/* https://leetcode.com/problems/design-hashset/ */
/* solution 1 - separate chaining */
// solution 2 - BST

class MyHashSet {
private:
  struct Node {
    int m_key;
    Node *m_left;
    Node *m_right;
    Node(int m_key) : m_key(m_key), m_left(nullptr), m_right(nullptr) {}
  };

  static const int m_size = 10000;
  array<Node *, m_size> m_buckets{};
  int hash(int key) { return key % m_size; }

public:
  MyHashSet() {}

  void add(int key) {
    if (contains(key))
      return;
    Node **slot = &m_buckets[hash(key)];
    while (*slot != nullptr) {
      Node *node = *slot;
      slot = key > node->m_key ? &node->m_right : &node->m_left;
    }
    *slot = new Node(key);
  }

  void remove(int key) {
    if (!contains(key))
      return;
    Node **slot = &m_buckets[hash(key)];
    while ((*slot)->m_key != key) {
      Node *node = *slot;
      slot = key > node->m_key ? &node->m_right : &node->m_left;
    }
    if (!(*slot)->m_left) {
      Node *temp = (*slot);
      *slot = (*slot)->m_right;
      delete temp;
      return;
    }
    if (!(*slot)->m_right) {
      Node *temp = *slot;
      *slot = (*slot)->m_left;
      delete temp;
      return;
    }
    Node **min_slot = &(*slot)->m_right;
    while ((*min_slot)->m_left)
      min_slot = &(*min_slot)->m_left;
    Node *min_value = *min_slot;
    (*slot)->m_key = min_value->m_key;
    *min_slot = min_value->m_right;
    delete min_value;
  }

  bool contains(int key) {
    Node *node = m_buckets[hash(key)];
    while (node) {
      if (node->m_key == key) {
        return true;
      } else if (node->m_key < key) {
        node = node->m_right;
      } else {
        node = node->m_left;
      }
    }
    return false;
  }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
