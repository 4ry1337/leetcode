#include "bits/stdc++.h"

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
public:
  bool isSubtree(TreeNode *root, TreeNode *sub) {
    if (!sub)
      return true;
    if (!root)
      return false;
    if (isSameTree(root, sub))
      return true;
    return isSubtree(root->left, sub) || isSubtree(root->right, sub);
  }

  bool isSameTree(TreeNode *p, TreeNode *q) {
    if (!p && !q)
      return true;
    if (p && q && p->val == q->val)
      return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    return false;
  }
};
