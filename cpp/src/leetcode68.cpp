#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  vector<string> fullJustify(vector<string> &words, int maxWidth) {
    vector<string> res;
    int l = 0, currRow = 0, currWord = 0;
    l += words[currWord].size();
    if (l < maxWidth) {
      res[0] += words[currWord] + ' ';
    } else if (l == maxWidth) {
    }
    return res;
  }
};

/*class Solution {*/
/*public:*/
/*  vector<string> fullJustify(vector<string> &words, int maxWidth) {*/
/*    vector<string> res;*/
/*    vector<string> vec;*/
/*    int spaces = maxWidth;*/
/**/
/*    for (int i = 0; i < words.size(); i++) {*/
/*      string w = words.at(i);*/
/*      if (spaces >= w.size() + vec.size()) {*/
/*        spaces -= w.size();*/
/*      } else {*/
/*        while (spaces > 0) {*/
/*          for (int j = 0; j < vec.size(); j++) {*/
/*            spaces--;*/
/*            if (spaces < 0) {*/
/*              break;*/
/*            }*/
/*            vec.at(j) += " ";*/
/*          }*/
/*        }*/
/*        string r = "";*/
/*        for (string v : vec) {*/
/*          r += v;*/
/*        }*/
/*        res.push_back(r);*/
/**/
/*        vec.clear();*/
/*        spaces = maxWidth - w.size();*/
/*      }*/
/*      vec.push_back(w);*/
/*    }*/
/*    for (int j = 0; j < vec.size() - 1; j++) {*/
/*      spaces--;*/
/*      if (spaces < 0) {*/
/*        break;*/
/*      }*/
/*      vec.at(j) += " ";*/
/*    }*/
/*    string r = "";*/
/*    for (string v : vec) {*/
/*      r += v;*/
/*    }*/
/*    vec.clear();*/
/*    res.push_back(r);*/
/*    for (string r : res) {*/
/*      cout << "\"" << r << "\"\t" << r.size() << "\t" << maxWidth - r.size()*/
/*           << endl;*/
/*    }*/
/*    return res;*/
/*  }*/
/*};*/

/*
if (spaces - w.size() < 0) {
  string r = "";
  for (string v : vec) {
    r += v;
  }
  res.push_back(r);
  spaces = maxWidth;
  vec.clear();
} else {
  spaces -= w.size() + 1;
  vec.push_back(w);
  vec.push_back(" ");
}
*/
/*int main() {*/
/*  Solution solution;*/
/*  vector<string> words = {*/
/*      "Science", "is", "what",       "we",   "understand", "well",*/
/*      "enough",  "to", "explain",    "to",   "a",          "computer.",*/
/*      "Art",     "is", "everything", "else", "we",         "do"};*/
/**/
/*  vector res = solution.fullJustify(words, 20);*/
/*  return 0;*/
/*}*/
