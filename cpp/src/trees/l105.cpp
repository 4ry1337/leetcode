#include <bits/stdc++.h>

#include <unordered_map>

using namespace std;

/* https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
 *
 * solution - hash map + depth first search
 *
 * 1. build a hash map mapping each value in inorder to its index.
 * 2. maintain a global preorder index starting at 0.
 * 3. define a recursive function dfs(l, r) for the inorder range [l, r].
 * 4. if l > r, return null (base case).
 * 5. get the root value from preorder at the current index, increment the
 * index.
 * 6. look up the root's position in the hash map (call it mid).
 * 7. recursively build left subtree with dfs(l, mid-1) and right subtree with
 * dfs(mid+1, r).
 * 8. return the root node.
 *
 */

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
  int pre_i = 0;
  unordered_map<int, int> indeces;

  TreeNode* dfs(vector<int>& p, int l, int r) {
    if (l > r) return nullptr;
    int val = p[pre_i++];
    TreeNode* root = new TreeNode(val);
    int mid = indeces[val];
    root->left = dfs(p, l, mid - 1);
    root->right = dfs(p, mid + 1, r);
    return root;
  }

 public:
  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    int len = preorder.size();
    for (int i{}; i < len; ++i) indeces[inorder[i]] = i;
    return dfs(preorder, 0, len - 1);
  }
};
