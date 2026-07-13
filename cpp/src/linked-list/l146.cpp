#include <bits/stdc++.h>

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
 * */

class LRUCache {
 private:
  struct Node {
    int m_key;
    int m_value;
    Node* p_next;
    Node(int key, int value) : m_key(key), m_value(value), p_next(nullptr) {}
    Node(int key, int value, Node* next)
        : m_key(key), m_value(value), p_next(next) {}
  };

 private:
  int m_capacity;

 public:
  LRUCache(int capacity) : m_capacity(capacity) {}

  int get(int key) {}

  void put(int key, int value) {}
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
