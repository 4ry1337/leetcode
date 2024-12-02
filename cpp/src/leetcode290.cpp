#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  bool wordPattern(string pattern, string s) {
    vector<string> words;
    string temp = "";
    for (int r = 0; r < s.size(); r++) {
      if (s.at(r) != ' ') {
        temp += s.at(r);
      } else {
        words.push_back(temp);
        temp = "";
      }
    }
    words.push_back(temp);

    if (pattern.size() != words.size()) {
      return false;
    }

    map<char, string> sh;
    map<string, char> th;

    for (int i = 0; i < pattern.length(); i++) {
      if (sh.count(pattern.at(i)) != 0 || th.count(words.at(i)) != 0) {
        if (sh[pattern.at(i)] != words.at(i) ||
            th[words.at(i)] != pattern.at(i)) {
          return false;
        }
      } else {
        sh[pattern.at(i)] = words.at(i);
        th[words.at(i)] = pattern.at(i);
      }
    }

    for (auto x : sh) {
      cout << x.first << " " << x.second << endl;
    }
    for (auto x : th) {
      cout << x.first << " " << x.second << endl;
    }

    return true;
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  cout << s.wordPattern("abba", "dog cat cat fish");
  return 0;
}
