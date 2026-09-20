#include <algorithm>
#include <deque>
#include <utility>

using namespace std;

/* link: https://leetcode.com/problems/invert-binary-tree
 *
 * solution 1 - simple bfs
 * keep track of layers
 * */

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
  static auto maxDepth(TreeNode* root) -> int {
    int res = 0;
    deque<pair<TreeNode*, int>> v{{root, 0}};
    while (!v.empty()) {
      auto& [curr, level] = v.front();
      res = max(res, level);
      if (curr->left != nullptr) {
        v.emplace_back(curr->left, level + 1);
      }
      if (curr->right != nullptr) {
        v.emplace_back(curr->right, level + 1);
      }
      v.pop_front();
    }
    return res;
  }
};
