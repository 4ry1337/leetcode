#include <bits/stdc++.h>

#include <algorithm>

using namespace std;

/* https://leetcode.com/problems/binary-tree-maximum-path-sum/ */

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
 private:
  int dfs(TreeNode* root, int& res) {
    if (!root) return 0;
    int val = root->val;
    int left_max = max(dfs(root->left, res), 0);
    int right_max = max(dfs(root->right, res), 0);
    res = max(res, val + left_max + right_max);
    return val + max(right_max, left_max);
  }

 public:
  int maxPathSum(TreeNode* root) {
    int res = root->val;
    dfs(root, res);
    return res;
  }
};
