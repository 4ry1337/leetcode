#include <string>
#include <vector>

using namespace std;

/* link: https://leetcode.com/problems/longest-common-prefix/description/
 * BCR(O(N))
 *
 * solution
 * create prefix string
 * iterate through string one index at a time and compare and append to prefix.
 * */

class Solution {
 public:
  static auto longestCommonPrefix(vector<string>& strs) -> string {
    string res;
    for (int i{}; i < strs[0].size(); ++i) {
      char const& c = strs[0][i];
      for (auto& str : strs) {
        if (i >= str.size() || str[i] != c) {
          return res;
        }
      }
      res += c;
    }
    return res;
  }
};
