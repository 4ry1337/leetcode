#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
  int maxScore(string s) {
    int ones = 0, max_score = 0;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '1') {
        ones++;
      }
    }
    int zeros = 0;
    for (int i = 0; i < s.size() - 1; i++) {
      if (s[i] == '0') {
        zeros++;
      } else {
        ones--;
      }
      max_score = max(max_score, zeros + ones);
    }
    return max_score;
  }
};
