#include <bits/stdc++.h>

using namespace std;

/* https://leetcode.com/problems/implement-trie-prefix-tree */

class Trie {
 private:
  struct TrieNode {
    unordered_map<char, TrieNode*> next;
    bool isEnd;
  };
  TrieNode* root;

 public:
  Trie() { root = new TrieNode(); }

  void insert(string word) {
    TrieNode* curr = root;
    for (auto& c : word) {
      if (!curr->next.contains(c)) {
        curr->next[c] = new TrieNode();
      }
      curr = curr->next[c];
    }
    curr->isEnd = true;
  }

  bool search(string word) {
    TrieNode* curr = root;
    for (auto& c : word) {
      if (!curr->next.contains(c)) return false;
      curr = curr->next[c];
    }
    return curr->isEnd;
  }

  bool startsWith(string prefix) {
    TrieNode* curr = root;
    for (auto& c : prefix) {
      if (!curr->next.contains(c)) {
        return false;
      }
      curr = curr->next[c];
    }
    return true;
  }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
