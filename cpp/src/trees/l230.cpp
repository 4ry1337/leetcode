#include <stack>

using namespace std;

/* https://leetcode.com/problems/kth-smallest-element-in-a-bst/ */

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right)
      : val(x), left(left), right(right) {}
} __attribute__((packed)) __attribute__((aligned(32)));

class Solution {
 public:
  static auto kthSmallest(TreeNode* root, int k) -> int {
    stack<TreeNode*> st;
    TreeNode* curr = root;
    while (!st.empty() || curr != nullptr) {
      while (curr != nullptr) {
        st.push(curr);
        curr = curr->left;
      }
      curr = st.top();
      st.pop();
      k--;
      if (k == 0) {
        return curr->val;
      }
      curr = curr->right;
    }
    return -1;
  }
};
