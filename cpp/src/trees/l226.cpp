#include <bits/stdc++.h>

using namespace std;

/* link: https://leetcode.com/problems/invert-binary-tree
 *
 * solution 1 - recursion
 * using call stack go through each node
 * check if left and right exists and tehn call fucntion again
 *
 * Time: O(n) space: O(N) using callstack
 *
 * solution 2 - simple bfs
 * same idea
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
  TreeNode* invertTree(TreeNode* root) {
    if (!root) return root;
    deque<TreeNode*> v{root};
    while (!v.empty()) {
      TreeNode* curr = v.front();
      swap(curr->left, curr->right);
      if (curr->left) v.push_back(curr->left);
      if (curr->right) v.push_back(curr->right);
      v.pop_front();
    }
    return root;
  }
};
