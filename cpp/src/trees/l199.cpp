#include <bits/stdc++.h>

using namespace std;

/*
 * link: https://leetcode.com/problems/binary-tree-right-side-view/
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
  vector<int> rightSideView(TreeNode* root) {
    vector<int> res;
    if (!root) return res;
    queue<TreeNode*> v({root});
    while (!v.empty()) {
      size_t size = v.size();
      for (size_t i{}; i++ < size;) {
        TreeNode* curr = v.front();
        v.pop();
        if (i == size) res.push_back(curr->val);
        if (curr->left) v.push(curr->left);
        if (curr->right) v.push(curr->right);
      }
    }
    return res;
  }
};
