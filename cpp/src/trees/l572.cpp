
using namespace std;

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
  auto isSubtree(TreeNode* root, TreeNode* subRoot) -> bool {
    if (subRoot == nullptr) {
      return true;
    }
    if (root == nullptr) {
      return false;
    }
    if (isSameTree(root, subRoot)) {
      return true;
    }
    return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
  }

  auto isSameTree(TreeNode* root, TreeNode* subRoot) -> bool {
    if ((root == nullptr) && (subRoot == nullptr)) {
      return true;
    }
    if ((root != nullptr) && (subRoot != nullptr) &&
        root->val == subRoot->val) {
      return isSameTree(root->left, subRoot->left) &&
             isSameTree(root->right, subRoot->right);
    }
    return false;
  }
};
