#include <algorithm>
#include <string>

using namespace std;

/*
// my hard coded answer
class Solution {
public:
  string reverseWords(string &s) {
    trim(s);
    int l = 0, r = 0;
    while (r < s.size()) {
      if (s[r] != ' ') {
        l = r;
        while (r < s.size() && s[r] != ' ') {
          r++;
        };
        reverse(s.begin() + l, s.begin() + r);
      }
      r++;
    }
    reverse(s.begin(), s.end());
    return s;
  }

  void trim(string &s) {
    int l = 0, r = 0;
    while (r < s.size()) {
      if (s[r] != ' ') {
        while (r < s.size() && s[r] != ' ') {
          s[l++] = s[r++];
        }
        s[l++] = ' ';
      }
      r++;
    }
    int length = s.size() - l + 1;
    for (int i = 0; i < length; i++) {
      s.pop_back();
    }
  }
};
*/

// cleaner by gpt
class Solution {
public:
  string reverseWords(string &s) {
    int n = s.size();
    int l = 0, r = 0;

    while (r < n) {
      while (r < n && s[r] == ' ') {
        r++;
      }
      if (r < n) {
        if (l != 0)
          s[l++] = ' ';

        int wordStart = l;

        while (r < n && s[r] != ' ') {
          s[l++] = s[r++];
        }
        reverse(s.begin() + wordStart, s.begin() + l);
      }
    }

    s.resize(l);
    reverse(s.begin(), s.end());

    return s;
  }
};
