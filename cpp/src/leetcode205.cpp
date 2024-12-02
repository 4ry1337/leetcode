#include <map>
#include <string>

using namespace std;

class Solution {
public:
  bool isIsomorphic(string s, string t) {
    map<char, char> sh;
    map<char, char> th;

    for (int i = 0; i < s.length(); i++) {
      if (sh.count(s.at(i)) != 0 && th.count(t.at(i)) != 0) {
        if (sh[s.at(i)] != t.at(i) || th[t.at(i)] != s.at(i)) {
          return false;
        }
      } else {
        sh[s.at(i)] = t.at(i);
        th[t.at(i)] = s.at(i);
      }
    }

    return true;
  }
};
