#include <bits/stdc++.h>

#include <deque>
#include <unordered_map>
#include <vector>

using namespace std;

/* link: https://leetcode.com/problems/lru-cache/
 *
 * Design a data structure that follows the constraints of a Least Recently Used
 * (LRU) cache.
 *
 * Implement the LRUCache class:
 *
 * - LRUCache(int capacity) Initialize the LRU cache with positive size
 * capacity.
 *
 * - int get(int key) Return the value of the key if the key exists, otherwise
 * return -1.
 *
 * - void put(int key, int value) Update the value of the key if the key exists.
 * Otherwise, add the key-value pair to the cache. If the number of keys exceeds
 * the capacity from this operation, evict the least recently used key.
 *
 * The functions get and put must each run in O(1) average time complexity.
 *
 *
 * solution 1 - double linked node
 * for key value retrival hashmap is fastest
 *
 * */

class LRUCache {
 private:
  struct Node {
    int key;
    int value;
    Node* prev;
    Node* next;
    Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
  };

 private:
  int m_capacity;
  unordered_map<int, Node*> m_cache;
  Node* m_left;
  Node* m_right;

  void remove(Node* node) {
    Node* prev = node->prev;
    Node* next = node->next;
    prev->next = next;
    next->prev = prev;
  }

  void insert(Node* node) {
    Node* prev = m_right->prev;
    prev->next = node;
    node->prev = prev;
    node->next = m_right;
    m_right->prev = node;
  }

 public:
  LRUCache(int capacity) : m_capacity(capacity) {
    m_cache.clear();
    m_left = new Node(0, 0);
    m_right = new Node(0, 0);
    m_left->next = m_right;
    m_right->prev = m_left;
  }

  int get(int key) {
    if (m_cache.find(key) != m_cache.end()) {
      Node* curr = m_cache[key];
      remove(curr);
      insert(curr);
      return curr->value;
    }
    return -1;
  }

  void put(int key, int value) {
    if (m_cache.find(key) != m_cache.end()) {
      remove(m_cache[key]);
    }
    Node* new_node = new Node(key, value);
    m_cache[key] = new_node;
    insert(new_node);
    if (m_cache.size() > m_capacity) {
      Node* lru = m_left->next;
      remove(lru);
      m_cache.erase(lru->key);
      delete lru;
    }
  }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
