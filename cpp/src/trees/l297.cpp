#include <bits/stdc++.h>

using namespace std;

/* https://leetcode.com/problems/serialize-and-deserialize-binary-tree/ */

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
 public:
  string serialize(TreeNode* root) {
    if (!root) return "N";
    return to_string(root->val) + ":" + serialize(root->left) + ":" +
           serialize(root->right);
  }

  TreeNode* deserialize(string data) {
    vector<string> vals;
    stringstream ss(data);
    string item;
    while (getline(ss, item, ':')) vals.push_back(item);
    int i = 0;
    return dfs(vals, i);
  }

  TreeNode* dfs(vector<string>& vals, int& i) {
    if (i > vals.size()) return nullptr;
    if (vals[i] == "N") {
      i++;
      return nullptr;
    }
    int val = stoi(vals[i++]);
    TreeNode* node = new TreeNode(val);
    node->left = dfs(vals, i);
    node->right = dfs(vals, i);
    return node;
  }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
