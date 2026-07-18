#include <bits/stdc++.h>

using namespace std;

/* link: https://leetcode.com/problems/count-good-nodes-in-binary-tree/ */

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
  int goodNodes(TreeNode* root) {
    int res = 0;
    if (!root) return res;
    stack<pair<TreeNode*, int>> st({{root, root->val}});
    while (!st.empty()) {
      auto [curr, prev_max] = st.top();
      st.pop();
      if (prev_max <= curr->val) {
        prev_max = curr->val;
        res++;
      }
      if (curr->right) {
        st.push({
            curr->right,
            prev_max,
        });
      }
      if (curr->left) {
        st.push({
            curr->left,
            prev_max,
        });
      }
    }
    return res;
  }
};
