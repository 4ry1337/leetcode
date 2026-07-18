#include <bits/stdc++.h>

using namespace std;

/* link: https://leetcode.com/problems/binary-tree-level-order-traversal */

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
  vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> res;
    if (!root) return res;
    queue<TreeNode*> v({root});
    while (!v.empty()) {
      vector<int> temp;
      size_t size = v.size();
      for (size_t i{}; i++ < size;) {
        TreeNode* curr = v.front();
        v.pop();
        temp.push_back(curr->val);
        if (curr->left) v.push(curr->left);
        if (curr->right) v.push(curr->right);
      }
      res.push_back(temp);
    }
    return res;
  }
};
