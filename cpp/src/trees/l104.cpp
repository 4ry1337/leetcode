#include <bits/stdc++.h>

using namespace std;

/* link: https://leetcode.com/problems/invert-binary-tree
 *
 * solution 1 - simple bfs
 * keep track of layers
 * */

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right)
      : val(x), left(left), right(right) {}
};

class Solution {
 public:
  int maxDepth(TreeNode* root) {
    int res = 0;
    deque<pair<TreeNode*, int>> v{{root, 0}};
    while (!v.empty()) {
      auto& [curr, level] = v.front();
      res = max(res, level);
      if (curr->left) v.push_back({curr->left, level + 1});
      if (curr->right) v.push_back({curr->right, level + 1});
      v.pop_front();
    }
    return res;
  }
};
