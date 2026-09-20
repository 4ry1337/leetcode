#include <bits/stdc++.h>

using namespace std;

/* https://leetcode.com/problems/design-hashset/ */
/* solution 1 - separate chaining */
// solution 2 - BST

class MyHashSet {
 private:
  struct Node {
    int m_key;
    Node* m_left;
    Node* m_right;
    Node(int key) : m_key(m_key), m_left(nullptr), m_right(nullptr) {}
  };

  vector<Node*> buckets;

  int hash(int key) { return key % size; }

  const int m_size = 10000;
  int hash(int key) { return key % m_size; }

 public:
  MyHashSet() {}

  void add(int key) {
    int p_key = hash(key);
    Node* curr = m_root;
    while (curr != nullptr) {
      if (p_key == curr->m_key) {
        return;
      } else if (p_key > curr->m_key) {
        curr = curr->m_left;
      } else {
        curr = curr->m_right;
      }
    }
    curr = new Node(key);
  }

  void remove(int key) {}

  bool contains(int key) {}
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
