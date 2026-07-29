#include <bits/stdc++.h>

using namespace std;

/* link: https://leetcode.com/problems/encode-and-decode-strings/
 *
 * solution
 * encode length of word
 * and the word
 *
 * during parsing we need to understand when digit is not part of word so we
 * need special separator
 *
 * we add it between length and word
 *
 * resulting: number#word...
 *
 * and then parse it
 * */

class Solution {
 public:
  string encode(vector<string>& strs) {
    string res = "";
    for (auto& str : strs) {
      res += to_string(str.size());
      res += '#';
      res += str;
    }
    cout << res.size() << " " << res << "\n";
    return res;
  }

  vector<string> decode(string s) {
    vector<string> res;
    int i{};
    while (i < s.size()) {
      int size = 0;
      while (i < s.size() && s[i] != '#') {
        size *= 10;
        size += s[i] - '0';
        i++;
      }
      cout << i << " " << size << "\n";
      i++;
      res.push_back(s.substr(i, size));
      i += size;
    }
    return res;
  }
};
