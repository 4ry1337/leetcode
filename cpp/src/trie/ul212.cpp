#include <bits/stdc++.h>

using namespace std;

/* https://leetcode.com/problems/word-search-ii */

class Solution {
 private:
  struct Node {
    unordered_map<char, Node*> mp;
  };
  Node* root;
  int rows, cols;

  bool search(string& word) {
    Node* curr = root;
    for (auto& c : word) {
      if (!curr->mp.contains(c)) return false;
      curr = curr->mp[c];
    }
    return true;
  }

  void dfs(Node* curr, vector<vector<char>>& board, int i, int j) {
    if (i < 0 || j < 0 || i >= rows || j >= cols || board[i][j] == '#') {
      return;
    }
    char c = board[i][j];
    if (!curr->mp.contains(c)) curr->mp[c] = new Node();
    curr = curr->mp[c];
    board[i][j] = '#';
    dfs(curr, board, i + 1, j);
    dfs(curr, board, i - 1, j);
    dfs(curr, board, i, j + 1);
    dfs(curr, board, i, j - 1);
    board[i][j] = c;
  }

 public:
  vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    root = new Node();
    rows = board.size();
    cols = board[0].size();

    vector<string> res;
    for (int i{}; i < rows; ++i) {
      for (int j{}; j < cols; ++j) {
        dfs(root, board, i, j);
      }
    }
    for (auto& word : words) {
      if (search(word)) {
        res.push_back(word);
      }
    }
    return res;
  }
};
