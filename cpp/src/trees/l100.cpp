#include <bits/stdc++.h>

using namespace std;

/* link: https://leetcode.com/problems/same-tree */

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
  bool isSameTree(TreeNode* p, TreeNode* q) {
    return (p && q && p->val == q->val && isSameTree(p->left, q->left) &&
            isSameTree(p->right, q->right)) ||
           (!p && !q);
  }
};
