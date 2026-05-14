#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:
  // Encodes a tree to a single string.
  string serialize(TreeNode *root) {
    if (!root)
      return "N";
    return to_string(root->val) + ":" + serialize(root->left) + ":" +
           serialize(root->right);
  }

  // Decodes your encoded data to tree.
  TreeNode *deserialize(string data) {
    stringstream ss(data);
    return dfs(ss);
  }

  TreeNode *dfs(stringstream &ss) {
    string curr;
    if (!getline(ss, curr, ':'))
      return nullptr;
    if (curr == "N")
      return nullptr;
    TreeNode *node = new TreeNode(stoi(curr));
    node->left = dfs(ss);
    node->right = dfs(ss);
    return node;
  }
};
