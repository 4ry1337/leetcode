#include <string>
#include <vector>

using namespace std;

/*time complexity in worst case is O(strs.size() * strs[0].size() ^ 2)*/
class Solution {
public:
  string longestCommonPrefix(vector<string> &strs) {
    string res = strs[0];
    for (int i = 1; i < strs.size(); i++) {
      while (strs[i].find(res) != 0) {
        if (res.size() == 0) {
          return "";
        }
        res.pop_back();
      }
    }
    return res;
  }
};

/*
// same but longer
class Solution {
public:
  string longestCommonPrefix(vector<string> &strs) {
    int w = 0;
    for (int i = 1; i < strs.size(); i++) {
      if (strs[0].size() > strs[i].size()) {
        w = i;
      }
    }
    string res = strs[w];
    int prefix = res.size();
    for (int i = 0; i < strs.size(); i++) {
      if (i == w) {
        continue;
      }
      while (strs[i].substr(0, prefix) != res) {
        prefix--;
        if (prefix == 0) {
          return "";
        }
        res = res.substr(0, prefix);
      }
    }
    return res;
  }
};
*/
