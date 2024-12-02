#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> findSubstring(string s, vector<string> &words) {
    unordered_map<string, int> map;
    for (const std::string &word : words)
      map[word]++;

    vector<int> res;
    int wlen = words[0].size();

    for (int i = 0; i < wlen; ++i) {
      int size = 0;
      unordered_map<string, int> seen;

      for (int j = i; j + wlen <= s.size(); j += wlen) {
        string sub = s.substr(j, wlen);

        auto itr = map.find(sub);
        if (itr == map.end()) {
          seen.clear();
          size = 0;
          continue;
        }
        ++seen[sub];
        ++size;

        while (seen[sub] > itr->second) {
          string first = s.substr(j - (size - 1) * wlen, wlen);
          --seen[first];
          --size;
        }
        if (size == words.size())
          res.push_back(j - (size - 1) * wlen);
      }
    }
    return res;
  }
};
