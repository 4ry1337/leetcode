

using namespace std;

/* https://leetcode.com/problems/binary-tree-maximum-path-sum/ */

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
 private:
  auto dfs(TreeNode* root, int& res) -> int {
    if (root == nullptr) {
      return 0;
    }
    int const val = root->val;
    int const left_max = max(dfs(root->left, res), 0);
    int const right_max = max(dfs(root->right, res), 0);
    res = max(res, val + left_max + right_max);
    return val + max(right_max, left_max);
  }

 public:
  auto maxPathSum(TreeNode* root) -> int {
    int res = root->val;
    dfs(root, res);
    return res;
  }
};
