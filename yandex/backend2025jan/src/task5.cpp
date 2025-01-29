#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

struct TrieNode {
  unordered_map<char, TrieNode *> children;
  int word_count = 0;
  bool isEndOfWord = false;
};

void insert(TrieNode *root, const string &word) {
  TrieNode *node = root;
  for (char ch : word) {
    if (node->children.find(ch) == node->children.end()) {
      node->children[ch] = new TrieNode();
    }
    node->word_count++;
    node = node->children[ch];
  }
  node->isEndOfWord = true;
}

int countActions(TrieNode *root, const string &query) {
  TrieNode *node = root;
  int actions = node->word_count;
  for (char ch : query) {
    if (node->children.find(ch) == node->children.end()) {
      break;
    }
    actions++;
    node = node->children[ch];
  }
  if (node->isEndOfWord) {
    actions++;
  }
  return actions;
}

void printTrie(TrieNode *node, const string &prefix = "") {
  if (node->isEndOfWord) {
    cout << prefix << " (end)" << endl;
  }
  for (auto &[ch, child] : node->children) {
    printTrie(child, prefix + ch);
  }
}

int main() {
  int n, q;
  TrieNode *root = new TrieNode();

  cin >> n;
  for (int i = 0; i < n; ++i) {
    string word;
    cin >> word;
    insert(root, word);
  }

  cin >> q;
  for (int i = 0; i < q; ++i) {
    string query;
    cin >> query;
    int actions = countActions(root, query);
    cout << actions << "\n";
  }

  return 0;
}
