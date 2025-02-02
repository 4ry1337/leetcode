#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
  bool wordPattern(string pattern, string s) {
    unordered_map<char, string> m;
    unordered_map<string, char> p;
    int count = 0;
    for (int l = 0; l < s.size(); l++) {
      if (count >= pattern.size()) {
        return false;
      }
      int r = l;
      while (r < s.size() && s[r] != ' ') {
        r++;
      }
      string temp = s.substr(l, r - l);
      l = r;
      if (m.find(pattern[count]) == m.end() && p.find(temp) == p.end()) {
        m[pattern[count]] = temp;
        p[temp] = pattern[count];
      } else {
        if (m[pattern[count]] != temp || p[temp] != pattern[count]) {
          return false;
        }
      }
      count++;
    }
    if (count != pattern.size())
      return false;
    return true;
  }
};
