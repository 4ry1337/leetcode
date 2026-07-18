#include <bits/stdc++.h>

#include <queue>
#include <sstream>
#include <string>
#include <vector>

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

  /* TreeNode* deserialize(string data) {
    vector<string> val;
    stringstream ss;
    string item;
    while (getline(ss, item, ':')) {
      val.push_back(item);
    }
    int i = 0;
    stack<string> st({val});
  } */
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
